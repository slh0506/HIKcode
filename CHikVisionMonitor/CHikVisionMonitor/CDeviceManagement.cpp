#include "CDeviceManagement.h"

CDeviceManagement::CDeviceManagement(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.addWidget->hide();
	ui.ModifyWidget->hide();
	//ģ̬
	ui.addWidget->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	ui.addWidget->setWindowModality(Qt::WindowModal);//�赲���״����������ؼ������Ǳ�widget�ر�
	ui.ModifyWidget->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	ui.ModifyWidget->setWindowModality(Qt::WindowModal);//�赲���״����������ؼ������Ǳ�widget�ر�
	ui.addWidget->move(600, 260);
	ui.ModifyWidget->move(600, 260);


	
	if (nullptr == m_pcDatabase)
	{
		m_pcDatabase = new CMonitorDatabase;
		m_pcDatabase->createConnection();
		m_pcDatabase->createTable();	
		/*m_pcDatabase->selectSize();*/
	}
	iRowcount = m_pcDatabase->selectSize();
	m_pItemModel = new QStandardItemModel(iRowcount,4,ui.tableView);
		//��ͷ��IP Port �豸���� ����״̬ UserID
	if (nullptr != m_pItemModel)
	{
		m_pItemModel->setHeaderData(0, Qt::Horizontal, QObject::tr("IP"));
		m_pItemModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Port"));
		m_pItemModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Device Type"));
		m_pItemModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Network State"));
	}	
	/*if (nullptr == m_pcDeviceInit)
	{
		m_pcDeviceInit = new CDeviceInit;
	}*/	

	if (nullptr != m_pItemModel)
	{
		iRowcount = m_pcDatabase->selectSize();
		setItemValues(iRowcount);
	}

	ui.tableView->setModel(m_pItemModel);
	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//���ɱ༭
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//�����������
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//����ѡ��

	slotInit();
}

void CDeviceManagement::setItemValues(const int &iRowcount)//����Iitem ��Ϣ
{
		for (int row = 0; row < iRowcount; ++row)
		{
			if (nullptr != m_pcDatabase)
			{
				struDeviceInfo = m_pcDatabase->selectRow(m_pcDatabase->selectID().value(row).toInt());
			}
			QVariant varPort = struDeviceInfo.Port;
				
			QStandardItem *pItem1 = new QStandardItem(QString(struDeviceInfo.IP).arg(row).arg(IP));
			m_pItemModel->setItem(row, IP, pItem1);

			QStandardItem *pItem2 = new QStandardItem(QString(varPort.toString()).arg(row).arg(Port));
			m_pItemModel->setItem(row, Port, pItem2);

			QStandardItem *pItem3 = new QStandardItem(QString("Coding Equipment").arg(row).arg(DeviceType));
			m_pItemModel->setItem(row, DeviceType, pItem3);

			if (m_veclUserID.value(row) < 0)
			{
				QStandardItem *pItem4 = new QStandardItem(QString("Offline").arg(row).arg(Status));
				m_pItemModel->setItem(row, Status, pItem4);
			}
			else
			{
				QStandardItem *pItem4 = new QStandardItem(QString("Online").arg(row).arg(Status));
				m_pItemModel->setItem(row, Status, pItem4);
			}
			ui.tableView->setModel(m_pItemModel);
		}	
}

void CDeviceManagement::login()
{
	m_pcDeviceInit->initSDK();
	for (int row = 0; row < iRowcount; ++row)
	{
		if (nullptr != m_pcDatabase && nullptr != m_pcDeviceInit)
		{
			CMonitorDatabase::struSqliteData struSqlInfo;
			struSqlInfo = m_pcDatabase->selectRow(m_pcDatabase->selectID().value(row).toInt());			
			m_veclUserID.push_back(m_pcDeviceInit->loginSDKInit(struSqlInfo));
		}
	}
}

void CDeviceManagement::onClickedDelete()//ɾ���豸��Ϣ
{
	QModelIndex index = ui.tableView->selectionModel()->currentIndex();
	int iRow = index.row();
	QString strIP = index.sibling(index.row(), 0).data().toString();
	if (nullptr != m_pItemModel && nullptr != m_pcDatabase)
	{
		m_pcDatabase->deleteValues(strIP);
		m_pItemModel->removeRow(index.row());
		m_pItemModel->submit();
		m_pcDeviceInit->logoutSDK(m_veclUserID.value(index.row()));
		ui.tableView->setModel(m_pItemModel);
		ui.tableView->show();
		ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//�����������
		emit deleteSignal(iRow);
	}
}

void CDeviceManagement::onClickedAdd()//��������豸��Ϣ����
{
	ui.addWidget->show();
}

void CDeviceManagement::onClickedExit()//�˳�����豸��Ϣ����
{
	ui.addWidget->hide();
}

void CDeviceManagement::onClickedLogin()//��¼����豸��Ϣ�����浽���ݿ�
{
	m_strIP = ui.IPLineEdit->text();
	m_strPort = ui.PortLineEdit->text();
	m_iPort = m_strPort.toInt();
	m_strUsername = ui.UsernameLineEdit->text();
	m_strPassword = ui.PasswordLineEdit->text();	

	CMonitorDatabase::struSqliteData struSqlInfo;
	struSqlInfo.IP = m_strIP;
	struSqlInfo.Port = m_iPort;
	struSqlInfo.Username = m_strUsername;
	struSqlInfo.Password = m_strPassword;
	
	if (m_pcDatabase->insertValues(struSqlInfo))
	{
		if (nullptr != m_pcDeviceInit)
		{
			m_veclUserID.push_back(m_pcDeviceInit->loginSDKInit(struSqlInfo));
		}	
		if (nullptr != m_pItemModel)
		{
			iRowcount = m_pcDatabase->selectSize();
			setItemValues(iRowcount);
			ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//�����������
		}
	}
	emit addSignal();
}

void CDeviceManagement::onClickedLogout()//ע���豸��Ϣ
{
	QModelIndex index = ui.tableView->selectionModel()->currentIndex();
	if (nullptr != m_pcDeviceInit)
	{
		m_pcDeviceInit->logoutSDK(m_veclUserID.value(index.row()));
	}	
	ui.addWidget->hide();
	emit logoutSignal();
}

void CDeviceManagement::onClickedModify(const QModelIndex &index)//�޸��豸��Ϣ
{
	int iRowNum = index.row();
	ui.ModifyWidget->show();

	CMonitorDatabase::struSqliteData struDeviceInfo;
	if (nullptr != m_pcDatabase)
	{
		struDeviceInfo = m_pcDatabase->selectRow(m_pcDatabase->selectID().value(iRowNum).toInt());
	}	
	QVariant varPort = struDeviceInfo.Port;

	ui.ModifyIPLineEdit->setText(struDeviceInfo.IP);
	ui.ModifyPortLineEdit->setText(varPort.toString());
	ui.ModifyUsernameLineEdit->setText(struDeviceInfo.Username);
	ui.ModifyPasswordLineEdit->setText(struDeviceInfo.Password);
}

void CDeviceManagement::onClickedModifyCheck()//ȷ���޸��豸��Ϣ
{
	m_strIP = ui.ModifyIPLineEdit->text();
	m_strPort = ui.ModifyPortLineEdit->text();
	m_iPort = m_strPort.toInt();
	m_strUsername = ui.ModifyUsernameLineEdit->text();
	m_strPassword = ui.ModifyPasswordLineEdit->text();

	CMonitorDatabase::struSqliteData struSqlInfo;
	struSqlInfo.IP = m_strIP;
	struSqlInfo.Port = m_iPort;
	struSqlInfo.Username = m_strUsername;
	struSqlInfo.Password = m_strPassword;

	QModelIndex index = ui.tableView->selectionModel()->currentIndex();
	int iRowNum = index.row();
	if (nullptr != m_pItemModel && nullptr != m_pcDatabase)
	{
		m_pcDatabase->replaceValues(struSqlInfo,m_pcDatabase->selectID().value(iRowNum).toInt());
		iRowcount = m_pcDatabase->selectSize();
		if (nullptr != m_pcDeviceInit)
		{
			m_pcDeviceInit->logoutSDK(m_veclUserID.value(iRowNum));
		}	
		m_veclUserID.replace(iRowNum,m_pcDeviceInit->loginSDKInit(struSqlInfo));
		setItemValues(iRowcount);
		ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//�����������
	}
	emit modifySignal();
}

void CDeviceManagement::onClickedModifyCancel()//ȡ���޸��豸��Ϣ
{
	ui.ModifyWidget->hide();
}

void CDeviceManagement::onClickedModifyExit()//�˳��޸��豸��Ϣ����
{
	ui.ModifyWidget->hide();
}

bool CDeviceManagement::event(QEvent *event)//����հ״��˳��ӽ���
{
	if (event->type() == QEvent::ActivationChange)
	{
		if (QApplication::activeWindow() != ui.ModifyWidget)
		{
			ui.ModifyWidget->hide();
		}
	}
	if (event->type() == QEvent::ActivationChange)
	{
		if (QApplication::activeWindow() != ui.addWidget)
		{
			ui.addWidget->hide();
		}
	}
	return QWidget::event(event);
}

void CDeviceManagement::slotInit()
{
	//�ۺ���
	connect(ui.tableView, &QTableView::doubleClicked, this, &CDeviceManagement::onClickedModify);
	connect(ui.DeleteButton, &QPushButton::clicked, this, &CDeviceManagement::onClickedDelete);
	connect(ui.AddButton, &QPushButton::clicked, this, &CDeviceManagement::onClickedAdd);
	connect(ui.ExitButton, &QPushButton::clicked, this, &CDeviceManagement::onClickedExit);
	connect(ui.LoginButton, &QPushButton::clicked, this, &CDeviceManagement::onClickedLogin);
	connect(ui.LogoutButton, &QPushButton::clicked, this, &CDeviceManagement::onClickedLogout);
	connect(ui.ModifyCancelButton, &QPushButton::clicked, this, &CDeviceManagement::onClickedModifyCancel);
	connect(ui.ModifyExitButton, &QPushButton::clicked, this, &CDeviceManagement::onClickedModifyExit);
	connect(ui.ModifyCheckButton, &QPushButton::clicked, this, &CDeviceManagement::onClickedModifyCheck);
}

CDeviceManagement::~CDeviceManagement()
{
	if (nullptr != m_pcDatabase)
	{
		delete m_pcDatabase;
		m_pcDatabase = nullptr;
	}

	if (nullptr != m_pcDeviceInit)
	{
		delete m_pcDeviceInit;
		m_pcDeviceInit = nullptr;
	}
}