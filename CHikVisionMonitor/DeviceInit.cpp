#include "DeviceInit.h"
//10.18.67.10
CDeviceInit::CDeviceInit(QWidget* parent)
	: QWidget(parent)
{
}

void CDeviceInit::stopListen(const long &lListenHandle)
{
	if (!NET_DVR_StopListen_V30(lListenHandle))
	{
		qDebug() << "NET_DVR_StopListen_V30 error is" << NET_DVR_GetLastError() << endl;
		/*NET_DVR_Logout(lUserID);
		NET_DVR_Cleanup();*/
		return;
	}
	else
	{
		qDebug() << "close listen success" << endl;
		return;
	}
}

void CDeviceInit::closeAlarm(const long &lHandle) //撤回布防
{
	if (!NET_DVR_CloseAlarmChan_V30(lHandle))
	{
		qDebug() << "NET_DVR_CloseAlarmChan_V30 error is" << NET_DVR_GetLastError() << endl;
		/*NET_DVR_Logout(lUserID);
		NET_DVR_Cleanup();*/
		return;
	}
	else
	{
		qDebug() << "close Alarm success" << endl;
		return;
	}
}

long CDeviceInit::setupAlarm(const long &lUserID) //启用布防
{
	NET_DVR_SETUPALARM_PARAM struSetupParam = { 0 };
	struSetupParam.dwSize = sizeof(NET_DVR_SETUPALARM_PARAM);
	//上传报警信息类型: 0- 老报警信息(NET_DVR_PLATE_RESULT), 1- 新报警信息(NET_ITS_PLATE_RESULT)
	struSetupParam.byAlarmInfoType = 1;
	//布防等级:二级布防，针对智能交通设备
	struSetupParam.byLevel = 1;

	LONG lHandle = NET_DVR_SetupAlarmChan_V41(lUserID, &struSetupParam);
	if (lHandle < 0)
	{
		qDebug() << "NET_DVR_SetupAlarmChan_V41 error is" << NET_DVR_GetLastError() << endl;
		/*NET_DVR_Logout(lUserID);
		NET_DVR_Cleanup();	*/
	}
	else
	{
		qDebug() << "setup Alarm success" << endl;
	}
	return lHandle;
}

int iNum = 0;

void CALLBACK MessageCallBack(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void* pUser)
{
	((CDeviceInit*)pUser)->msgCallback(lCommand, pAlarmer, pAlarmInfo, dwBufLen);
	return;
}


bool CDeviceInit::msgCallback(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen)
{
	int i;
	NET_DVR_ALARMINFO struAlarmInfo;
	memcpy(&struAlarmInfo, pAlarmInfo, sizeof(NET_DVR_ALARMINFO));
	switch (lCommand)
	{
	case COMM_ALARM:
	{
		switch (struAlarmInfo.dwAlarmType)
		{
		case 3: //移动侦测报警
			for (i = 0; i < 16; i++)   //#define MAX_CHANNUM   16  //最大通道数
			{
				if (1 == struAlarmInfo.dwChannel[i])
				{
					qDebug() << "move alarm channel" << i + 1 << endl;
				}
			}
			break;
		default:
			break;
		}
	}
	break;
	default:
		break;

	}
	m_mapAlarmDeviceInfo.insert(std::make_pair(pAlarmer->lUserID,*pAlarmer));
	m_mapAlarmChannelInfo.insert(std::make_pair(pAlarmer->lUserID, struAlarmInfo));
	return TRUE;
}

NET_DVR_ALARMER CDeviceInit::getAlarmInfo(const long &lUserID)
{
	m_mapAlarmDeviceIter = m_mapAlarmDeviceInfo.find(lUserID);
	NET_DVR_ALARMER struAlarmerInfo = m_mapAlarmDeviceIter->second;
	return struAlarmerInfo;
}

NET_DVR_ALARMINFO CDeviceInit::getAlarmerChannel(const long &lUserID)
{
	m_mapAlarmChannelIter = m_mapAlarmChannelInfo.find(lUserID);
	NET_DVR_ALARMINFO struAlarmerChannelInfo = m_mapAlarmChannelIter->second;
	return struAlarmerChannelInfo;
}

long CDeviceInit::startListen(const long &lPort)//开始监听
{
	//NET_DVR_NETCFG_V30 struNetcfg = { 0 };
	//struNetcfg.dwSize = sizeof(NET_DVR_NETCFG_V30);
	//struNetcfg.struAlarmHostIpAddr.sIpV4 = strIP;
	long lListenHandle;
	lListenHandle = NET_DVR_StartListen_V30(NULL, lPort, MessageCallBack, NULL);
	if (lListenHandle < 0)
	{
		qDebug() << "NET_DVR_StartListen_V30 error is" << NET_DVR_GetLastError() << endl;
		/*NET_DVR_Logout(lUserID);
		NET_DVR_Cleanup();	*/
	}
	else
	{
		qDebug() << "start listen success" << endl;
	}
	return lListenHandle;
}

long CDeviceInit::preview(long userID, const int &iChannel, const HWND &hWnd)//获取previewID预览准备
{
	NET_DVR_PREVIEWINFO struPreviewInfo = { 0 };
	struPreviewInfo.lChannel = iChannel;//通道号，目前设备模拟通道号从1开始，数字通道的起始通道号通过NET_DVR_GetDVRConfig（配置命令NET_DVR_GET_IPPARACFG_V40）获取（dwStartDChan）。 
	struPreviewInfo.hPlayWnd = hWnd;//播放窗口的句柄，为NULL表示不解码显示。
	struPreviewInfo.dwStreamType = 0;//码流类型：0-主码流，1-子码流，2-三码流，3-虚拟码流，以此类推 
	struPreviewInfo.dwLinkMode = 0;//连接方式：0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4- RTP/RTSP，5- RTP/HTTP，6- HRUDP（可靠传输） ，7- RTSP/HTTPS，8- NPQ 
	struPreviewInfo.bBlocked = 1; //0 - 非阻塞取流，1 - 阻塞取流

	long IRealPreviewHandle = NET_DVR_RealPlay_V40(userID, &struPreviewInfo, NULL, NULL);

	if (IRealPreviewHandle < 0)
	{
		qDebug() << "NET_DVR_RealPlay_V40 error;error number " << NET_DVR_GetLastError();
		QMessageBox::warning(NULL, "error", "NET_DVR_RealPlay_V40 error;error number " + QString::number(NET_DVR_GetLastError()));
		NET_DVR_Logout(userID);
		userID = -1;
		return -1;
	}
	return IRealPreviewHandle;
}

long CDeviceInit::reviewInit(long userID,const HWND &hWnd,QDateTime beginDatetime,QDateTime endDatetime,const long &lChannel)
{
	NET_DVR_VOD_PARA_V50 struReviewInfo = { 0 };
	
	struReviewInfo.struBeginTime.wYear = beginDatetime.date().year();
	struReviewInfo.struBeginTime.byMonth = beginDatetime.date().month();
	struReviewInfo.struBeginTime.byDay = beginDatetime.date().day();
	struReviewInfo.struBeginTime.byHour = beginDatetime.time().hour();
	struReviewInfo.struBeginTime.byMinute = beginDatetime.time().minute();
	struReviewInfo.struBeginTime.bySecond = beginDatetime.time().second();
	struReviewInfo.struEndTime.wYear = endDatetime.date().year();
	struReviewInfo.struEndTime.byMonth = endDatetime.date().month();
	struReviewInfo.struEndTime.byDay = endDatetime.date().day();
	struReviewInfo.struEndTime.byHour = endDatetime.time().hour();
	struReviewInfo.struEndTime.byMinute = endDatetime.time().minute();
	struReviewInfo.struEndTime.bySecond = endDatetime.time().second();
	struReviewInfo.struIDInfo.dwChannel = lChannel;
	struReviewInfo.hWnd = hWnd;

	long lRealReviewHandle = NET_DVR_PlayBackByTime_V50(userID, &struReviewInfo);
	if (lRealReviewHandle < 0)
	{
		qDebug() << "NET_DVR_PlayBackByTime_V50 error;error number " << NET_DVR_GetLastError();
		QMessageBox::warning(NULL, "error", "NET_DVR_PlayBackByTime_V50 error;error number " + QString::number(NET_DVR_GetLastError()));
		NET_DVR_Logout(userID);
		userID = -1;
		return -1;
	}
	return lRealReviewHandle;
}

long CDeviceInit::reviewFileInit(long UserID, const HWND &hWnd, NET_DVR_TIME struStartTime, NET_DVR_TIME struStopTime, const long &lChannel)
{
	NET_DVR_VOD_PARA struReviewInfo = { 0 };

	struReviewInfo.struBeginTime = struStartTime;
	struReviewInfo.struEndTime = struStopTime;
	struReviewInfo.hWnd = hWnd;
	struReviewInfo.struIDInfo.dwChannel = lChannel;

	long lRealReviewHandle = NET_DVR_PlayBackByTime_V40(UserID,&struReviewInfo);
	if (lRealReviewHandle < 0)
	{
		qDebug() << "NET_DVR_PlayBackByTime_V50 error;error number " << NET_DVR_GetLastError();
		QMessageBox::warning(NULL, "error", "NET_DVR_PlayBackByTime_V50 error;error number " + QString::number(NET_DVR_GetLastError()));
		NET_DVR_Logout(UserID);
		UserID = -1;
		return -1;
	}
	return lRealReviewHandle;
}

bool CDeviceInit::initSDK()
{
	bool bok = NET_DVR_Init();
	if (!bok)
	{
		qDebug() << "NET_DVR_Init error;error number is" << NET_DVR_GetLastError();
		QMessageBox::warning(NULL, "error", "NET_DVR_Init error;error number is " + QString::number(NET_DVR_GetLastError()));
		return bok;
	}
	NET_DVR_SetConnectTime(2000, 1);
	NET_DVR_SetReconnect(10000, true); 
	//设置报警回调函数
	NET_DVR_SetDVRMessageCallBack_V30(MessageCallBack, NULL);

	return bok;
}

bool CDeviceInit::uninitSDK()
{
	bool bok = NET_DVR_Cleanup();
	if (!bok)
	{
		qDebug() << "NET_DVR_Cleanup error;error number is" << NET_DVR_GetLastError();
		QMessageBox::warning(NULL, "error", "NET_DVR_Cleanup error;error number " + QString::number(NET_DVR_GetLastError()));
		return bok;
	}
	return bok;
}

long CDeviceInit::loginSDKInit(const CMonitorDatabase::struSqliteData &struSqlInfo)
{
	long userID = NET_DVR_Login_V30((char*)struSqlInfo.IP.toStdString().c_str(), struSqlInfo.Port, (char*)struSqlInfo.Username.toStdString().c_str(), (char*)struSqlInfo.Password.toStdString().c_str(), &DeviceInfotmp);
	if (userID < 0)
	{
		qDebug() << "NET_DVR_Login_V30 error;" << "error number is" << NET_DVR_GetLastError();
		/*QMessageBox::warning(NULL, "error", "NET_DVR_Login_V30 error;error number " + QString::number(NET_DVR_GetLastError()));*/
	}
	qDebug() << "Login Success,userID:" << userID << endl;
	qDebug() << "The max number of analog channels: " << DeviceInfotmp.byChanNum;
	qDebug() << "The max number of IP channels: " << DeviceInfotmp.byIPChanNum + DeviceInfotmp.byHighDChanNum * 256;
	m_mapStruDeviceInfotmp.insert(std::make_pair(userID, DeviceInfotmp));
	//m_vecstruDeviceInfotmp.emplace_back(DeviceInfotmp);
	/*DoGetDeviceResoure(userID);*/
	return userID;
}

void CDeviceInit::logoutSDK(const long &userID)
{
	if ( -1 != userID)
	{
		if (NET_DVR_Logout(userID) == false)
		{
			qDebug() << "NET_DVR_Logout error;" << "error number is " << NET_DVR_GetLastError();
			/*QMessageBox::warning(NULL, "error", "NET_DVR_Logout error;error number " + QString::number(NET_DVR_GetLastError()));*/
			return;
		}
		//m_listlUserID.replace(iNum,-1);
		qDebug() << "Logout Success!" << endl;
	}
}

long CDeviceInit::previewBegin(const long &userID,const int &iChannel,const HWND &hWnd1)//开始预览
{
	if (-1 == userID)
	{
		qDebug() << "Need Login!" << endl;
		QMessageBox::warning(NULL, "error", "Need Login!");
	}
	NET_DVR_PREVIEWINFO struPreviewInfo;
	long m_lpreviewID = preview(userID, iChannel, hWnd1);
	
	if (-1 == m_lpreviewID)
	{
		qDebug() << "Need Login!" << endl;
	}
	qDebug() << "Preview Success!" << userID << endl;
	return m_lpreviewID;
}

void CDeviceInit::reviewStatus(const long &lUserID, long m_lreviewID, long reviewStatus)//开始回放
{
	if (-1 == lUserID)
	{
		qDebug() << "Need Login!" << endl;
		QMessageBox::warning(NULL, "error", "Need Login!");
		return;
	}
	if (NET_DVR_PlayBackControl(m_lreviewID, reviewStatus , 0, NULL) == false)
	{
		qDebug() << "NET_DVR_PlayBackControl_V40 error;" << "error number is " << NET_DVR_GetLastError();
		QMessageBox::warning(NULL, "error", "NET_DVR_PlayBackControl_V40 error;error number " + QString::number(NET_DVR_GetLastError()));
		return;
	}
	qDebug() << "Review Success!" << endl;
}

DWORD CDeviceInit::getReviewTotalTime(const long &lUserID, long m_lreviewID, long reviewStatus)
{
	DWORD lfileTotalTime;
	if (-1 == lUserID)
	{
		qDebug() << "Need Login!" << endl;
		QMessageBox::warning(NULL, "error", "Need Login!");
	}
	if (NET_DVR_PlayBackControl(m_lreviewID, reviewStatus, 0, &lfileTotalTime) == false)
	{
		qDebug() << "NET_DVR_PlayBackControl_V40 error;" << "error number is " << NET_DVR_GetLastError();
		/*QMessageBox::warning(NULL, "error", "NET_DVR_PlayBackControl_V40 error;error number " + QString::number(NET_DVR_GetLastError()));*/
	}
	else
	{
		qDebug() << "GetReviewTime Success!" <<lfileTotalTime<< endl;
	}
	return lfileTotalTime;
}

void CDeviceInit::manageReviewPos(const long &lUserID, long m_lreviewID, DWORD dwreviewPos, long reviewStatus)
{
	if (-1 == lUserID)
	{
		qDebug() << "Need Login!" << endl;
		QMessageBox::warning(NULL, "error", "Need Login!");
		return;
	}
	if (NET_DVR_PlayBackControl(m_lreviewID, reviewStatus, dwreviewPos, NULL) == false)
	{
		qDebug() << "NET_DVR_PlayBackControl_V40 error;" << "error number is " << NET_DVR_GetLastError();
		QMessageBox::warning(NULL, "error", "NET_DVR_PlayBackControl_V40 error;error number " + QString::number(NET_DVR_GetLastError()));
		return;
	}
	qDebug() << "ManageReviewTime Success!" << endl;
}

void CDeviceInit::previewStop(long lpreviewID)//停止预览
{
	if (lpreviewID != -1)
	{
		if (NET_DVR_StopRealPlay(lpreviewID) == false)
		{
			qDebug() << "NET_DVR_StopRealPlay error;" << "error number is " << NET_DVR_GetLastError();
			QMessageBox::warning(NULL, "error", "NET_DVR_StopRealPlay error;error number " + QString::number(NET_DVR_GetLastError()));
			return;
		}
		lpreviewID = -1;
		qDebug() << "Stop Preview Success!" << endl;
	}
}

void CDeviceInit::reviewStop(long lPlayHandle)
{
	if (lPlayHandle != -1)
	{
		if (NET_DVR_StopPlayBack(lPlayHandle) == false)
		{
			qDebug() << "NET_DVR_PlayBack error;" << "error number is " << NET_DVR_GetLastError();
			QMessageBox::warning(NULL, "error", "NET_DVR_PlayBack error;error number " + QString::number(NET_DVR_GetLastError()));
			return;
		}
		lPlayHandle = -1;
		qDebug() << "Stop Review Success!" << endl;
	}
}

QVector<int> CDeviceInit::DoGetDeviceResoure(const long &lUserID)//通道信息
{
	BYTE byIPID, byIPIDHigh;
	int iDevInfoIndex, iGroupNO = 0, iIPCh;
	NET_DVR_IPPARACFG_V40 IpAccessCfg;
	memset(&IpAccessCfg, 0, sizeof(IpAccessCfg));
	DWORD dwReturned;
	g_vecChanNum.clear();
	iter = m_mapStruDeviceInfotmp.find(lUserID);
 	if (0 != iter->second.byStartDChan)
	{		
		if (!NET_DVR_GetDVRConfig(lUserID, NET_DVR_GET_IPPARACFG_V40, 0, &IpAccessCfg, sizeof(NET_DVR_IPPARACFG_V40), &dwReturned))
		{
			qDebug() << "error code is" << NET_DVR_GetLastError() << endl;			
			NET_DVR_Cleanup();
			/*for (int i = 0; i <= DeviceInfotmp.byChanNum; ++i)
			{
				g_vecChanNum.push_back(i + 1);
			}*/
		}
		else
		{
			for (int i = 0; i < IpAccessCfg.dwDChanNum; ++i)
			{
				if (IpAccessCfg.struStreamMode[i].uGetStream.struChanInfo.byEnable)
				{
					byIPID = IpAccessCfg.struStreamMode[i].uGetStream.struChanInfo.byIPID;
					byIPIDHigh = IpAccessCfg.struStreamMode[i].uGetStream.struChanInfo.byIPIDHigh;
					iDevInfoIndex = byIPIDHigh * 256 + byIPID - 1 - iGroupNO * 64;
					qDebug() << "IPV4 " << IpAccessCfg.struIPDevInfo[iDevInfoIndex].struIP.sIpV4 << endl;
					qDebug() << "IP channel no is online   " << i << endl;
					qDebug() << IpAccessCfg.dwDChanNum << endl;
					qDebug() << IpAccessCfg.dwStartDChan << endl;
					qDebug() << IpAccessCfg.dwAChanNum << endl;
					g_vecChanNum.push_back(IpAccessCfg.dwStartDChan + i);
				}
			}

			for (int i = 0; i < IpAccessCfg.dwAChanNum; ++i)
			{
				if (1 == IpAccessCfg.byAnalogChanEnable[i])
				{
					g_vecChanNum.push_back(1 + i);
				}
			}
			qSort(g_vecChanNum.begin(), g_vecChanNum.end());
		}
	}
	else
	{
		for (int j = 1; j <= iter->second.byChanNum; ++j)
		{
			g_vecChanNum.push_back(j);
		}
	}
	return g_vecChanNum;
}

void CDeviceInit::openSound(const long &lRealHandle)
{
	NET_DVR_OpenSound(lRealHandle);
}

void CDeviceInit::closeSound()
{
	NET_DVR_CloseSound();
}

void CDeviceInit::soundVolume(const long &lRealHandle, const int iVolume)
{
	if (!NET_DVR_Volume(lRealHandle, iVolume))
	{
		qDebug()<<"manage failed "<<"error is "<< NET_DVR_GetLastError() << endl;
	}
	else
	{
		qDebug() << "manage volume success" << endl;
	}
}

bool CDeviceInit::capturePicture(const long &lRealHandle)
{
	NET_DVR_SetCapturePictureMode(0);//bmp
	if (!NET_DVR_CapturePicture(lRealHandle, sPicFileName))
	{
		qDebug() << "capture failed  " << "error number is " << NET_DVR_GetLastError() << endl;
		return false;
	}
	else
	{
		qDebug() << "capture success" << endl;
		return true;
	}
	return true;
}

void CDeviceInit::saveRealData(const long &lRealHandle)
{
	if (!NET_DVR_SaveRealData(lRealHandle, sRealFileName))
	{
		qDebug()<<"saveRealData error  "<< NET_DVR_GetLastError() << endl;
	}
	else
	{
		qDebug() << "saveRealData success" << endl;
	}
}

void CDeviceInit::stopSaveRealData(const long &lRealHandle)
{
	NET_DVR_StopSaveRealData(lRealHandle);
}

long CDeviceInit::findFile(const long &lUserID, const QDateTime &beginDatetime, const QDateTime &endDatetime, const long &lFileChannel)
{
	NET_DVR_FILECOND_V40 struFileInfotmp;
	struFileInfotmp = { 0 };
	struFileInfotmp.lChannel = lFileChannel;
	struFileInfotmp.struStartTime.dwYear = beginDatetime.date().year();
	struFileInfotmp.struStartTime.dwMonth = beginDatetime.date().month();
	struFileInfotmp.struStartTime.dwDay = beginDatetime.date().day();
	struFileInfotmp.struStartTime.dwHour = beginDatetime.time().hour();
	struFileInfotmp.struStartTime.dwMinute = beginDatetime.time().minute();
	struFileInfotmp.struStartTime.dwSecond = beginDatetime.time().second();
	struFileInfotmp.struStopTime.dwYear = endDatetime.date().year();
	struFileInfotmp.struStopTime.dwMonth = endDatetime.date().month();
	struFileInfotmp.struStopTime.dwDay = endDatetime.date().day();
	struFileInfotmp.struStopTime.dwHour = endDatetime.time().hour();
	struFileInfotmp.struStopTime.dwMinute = endDatetime.time().minute();
	struFileInfotmp.struStopTime.dwSecond = endDatetime.time().second();
	
	long lFindHandle = NET_DVR_FindFile_V40(lUserID, &struFileInfotmp);
	if (-1 == lFindHandle)
	{
		qDebug() << "find error " << NET_DVR_GetLastError() << endl;
	}	
	return lFindHandle;
}

NET_DVR_FINDDATA_V40 CDeviceInit::findNextFile(const long &lFindHandle)
{
	NET_DVR_FINDDATA_V40 struFindDataInfotmp;
	memset(&struFindDataInfotmp, 0, sizeof(struFindDataInfotmp));
	returnRes = NET_DVR_FindNextFile_V40(lFindHandle, &struFindDataInfotmp);
	if (-1 == returnRes)
	{
		qDebug() << "find file error " << NET_DVR_GetLastError() << endl;
	}
	else
	{
		qDebug() << "return num is " << returnRes << endl;
	}
	return struFindDataInfotmp;
}

CDeviceInit::~CDeviceInit()
{
}
