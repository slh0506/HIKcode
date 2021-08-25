#include "AlarmDevice.h"

CAlarmDevice::CAlarmDevice(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.alarmerInfoWidget->hide();

	if (nullptr == m_pcMonitorDatabase)
	{
		m_pcMonitorDatabase = new CMonitorDatabase;
		m_pAlarmItemModel = new QStandardItemModel(m_pcMonitorDatabase->selectSize(), 3, ui.alarmTableView);
		m_pAlarmDeviceInfoModel = new QStandardItemModel(1, 3, ui.alarmerInfoTableView);
	}
	if (nullptr == m_pcDeviceManagement)
	{
		m_pcDeviceManagement = new CDeviceManagement;
	}
	if (nullptr == m_pcDeviceInit)
	{
		m_pcDeviceInit = new CDeviceInit;
	}
	
	if (nullptr != m_pAlarmDeviceInfoModel)
	{
		m_pAlarmDeviceInfoModel->setHeaderData(0, Qt::Horizontal, QObject::tr("AlarmIP"));
		m_pAlarmDeviceInfoModel->setHeaderData(1, Qt::Horizontal, QObject::tr("AlarmChannel"));
		m_pAlarmDeviceInfoModel->setHeaderData(2, Qt::Horizontal, QObject::tr("AlarmType"));
		ui.alarmerInfoTableView->setModel(m_pAlarmDeviceInfoModel);
	}

	if (nullptr != m_pAlarmItemModel)
	{
		m_pAlarmItemModel->setHeaderData(0, Qt::Horizontal, QObject::tr("IP"));
		m_pAlarmItemModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Network State"));
		m_pAlarmItemModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Alarm State"));
		ui.alarmTableView->setModel(m_pAlarmItemModel);
	}
	
	setAlarmItem();

	ui.alarmTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
	ui.alarmTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//横向填满表格
	ui.alarmTableView->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中

	ui.alarmerInfoTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
	ui.alarmerInfoTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//横向填满表格
	ui.alarmerInfoTableView->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中

	slotsInit();
}

void CAlarmDevice::setAlarmerInfo(const long &lUserID)
{
	if (nullptr != m_pAlarmDeviceInfoModel)
	{
		if (nullptr != m_pcDeviceInit)
		{
			QString strAlarmChannel;
			QStandardItem *pAlarmerItem1 = new QStandardItem(QString(m_pcDeviceInit->getAlarmInfo(lUserID).sDeviceIP));
			if (nullptr != pAlarmerItem1)
			{
				m_pAlarmDeviceInfoModel->setItem(0, AlarmerIP, pAlarmerItem1);
			}

			for (int i = 0;i<sizeof(m_pcDeviceInit->getAlarmerChannel(lUserID).dwChannel);++i)
			{
				if (1 == m_pcDeviceInit->getAlarmerChannel(lUserID).dwChannel[i])
				{
					QString strAlarm = QString("%1, ").arg(i + 1);
					strAlarmChannel += strAlarm;
				}
			}
			QStandardItem *pAlarmerItem2 = new QStandardItem(QString(strAlarmChannel));
			if (nullptr != pAlarmerItem2)
			{
				m_pAlarmDeviceInfoModel->setItem(0, AlarmerChannel, pAlarmerItem2);
			}

			DWORD dw = m_pcDeviceInit->getAlarmerChannel(lUserID).dwAlarmType;
			std::string str = std::to_string(long long(dw));
			QString qstrAlarmType = QString::fromStdString(str);
			QStandardItem *pAlarmerItem3 = new QStandardItem(qstrAlarmType);
			if (nullptr != pAlarmerItem3)
			{
				m_pAlarmDeviceInfoModel->setItem(0, AlarmerType, pAlarmerItem3);
			}
			ui.alarmerInfoTableView->setModel(m_pAlarmDeviceInfoModel);
		}
	}
}

void CAlarmDevice::onDoubleClickedAlarmDeviceInfo(const QModelIndex &index)
{
	if (nullptr != m_pcDeviceManagement)
	{
		setAlarmerInfo(m_pcDeviceManagement->m_veclUserID.value(index.row()));
		ui.alarmerInfoWidget->show();
	}
}

void CAlarmDevice::setAlarmItem()//留有bug***********
{
	if (nullptr != m_pAlarmItemModel)
	{
		for (int row = 0; row < m_pcMonitorDatabase->selectSize(); ++row)
		{
			if (nullptr != m_pcMonitorDatabase)
			{
				struAlarmDeviceInfo = m_pcMonitorDatabase->selectRow(m_pcMonitorDatabase->selectID().value(row).toInt());
			}

			QStandardItem *pItem1 = new QStandardItem(QString(struAlarmDeviceInfo.IP).arg(row).arg(IP));
			if (nullptr != pItem1)
			{
				m_pAlarmItemModel->setItem(row, IP, pItem1);
			}			

			if (nullptr != m_pcDeviceManagement)
			{
				if (m_pcDeviceManagement->m_veclUserID.value(row) < 0)
				{
					QStandardItem *pItem2 = new QStandardItem(QString("Offline").arg(row).arg(NetworkStatus));
					if (nullptr != pItem2)
					{
						m_pAlarmItemModel->setItem(row, NetworkStatus, pItem2);
					}
				}
				else
				{
					QStandardItem *pItem2 = new QStandardItem(QString("Online").arg(row).arg(NetworkStatus));
					if (nullptr != pItem2)
					{
						m_pAlarmItemModel->setItem(row, NetworkStatus, pItem2);
					}				
				}
			}

			if (nullptr != m_pcDeviceManagement)
			{
				if (1 == m_iAlarmFlag)
				{
					m_mapAlarmFlagIter = m_maplAlarmFlag.find(m_pcDeviceManagement->m_veclUserID.value(row));
					if (1 != m_mapAlarmFlagIter->second && 1 != m_ilistenFlag)
					{
						QStandardItem *pItem3 = new QStandardItem(QString("Free").arg(row).arg(AlarmState));
						if (nullptr != pItem3)
						{
							m_pAlarmItemModel->setItem(row, AlarmState, pItem3);
						}
					}
					if (1 != m_mapAlarmFlagIter->second && 1 == m_ilistenFlag)
					{
						QStandardItem *pItem3 = new QStandardItem(QString("Listen").arg(row).arg(AlarmState));
						if (nullptr != pItem3)
						{
							m_pAlarmItemModel->setItem(row, AlarmState, pItem3);
						}
					}
					if (1 == m_mapAlarmFlagIter->second && 1 != m_ilistenFlag)
					{
						QStandardItem *pItem3 = new QStandardItem(QString("AlarmChan").arg(row).arg(AlarmState));
						if (nullptr != pItem3)
						{
							m_pAlarmItemModel->setItem(row, AlarmState, pItem3);
						}
					}
				}
				
			}

			ui.alarmTableView->setModel(m_pAlarmItemModel);
			ui.alarmTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//横向填满表格
		}
	}
}

void CAlarmDevice::onClickedSetupAlarmChan() //这之后的都留有bug，暂未解决
{
	switch (QMessageBox::warning(NULL, "warning", QString("Need to Close all the Listen,Please confirm to continue!"),
		QMessageBox::Yes | QMessageBox::Default,
		QMessageBox::No | QMessageBox::Escape))
	{
	case QMessageBox::Yes:
		break;
	case QMessageBox::No:
		return;
	}
	if (1 == m_ilistenFlag)
	{
		m_pcDeviceInit->stopListen(m_lstartListenHandle);
		m_ilistenFlag = 0;
	}

	QModelIndex index = ui.alarmTableView->selectionModel()->currentIndex();
	long lsetupAlarmHandle;
	if (nullptr != m_pcDeviceInit)
	{
		
		if (0 == m_iAlarmFlag)
		{
			lsetupAlarmHandle = m_pcDeviceInit->setupAlarm(m_pcDeviceManagement->m_veclUserID.value(index.row()));
			m_maplSetupAlarmHandle.insert(std::make_pair(m_pcDeviceManagement->m_veclUserID.value(index.row()), lsetupAlarmHandle));
			m_iAlarmFlag = 1;
			m_maplAlarmFlag.insert(std::make_pair(m_pcDeviceManagement->m_veclUserID.value(index.row()), 1));
		}
		m_mapAlarmFlagIter = m_maplAlarmFlag.find(m_pcDeviceManagement->m_veclUserID.value(index.row()));
		if (1 != m_mapAlarmFlagIter->second && 1 == m_iAlarmFlag)
		{
			lsetupAlarmHandle = m_pcDeviceInit->setupAlarm(m_pcDeviceManagement->m_veclUserID.value(index.row()));
			m_maplSetupAlarmHandle.insert(std::make_pair(m_pcDeviceManagement->m_veclUserID.value(index.row()), lsetupAlarmHandle));
			m_iAlarmFlag = 1;
			m_maplAlarmFlag.insert(std::make_pair(m_pcDeviceManagement->m_veclUserID.value(index.row()), 1));
		}
		else
		{
			qDebug() << "the device alarm has already opened!" << endl;
		}
		setAlarmItem();
	}
}

void CAlarmDevice::onClickedCloseAlarmChan()
{
	QModelIndex index = ui.alarmTableView->selectionModel()->currentIndex();
	if (nullptr != m_pcDeviceInit)
	{
		m_mapAlarmFlagIter = m_maplAlarmFlag.find(m_pcDeviceManagement->m_veclUserID.value(index.row()));
		if (1 == m_mapAlarmFlagIter->second)
		{
			m_mapSetupAlarmIter = m_maplSetupAlarmHandle.find(m_pcDeviceManagement->m_veclUserID.value(index.row()));
			m_pcDeviceInit->closeAlarm(m_mapSetupAlarmIter->second);
			m_maplAlarmFlag.insert(std::make_pair(m_pcDeviceManagement->m_veclUserID.value(index.row()), 0));
		}
		else
		{
			qDebug() << "the device alarm has already closed" << endl;
			return;
		}
	}
}

void CAlarmDevice::onClickedStartListen()
{
	switch (QMessageBox::warning(NULL, "warning", QString("Need to Close all the Alarm,Please confirm to continue!"),
		QMessageBox::Yes | QMessageBox::Default,
		QMessageBox::No | QMessageBox::Escape))
	{
	case QMessageBox::Yes:
		break;
	case QMessageBox::No:
		return;
	}

	if (nullptr != m_pcDeviceManagement && nullptr != m_pcDeviceInit)
	{
		for (int i = 0; i < m_pcDeviceManagement->m_veclUserID.size(); ++i)
		{
			m_mapAlarmFlagIter = m_maplAlarmFlag.find(m_pcDeviceManagement->m_veclUserID.value(i));
			if (1 == m_mapAlarmFlagIter->second)
			{
				m_mapSetupAlarmIter = m_maplSetupAlarmHandle.find(m_pcDeviceManagement->m_veclUserID.value(i));
				m_pcDeviceInit->closeAlarm(m_mapSetupAlarmIter->second);
				m_maplAlarmFlag.insert(std::make_pair(m_pcDeviceManagement->m_veclUserID.value(i), 0));
			}
		}
	}

	if (nullptr != m_pcDeviceInit)
	{
		if (0 == m_ilistenFlag)
		{
			m_lstartListenHandle = m_pcDeviceInit->startListen(8000);
			m_ilistenFlag = 1;
		}
		else
		{
			qDebug() << "listen has already opened" << endl;
			return;
		}
	}
}

void CAlarmDevice::onClickedStopListen()
{
	if (nullptr != m_pcDeviceInit)
	{
		if (1 == m_ilistenFlag)
		{
			m_pcDeviceInit->stopListen(m_lstartListenHandle);
			m_ilistenFlag = 0;
		}
		else
		{
			qDebug() << "listen has already closed" << endl;
			return;
		}
	}
}

void CAlarmDevice::onClickedExit()
{
	ui.alarmerInfoWidget->hide();
}

void CAlarmDevice::slotsInit()
{
	connect(ui.SetupAlarmChanButton, &QPushButton::clicked, this, &CAlarmDevice::onClickedSetupAlarmChan);
	connect(ui.CloseAlarmChanButton, &QPushButton::clicked, this, &CAlarmDevice::onClickedCloseAlarmChan);
	connect(ui.StartListenButton, &QPushButton::clicked, this, &CAlarmDevice::onClickedStartListen);
	connect(ui.StopListenButton, &QPushButton::clicked, this, &CAlarmDevice::onClickedStopListen);
	connect(ui.alarmTableView, &QTableView::doubleClicked, this, &CAlarmDevice::onDoubleClickedAlarmDeviceInfo);
	connect(ui.exitButton, &QPushButton::clicked, this, &CAlarmDevice::onClickedExit);
}

CAlarmDevice::~CAlarmDevice()//析构
{
	if (nullptr != m_pcMonitorDatabase)
	{
		delete m_pcMonitorDatabase;
		m_pcMonitorDatabase = nullptr;
	}

	if (nullptr != m_pcDeviceManagement)
	{
		delete m_pcDeviceManagement;
		m_pcDeviceManagement = nullptr;
	}

	if (nullptr != m_pcDeviceInit)
	{
		delete m_pcDeviceInit;
		m_pcDeviceInit = nullptr;
	}
}
