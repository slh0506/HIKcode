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

#define sPicFileName  "..\\CHikVisionMonitor\\Resources\\test.bmp" //ץͼ�洢·��
#define sRealFileName "..\\CHikVisionMonitor\\Resources\\test.mp4" //¼��洢·��

class CDeviceInit:public QWidget
{
	Q_OBJECT
public:
	explicit CDeviceInit(QWidget* parent = 0);
	~CDeviceInit();
	//��ȡ������Ϣ
	NET_DVR_ALARMER getAlarmInfo(const long &lUserID);
	NET_DVR_ALARMINFO getAlarmerChannel(const long &lUserID);
	//ֹͣ����
	void stopListen(const long &lListenHandle);
	//��ʼ����
	long startListen(const long &lPort);
	//���������ϴ�ͨ��
	void closeAlarm(const long &lHandle);
	//���ò���
	long setupAlarm(const long &lUserID);
	//�ص�����
	bool msgCallback(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen);
	//Ԥ����Ϣ׼��
	long preview(long userID, const int &iChannel, const HWND &hWnd);
	//��ȡͨ������Ϣ
	QVector<int> DoGetDeviceResoure(const long &lUserID);
	//��ʼ��SDK
	bool initSDK();
	//ע��SDK
	bool uninitSDK();
	//��¼SDK��ʼ��
	long loginSDKInit(const CMonitorDatabase::struSqliteData &struSqlInfo);
	//�ǳ�SDK
	void logoutSDK(const long &userID);
	//��ʼԤ��
	long previewBegin(const long &userID, const int &iChannel,const HWND &hWnd1);
	//ֹͣԤ��
	void previewStop(long lpreviewID);
	//ֹͣ�ط�
	void reviewStop(long lPlayHandle);
	//�ط���Ϣ׼��
	long reviewInit(long UserID, const HWND &hWnd, QDateTime beginDatetime, QDateTime endDatetime,const long &lChannel);
	long reviewFileInit(long UserID, const HWND &hWnd, NET_DVR_TIME struStartTime, NET_DVR_TIME struStopTime, const long &lChannel);
	//�ط�״̬����
	void reviewStatus(const long &lUserID, long m_lreviewID,long reviewStatus);
	DWORD getReviewTotalTime(const long &lUserID, long m_lreviewID, long reviewStatus);
	//�طŽ��ȹ���
	void manageReviewPos(const long &lUserID, long m_lreviewID, DWORD dwreviewPos,long reviewStatus);
	//����������
	void openSound(const long &lRealHandle);
	//�ر�����
	void closeSound();
	//��������
	void soundVolume(const long &lRealHandle, const int iVolume);
	//ץͼ
	bool capturePicture(const long &lRealHandle);
	//¼��
	void saveRealData(const long &lRealHandle);
	//ֹͣ¼��
	void stopSaveRealData(const long &lRealHandle);
	//�����ļ����͡�ʱ������豸¼���ļ���
	long findFile(const long &lUserID, const QDateTime &beginDatetime, const QDateTime &endDatetime, const long &lFileChannel);
	//�����ȡ���ҵ����ļ���Ϣ
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

