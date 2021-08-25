#pragma once

#include <QWidget>
#include "CDeviceManagement.h"
#include "MonitorDatabase.h"
#include "DeviceInit.h"
#include "ui_CAlarmDevice.h"

class CAlarmDevice : public QWidget
{
	Q_OBJECT

public:
	explicit CAlarmDevice(QWidget *parent = Q_NULLPTR);
	~CAlarmDevice();

private:
	Ui::CAlarmDevice ui;
	QStandardItemModel *m_pAlarmItemModel{ nullptr };//报警设备
	QStandardItemModel *m_pAlarmDeviceInfoModel{ nullptr };//报警设备信息
	CMonitorDatabase *m_pcMonitorDatabase{ nullptr };
	CDeviceInit *m_pcDeviceInit{ nullptr };
	CDeviceManagement *m_pcDeviceManagement{ nullptr };
	CMonitorDatabase::struSqliteData struAlarmDeviceInfo;
	std::map<long, long>m_maplSetupAlarmHandle;
	std::map<long, long>::iterator m_mapSetupAlarmIter;
	std::map<long, int>m_maplAlarmFlag;
	std::map<long, int>::iterator m_mapAlarmFlagIter;
	long m_lstartListenHandle;
	int m_iAlarmFlag{ 0 };
	int m_ilistenFlag{ 0 };
	typedef enum AlarmColumData//枚举item表头信息
	{
		IP = 0,
		NetworkStatus = 1,
		AlarmState = 2
	}AlarmColumData;

	typedef enum AlarmerDeviceInfo//枚举item表头信息
	{
		AlarmerIP = 0,
		AlarmerChannel = 1,
		AlarmerType = 2
	}AlarmerDeviceInfo;

private:
	void setAlarmItem();
	void slotsInit();
	void setAlarmerInfo(const long &lUserID);
private slots:
	void onClickedSetupAlarmChan();
	void onClickedCloseAlarmChan();
	void onClickedStartListen();
	void onClickedStopListen();
	void onDoubleClickedAlarmDeviceInfo(const QModelIndex &index = QModelIndex());
	void onClickedExit();
};
