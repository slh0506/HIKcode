#pragma once

#include <QDateTime>
#include "include/HCNetSDK.h"
#include <QMessageBox>
#include <QDateTime> 
#include <QWidget>
#include <QDebug>
#include <QList>
#include <QVector>
#include "MonitorDatabase.h"

#define sPicFileName  "..\\CHikVisionMonitor\\Resources\\test.bmp" //抓图存储路径
#define sRealFileName "..\\CHikVisionMonitor\\Resources\\test.mp4" //录像存储路径

class CDeviceInit:public QWidget
{
	Q_OBJECT
public:
	explicit CDeviceInit(QWidget* parent = 0);
	~CDeviceInit();
	//获取报警信息
	NET_DVR_ALARMER getAlarmInfo(const long &lUserID);
	NET_DVR_ALARMINFO getAlarmerChannel(const long &lUserID);
	//停止监听
	void stopListen(const long &lListenHandle);
	//开始监听
	long startListen(const long &lPort);
	//撤销布防上传通道
	void closeAlarm(const long &lHandle);
	//启用布防
	long setupAlarm(const long &lUserID);
	//回调函数
	bool msgCallback(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen);
	//预览信息准备
	long preview(long userID, const int &iChannel, const HWND &hWnd);
	//获取通道号信息
	QVector<int> DoGetDeviceResoure(const long &lUserID);
	//初始化SDK
	bool initSDK();
	//注销SDK
	bool uninitSDK();
	//登录SDK初始化
	long loginSDKInit(const CMonitorDatabase::struSqliteData &struSqlInfo);
	//登出SDK
	void logoutSDK(const long &userID);
	//开始预览
	long previewBegin(const long &userID, const int &iChannel,const HWND &hWnd1);
	//停止预览
	void previewStop(long lpreviewID);
	//停止回放
	void reviewStop(long lPlayHandle);
	//回放信息准备
	long reviewInit(long UserID, const HWND &hWnd, QDateTime beginDatetime, QDateTime endDatetime,const long &lChannel);
	long reviewFileInit(long UserID, const HWND &hWnd, NET_DVR_TIME struStartTime, NET_DVR_TIME struStopTime, const long &lChannel);
	//回放状态管理
	void reviewStatus(const long &lUserID, long m_lreviewID,long reviewStatus);
	DWORD getReviewTotalTime(const long &lUserID, long m_lreviewID, long reviewStatus);
	//回放进度管理
	void manageReviewPos(const long &lUserID, long m_lreviewID, DWORD dwreviewPos,long reviewStatus);
	//开启声音。
	void openSound(const long &lRealHandle);
	//关闭声音
	void closeSound();
	//调节音量
	void soundVolume(const long &lRealHandle, const int iVolume);
	//抓图
	bool capturePicture(const long &lRealHandle);
	//录像
	void saveRealData(const long &lRealHandle);
	//停止录像
	void stopSaveRealData(const long &lRealHandle);
	//根据文件类型、时间查找设备录像文件。
	long findFile(const long &lUserID, const QDateTime &beginDatetime, const QDateTime &endDatetime, const long &lFileChannel);
	//逐个获取查找到的文件信息
	NET_DVR_FINDDATA_V40 findNextFile(const long &lFindHandle);

public:
	QVector<int> g_vecChanNum;
	NET_DVR_DEVICEINFO_V30 DeviceInfotmp{ 0 };
	long returnRes;

private:
	//std::vector<NET_DVR_DEVICEINFO_V30> m_vecstruDeviceInfotmp;
	std::map<long, NET_DVR_DEVICEINFO_V30>m_mapStruDeviceInfotmp;
	std::map<long, NET_DVR_DEVICEINFO_V30>::iterator iter;
	/*MSGCallBack_V31 MessageCallBack;*/
	std::map<long, NET_DVR_ALARMER> m_mapAlarmDeviceInfo;
	std::map<long, NET_DVR_ALARMER>::iterator m_mapAlarmDeviceIter;
	std::map<long, NET_DVR_ALARMINFO> m_mapAlarmChannelInfo;
	std::map<long, NET_DVR_ALARMINFO>::iterator m_mapAlarmChannelIter;
};

