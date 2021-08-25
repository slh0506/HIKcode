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
	//����item��Ϣ������
	void setItemValues(const int &iRowcount);
	void setPointer(CDeviceInit *pcDeviceInit) { m_pcDeviceInit = pcDeviceInit; };
	void login();

public:
	QStandardItemModel *m_pItemModel{ nullptr };
	int iRowcount;
	QVector <long>m_veclUserID;
	
signals:
	//�����źź���
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
	typedef enum ColumData//ö��item��ͷ��Ϣ
	{
		IP = 0,
		Port = 1,
		DeviceType = 2,
		Status = 3,
		UserID = 4
	}ColumData;
private slots:
	//������޸�ҳ��
	void onClickedModify(const QModelIndex &index);
	//���ɾ���豸��Ϣ
	void onClickedDelete();
	//���������豸��Ϣҳ��
	void onClickedAdd();
	//����˳�����豸��Ϣҳ��
	void onClickedExit();
	//�������豸��Ϣ����½
	void onClickedLogin();
	//����ǳ��豸��Ϣ
	void onClickedLogout();
	//���ȡ���޸��豸��Ϣ
	void onClickedModifyCancel();
	//����˳��޸��豸��Ϣҳ��
	void onClickedModifyExit();
	//���ȷ���ύ�޸��豸��Ϣ
	void onClickedModifyCheck();
	//�ۺ���
	void slotInit();
};
