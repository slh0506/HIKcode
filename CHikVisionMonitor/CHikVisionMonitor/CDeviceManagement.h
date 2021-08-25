#pragma once

#include <QWidget>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QStringList>
#include <QVariant>
#include <QVector>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QAbstractItemView>
#include "qinputdialog.h"
#include "MonitorDatabase.h"
#include "DeviceInit.h"
#include "ui_CDeviceManagement.h"

class CDeviceManagement : public QWidget
{
	Q_OBJECT
public:
	explicit CDeviceManagement(QWidget *parent = Q_NULLPTR);
	~CDeviceManagement();
	//设置item信息并放置
	void setItemValues(const int &iRowcount);
	void setPointer(CDeviceInit *pcDeviceInit) { m_pcDeviceInit = pcDeviceInit; };
	void login();

public:
	QStandardItemModel *m_pItemModel{ nullptr };
	int iRowcount;
	QVector <long>m_veclUserID;
	
signals:
	//发送信号函数
	void addSignal();
	void deleteSignal(const int &iNum);
	void modifySignal();
	void logoutSignal();

protected:
	virtual bool event(QEvent *event);

private:
	Ui::CDeviceManagement ui;
	CMonitorDatabase *m_pcDatabase{ nullptr };
	CDeviceInit *m_pcDeviceInit{ nullptr };	
	int m_iPort;
	QString m_strUsername;
	QString m_strPassword;
	QString m_strIP;
	QString m_strPort;
	CMonitorDatabase::struSqliteData struDeviceInfo;
	typedef enum ColumData//枚举item表头信息
	{
		IP = 0,
		Port = 1,
		DeviceType = 2,
		Status = 3,
		UserID = 4
	}ColumData;
private slots:
	//点击打开修改页面
	void onClickedModify(const QModelIndex &index);
	//点击删除设备信息
	void onClickedDelete();
	//点击打开添加设备信息页面
	void onClickedAdd();
	//点击退出添加设备信息页面
	void onClickedExit();
	//点击添加设备信息并登陆
	void onClickedLogin();
	//点击登出设备信息
	void onClickedLogout();
	//点击取消修改设备信息
	void onClickedModifyCancel();
	//点击退出修改设备信息页面
	void onClickedModifyExit();
	//点击确认提交修改设备信息
	void onClickedModifyCheck();
	//槽函数
	void slotInit();
};
