#include "CHikVisionMonitor.h"

CHikVisionMonitor::CHikVisionMonitor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
	ui.ReviewLabel->show();

	ui.label->setStyleSheet("border:none;");
	ui.label_2->setStyleSheet("border:none;"); 
	ui.label_3->setStyleSheet("border:none;");
	ui.label_4->setStyleSheet("border:none;");
	ui.ReviewLabel->setStyleSheet("border:none;");
	ui.ReviewLabel_2->setStyleSheet("border:none;");
	ui.ReviewLabel_3->setStyleSheet("border:none;");
	ui.ReviewLabel_4->setStyleSheet("border:none;");

	ui.label->installEventFilter(this);//安装事件过滤器
	ui.label_2->installEventFilter(this);
	ui.label_3->installEventFilter(this);
	ui.label_4->installEventFilter(this);

	ui.soundSlider->setMaximum(100);
	ui.soundSlider->setMinimum(0);
	ui.soundSlider->setSingleStep(5);
	ui.soundSlider->setPageStep(5);
	ui.soundSlider->setValue(50);
	ui.soundSlider->setTracking(true);

	QIcon previewIcon;
	previewIcon.addFile(tr(":/CHikVisionMonitor/Resources/preview.png")); //预览Icon
	ui.PreviewButton->setIcon(previewIcon);
	ui.PreviewButton->setIconSize(QSize(32, 32));

	QIcon reviewIcon;
	reviewIcon.addFile(tr(":/CHikVisionMonitor/Resources/review.png"));  //回放Icon
	ui.ReviewButton->setIcon(reviewIcon);
	ui.ReviewButton->setIconSize(QSize(32, 32));

	QIcon deviceIcon;
	deviceIcon.addFile(tr(":/CHikVisionMonitor/Resources/device.png"));  //设备Icon
	ui.ManagementButton->setIcon(deviceIcon);
	ui.ManagementButton->setIconSize(QSize(32, 32));

	QIcon alarmIcon;
	alarmIcon.addFile(tr(":/CHikVisionMonitor/Resources/alarm.png"));  //报警Icon
	ui.alarmDeviceButton->setIcon(alarmIcon);
	ui.alarmDeviceButton->setIconSize(QSize(32, 32));

	//this->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");//全局边框圆角化
																				
	QFile file(":/CHikVisionMonitor/StyleSheet.qss");
	file.open(QFile::ReadOnly);//只读方式打开文件
	QString styleSheet = tr(file.readAll());
	this->setStyleSheet(styleSheet);//设置样式表

	//右键菜单搜索录像文件
	m_findFileMenu = new QMenu(this);
	m_findFileAction = new QAction(m_findFileMenu);
	if (nullptr != m_findFileMenu && nullptr != m_findFileAction)
	{
		m_findFileAction->setText("FindFile");
		m_findFileMenu->addAction(m_findFileAction);
	}
	ui.ReviewTreeView->setContextMenuPolicy(Qt::CustomContextMenu);

	//右键菜单抓图
	m_capturePictureMenu = new QMenu(this);
	m_capturePictureAction = new QAction(m_capturePictureMenu);
	if (nullptr != m_capturePictureMenu && nullptr != m_capturePictureAction)
	{
		m_capturePictureAction->setText("CapturePicture");
		m_capturePictureMenu->addAction(m_capturePictureAction);
	}
	ui.label->setContextMenuPolicy(Qt::CustomContextMenu);//给控件设置上下文菜单策略

	m_systemTray = new QSystemTrayIcon(this);
	m_menu = new QMenu(this);
	m_action1 = new QAction(m_menu);
	m_action2 = new QAction(m_menu);

	if (nullptr != m_menu && nullptr != m_action1 && nullptr != m_action2 && nullptr != m_systemTray)
	{
		m_action1->setText("Show Window");
		m_action2->setText("Show Message");

		m_menu->addAction(m_action1);
		m_menu->addAction(m_action2);

		m_systemTray->setIcon(QIcon(":/CHikVisionMonitor/Resources/Hik.ico"));
		m_systemTray->setToolTip("CHikVisionMonitor");
		m_systemTray->show();
	}	

	if (nullptr == m_pcDeviceInit)
	{
		m_pcDeviceInit = new CDeviceInit;
	}
	ui.DeviceManagementPage->setPointer(m_pcDeviceInit);
 	ui.DeviceManagementPage->login();
	if (nullptr == m_pcDatabase)
	{
		m_pcDatabase = new CMonitorDatabase;
	}

	m_pPreviewModel = new QStandardItemModel(ui.treeView);
	m_pReviewModel = new QStandardItemModel(ui.ReviewTreeView);
	m_pFindFileModel = new QStandardItemModel(ui.reviewFilelistView);
	addMonitor();
	ui.treeView->setModel(m_pPreviewModel);
	ui.ReviewTreeView->setModel(m_pReviewModel);
	ui.treeView->setHeaderHidden(true);//在QTreeView中应用上面构造的model
	ui.ReviewTreeView->setHeaderHidden(true);
	ui.treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
	ui.treeView->expandAll();
	ui.ReviewTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.ReviewTreeView->expandAll();

	//定时器创建
	m_pReviewPosTimer = new QTimer;
	m_pReviewPosTimer->setTimerType(Qt::PreciseTimer);

	slotInit();
}

void CHikVisionMonitor::getAddSignal() 
{
	addMonitor();
}

void CHikVisionMonitor::getDeleteSignal(const int &iNum)
{
	addMonitor();
	m_pPreviewModel->removeRow(iNum);
	m_pReviewModel->removeRow(iNum);
}

void CHikVisionMonitor::getModifySignal()
{
	addMonitor();
}

void CHikVisionMonitor::getLogoutSignal()
{
	addMonitor();
}

void CHikVisionMonitor::addMonitor() //增加监控节点
{
	if (nullptr != m_pcDatabase)
	{
		int iRowcount = m_pcDatabase->selectSize();
		if (nullptr != ui.DeviceManagementPage->m_pItemModel)
		{
			for (int i = 0; i < iRowcount; ++i)
			{
				CMonitorDatabase::struSqliteData struDeviceInfo;
				struDeviceInfo = m_pcDatabase->selectRow(m_pcDatabase->selectID().value(i).toInt());
				QVariant varPort = struDeviceInfo.Port;
				QVector<int> vecChanNum = m_pcDeviceInit->DoGetDeviceResoure(ui.DeviceManagementPage->m_veclUserID.value(i));

				QStandardItem *piecePreviewItem = new QStandardItem(QString(struDeviceInfo.IP));
				QStandardItem *pieceReviewItem = new QStandardItem(QString(struDeviceInfo.IP));

				if (nullptr != piecePreviewItem && nullptr != pieceReviewItem)
				{
					m_pPreviewModel->setItem(i, piecePreviewItem);
					m_pReviewModel->setItem(i, pieceReviewItem);
				}

				for (int j = 0; j < vecChanNum.size(); ++j)
				{
					QStandardItem *piecePreviewChildItem = new QStandardItem(QString("Channel: %1").arg(vecChanNum.value(j)));
					QStandardItem *pieceReviewChildItem = new QStandardItem(QString("Channel: %1").arg(vecChanNum.value(j)));

					if (nullptr != pieceReviewChildItem && nullptr != piecePreviewChildItem)
					{
						piecePreviewChildItem->setData(struDeviceInfo.IP, IP);
						pieceReviewChildItem->setData(struDeviceInfo.IP, IP);
						piecePreviewChildItem->setData(varPort.toString(), Port);
						pieceReviewChildItem->setData(varPort.toString(), Port);
						piecePreviewChildItem->setData(struDeviceInfo.Username, Username);
						pieceReviewChildItem->setData(struDeviceInfo.Username, Username);
						piecePreviewChildItem->setData(struDeviceInfo.Password, Password);
						pieceReviewChildItem->setData(struDeviceInfo.Password, Password);
						piecePreviewChildItem->setData(ui.DeviceManagementPage->m_veclUserID.value(i), UserID);
						pieceReviewChildItem->setData(ui.DeviceManagementPage->m_veclUserID.value(i), UserID);
						piecePreviewChildItem->setData(vecChanNum.value(j), Channel);
						pieceReviewChildItem->setData(vecChanNum.value(j), Channel);
					}

					if (nullptr != pieceReviewChildItem && nullptr != piecePreviewChildItem)
					{
						piecePreviewItem->appendRow(piecePreviewChildItem);
						pieceReviewItem->appendRow(pieceReviewChildItem);
					}
				}		
			}
		}
	}
}

void CHikVisionMonitor::fineFileRes(const int &iUserID, const int &iChannel)//显示录像查找文件
{
	for (int i = 0; i < m_vecstruFindDataInfotmp.size(); ++i)
	{
		QStandardItem *pFindFileItem = new QStandardItem(QString(m_vecstruFindDataInfotmp[i].sFileName));
		if (nullptr != pFindFileItem)
		{
			pFindFileItem->setData(iUserID, UserID);
			pFindFileItem->setData(iChannel, Channel);
		}
		if (nullptr != m_pFindFileModel)
		{
			m_pFindFileModel->appendRow(pFindFileItem);
		}		
	}
	ui.reviewFilelistView->setModel(m_pFindFileModel);
}

void CHikVisionMonitor::onDoubleClickedReview(const QModelIndex &index)//打开回放问题：只能打开两个问题*****************************************
{
		QString strIPValue = index.data(IP).toString();
		int iPortValue = index.data(Port).toInt();
		QString strUsernameValue = index.data(Username).toString();
		QString strPasswordValue = index.data(Password).toString();
		int iChannel = index.data(Channel).toInt();
		qDebug() << strIPValue;
		
		m_struItemInfo.IP = strIPValue;
		m_struItemInfo.Port = iPortValue;
		m_struItemInfo.Username = strUsernameValue;
		m_struItemInfo.Password = strPasswordValue;

		QDateTime m_beginDateTime = ui.BeginDateTimeEdit->dateTime();
		QDateTime m_endDateTime = ui.EndDateTimeEdit->dateTime();

		if (CamaraOne == m_iChooseCamaraValue)
		{
			m_lreviewID = m_pcDeviceInit->reviewInit(index.data(UserID).toInt(), (HWND)ui.ReviewLabel->winId(), m_beginDateTime, m_endDateTime, iChannel);
			m_listlReviewID.replace(0,m_lreviewID);
			m_listlReviewInformation.replace(0, std::make_pair(index.data(UserID).toInt(), m_lreviewID));
			m_pcDeviceInit->reviewStatus(index.data(UserID).toInt(),m_lreviewID, NET_DVR_PLAYSTART);
		}
		if (CamaraTwo == m_iChooseCamaraValue)
		{
			m_lreviewID = m_pcDeviceInit->reviewInit(index.data(UserID).toInt(),(HWND)ui.ReviewLabel_2->winId(), m_beginDateTime, m_endDateTime, iChannel);
			m_listlReviewID.replace(1,m_lreviewID);
			m_listlReviewInformation.replace(1, std::make_pair(index.data(UserID).toInt(), m_lreviewID));
			m_pcDeviceInit->reviewStatus(index.data(UserID).toInt(),m_lreviewID, NET_DVR_PLAYSTART);
		}
		if (CamaraThree == m_iChooseCamaraValue)
		{
			m_lreviewID = m_pcDeviceInit->reviewInit(index.data(UserID).toInt(),(HWND)ui.ReviewLabel_3->winId(), m_beginDateTime, m_endDateTime, iChannel);
			m_listlReviewID.replace(2,m_lreviewID);
			m_listlReviewInformation.replace(2, std::make_pair(index.data(UserID).toInt(), m_lreviewID));
			m_pcDeviceInit->reviewStatus(index.data(UserID).toInt(),m_lreviewID, NET_DVR_PLAYSTART);
		}
		if (CamaraFour == m_iChooseCamaraValue)
		{
			m_lreviewID = m_pcDeviceInit->reviewInit(index.data(UserID).toInt(),(HWND)ui.ReviewLabel_4->winId(), m_beginDateTime, m_endDateTime, iChannel);
			m_listlReviewID.replace(3,m_lreviewID);
			m_listlReviewInformation.replace(3, std::make_pair(index.data(UserID).toInt(), m_lreviewID));
			m_pcDeviceInit->reviewStatus(index.data(UserID).toInt(),m_lreviewID, NET_DVR_PLAYSTART);
		}		
}

void CHikVisionMonitor::onDoubleClickedFileReview(const QModelIndex &index)
{
	if (nullptr != m_pcDeviceInit)
	{
		if (CamaraOne == m_iChooseCamaraValue)
		{
			m_lreviewID = m_pcDeviceInit->reviewFileInit(index.data(UserID).toInt(), (HWND)ui.ReviewLabel->winId(), m_vecstruFindDataInfotmp[index.row()].struStartTime, m_vecstruFindDataInfotmp[index.row()].struStopTime, index.data(Channel).toInt());
			m_listlReviewID.replace(0, m_lreviewID);
			m_listlReviewInformation.replace(0, std::make_pair(index.data(UserID).toInt(), m_lreviewID));
			m_pcDeviceInit->reviewStatus(index.data(UserID).toInt(), m_lreviewID, NET_DVR_PLAYSTART);
		}
		if (CamaraTwo == m_iChooseCamaraValue)
		{
			m_lreviewID = m_pcDeviceInit->reviewFileInit(index.data(UserID).toInt(), (HWND)ui.ReviewLabel_2->winId(), m_vecstruFindDataInfotmp[index.row()].struStartTime, m_vecstruFindDataInfotmp[index.row()].struStopTime, index.data(Channel).toInt());
			m_listlReviewID.replace(1, m_lreviewID);
			m_listlReviewInformation.replace(1, std::make_pair(index.data(UserID).toInt(), m_lreviewID));
			m_pcDeviceInit->reviewStatus(index.data(UserID).toInt(), m_lreviewID, NET_DVR_PLAYSTART);
		}
		if (CamaraThree == m_iChooseCamaraValue)
		{
			m_lreviewID = m_pcDeviceInit->reviewFileInit(index.data(UserID).toInt(), (HWND)ui.ReviewLabel_3->winId(), m_vecstruFindDataInfotmp[index.row()].struStartTime, m_vecstruFindDataInfotmp[index.row()].struStopTime, index.data(Channel).toInt());
			m_listlReviewID.replace(2, m_lreviewID);
			m_listlReviewInformation.replace(2, std::make_pair(index.data(UserID).toInt(), m_lreviewID));
			m_pcDeviceInit->reviewStatus(index.data(UserID).toInt(), m_lreviewID, NET_DVR_PLAYSTART);
		}
		if (CamaraFour == m_iChooseCamaraValue)
		{
			m_lreviewID = m_pcDeviceInit->reviewFileInit(index.data(UserID).toInt(), (HWND)ui.ReviewLabel_4->winId(), m_vecstruFindDataInfotmp[index.row()].struStartTime, m_vecstruFindDataInfotmp[index.row()].struStopTime, index.data(Channel).toInt());
			m_listlReviewID.replace(3, m_lreviewID);
			m_listlReviewInformation.replace(3, std::make_pair(index.data(UserID).toInt(), m_lreviewID));
			m_pcDeviceInit->reviewStatus(index.data(UserID).toInt(), m_lreviewID, NET_DVR_PLAYSTART);
		}
		if (-1 != m_listlReviewID.value(m_iChooseCamaraValue - 1))
		{
			m_pReviewPosTimer->start(1000);
		}		
	}
}

void CHikVisionMonitor::onClickedStepOn()
{
	if (nullptr != m_pcDeviceInit)
	{
		m_listdwReviewPos.replace(m_iChooseCamaraValue - 1, m_pcDeviceInit->getReviewTotalTime(m_listlReviewInformation[m_iChooseCamaraValue - 1].first, m_listlReviewInformation[m_iChooseCamaraValue - 1].second, NET_DVR_PLAYGETPOS));
		m_pcDeviceInit->manageReviewPos(m_listlReviewInformation[m_iChooseCamaraValue - 1].first, m_listlReviewInformation[m_iChooseCamaraValue - 1].second, m_listdwReviewPos[m_iChooseCamaraValue - 1] + 10, NET_DVR_PLAYSETPOS);
	}
}

void CHikVisionMonitor::onClickedStepBack()
{
	if (nullptr != m_pcDeviceInit)
	{
		m_listdwReviewPos.replace(m_iChooseCamaraValue-1, m_pcDeviceInit->getReviewTotalTime(m_listlReviewInformation[m_iChooseCamaraValue - 1].first, m_listlReviewInformation[m_iChooseCamaraValue - 1].second, NET_DVR_PLAYGETPOS));
		m_pcDeviceInit->manageReviewPos(m_listlReviewInformation[m_iChooseCamaraValue - 1].first, m_listlReviewInformation[m_iChooseCamaraValue - 1].second, m_listdwReviewPos[m_iChooseCamaraValue - 1] - 10, NET_DVR_PLAYSETPOS);
	}
}

void CHikVisionMonitor::timeOutReviewPos()//留有BUG，暂未解决
{
	if (nullptr != m_pcDeviceInit)
	{
		if (m_pReviewPosTimer)
		{
			if (-1 == m_listlReviewID.value(m_iChooseCamaraValue - 1))
			{
				m_pReviewPosTimer->stop();
				killTimer(m_pReviewPosTimer->timerId());
				/*delete m_pReviewPosTimer;
				m_pReviewPosTimer = nullptr;*/
			}
			DWORD dw = m_pcDeviceInit->getReviewTotalTime(m_listlReviewInformation[m_iChooseCamaraValue - 1].first, m_listlReviewInformation[m_iChooseCamaraValue - 1].second, NET_DVR_PLAYGETTIME);
			std::string str = std::to_string(long long(dw));
			QString qstr = QString::fromStdString(str);
			ui.totalTimeLabel->setText(qstr);			
		}
	}
}

void CHikVisionMonitor::onDoubleClickedOpenCamara(const QModelIndex &index)//打开预览
{
	if (0 == ui.stackedWidget->currentIndex())
	{
		QString strIPValue = index.data(IP).toString();
		int iPortValue = index.data(Port).toInt();
		QString strUsernameValue = index.data(Username).toString();
		QString strPasswordValue = index.data(Password).toString();
		int iChannel = index.data(Channel).toInt();
		qDebug() << iChannel;
		qDebug() << index.data(UserID).toInt();

		m_struItemInfo.IP = strIPValue;
		m_struItemInfo.Port = iPortValue;
		m_struItemInfo.Username = strUsernameValue;
		m_struItemInfo.Password = strPasswordValue;
		
		if (CamaraOne == m_iChooseCamaraValue)
		{
			m_listlPreviewID.replace(0, m_pcDeviceInit->previewBegin(index.data(UserID).toInt(), iChannel, (HWND)ui.label->winId()));
			ui.label->show();
		}

		if (CamaraTwo == m_iChooseCamaraValue)
		{
			m_listlPreviewID.replace(1, m_pcDeviceInit->previewBegin(index.data(UserID).toInt(), iChannel, (HWND)ui.label_2->winId()));
			ui.label_2->show();
		}

		if (CamaraThree == m_iChooseCamaraValue)
		{
			m_listlPreviewID.replace(2, m_pcDeviceInit->previewBegin(index.data(UserID).toInt(), iChannel, (HWND)ui.label_3->winId()));
			ui.label_3->show();
		}

		if (CamaraFour == m_iChooseCamaraValue)
		{
			m_listlPreviewID.replace(3, m_pcDeviceInit->previewBegin(index.data(UserID).toInt(), iChannel, (HWND)ui.label_4->winId()));
			ui.label_4->show();
		}			
	}
}

void CHikVisionMonitor::onClickedStopPreview()//停止预览
{
	if (CamaraOne == m_iChooseCamaraValue)
	{
		m_pcDeviceInit->previewStop(m_listlPreviewID.value(0));
		ui.label->repaint();
	}
	if (CamaraTwo == m_iChooseCamaraValue)
	{
		m_pcDeviceInit->previewStop(m_listlPreviewID.value(1));
		ui.label_2->repaint();
	}
	if (CamaraThree == m_iChooseCamaraValue)
	{
		m_pcDeviceInit->previewStop(m_listlPreviewID.value(2));
		ui.label_3->repaint();
	}
	if (CamaraFour == m_iChooseCamaraValue)
	{
		m_pcDeviceInit->previewStop(m_listlPreviewID.value(3));
		ui.label_4->repaint();
	}
}

void CHikVisionMonitor::onClickedStopReview()//停止回放
{
	if (CamaraOne == m_iChooseCamaraValue)
	{
		m_pcDeviceInit->reviewStop(m_listlReviewID.value(0));
		m_listlReviewID.replace(0, -1);
		ui.ReviewLabel->repaint();
	}
	if (CamaraTwo == m_iChooseCamaraValue)
	{
		m_pcDeviceInit->reviewStop(m_listlReviewID.value(1));
		m_listlReviewID.replace(1, -1);
		ui.ReviewLabel_2->repaint();
	}
	if (CamaraThree == m_iChooseCamaraValue)
	{
		m_pcDeviceInit->reviewStop(m_listlReviewID.value(2));
		m_listlReviewID.replace(2, -1);
		ui.ReviewLabel_3->repaint();
	}
	if (CamaraFour == m_iChooseCamaraValue)
	{
		m_pcDeviceInit->reviewStop(m_listlReviewID.value(3));
		m_listlReviewID.replace(3, -1);
		ui.ReviewLabel_4->repaint();
	}
}

void CHikVisionMonitor::reviewStatusControl(const long &lStatus)
{
	QModelIndex index = ui.ReviewTreeView->selectionModel()->currentIndex();
	m_pcDeviceInit->reviewStatus(index.data(UserID).toInt(), m_listlPreviewID.value(m_iChooseCamaraValue - 1), lStatus);
	//ui.ReviewLabel->show();
}

void CHikVisionMonitor::onClickedReviewPause()
{
	reviewStatusControl(NET_DVR_PLAYPAUSE);
	return;
}

void CHikVisionMonitor::onClickedRestart()
{
	reviewStatusControl(NET_DVR_PLAYRESTART);
	return;
}

void CHikVisionMonitor::onClickedReviewFast()
{
	reviewStatusControl(NET_DVR_PLAYFAST);
	return;
}

void CHikVisionMonitor::onClickedReviewSlow()
{
	reviewStatusControl(NET_DVR_PLAYSLOW);
	return;
}

void CHikVisionMonitor::onClickedReviewNormal()
{
	reviewStatusControl(NET_DVR_PLAYNORMAL);
	return;
}

void CHikVisionMonitor::onClickedReviewSingleFrame()
{
	reviewStatusControl(NET_DVR_PLAYFRAME);
	return;
}

void CHikVisionMonitor::onClickedDeviceManagement()//弹出设备管理界面
{
	ui.stackedWidget->setCurrentIndex(2);
}

void CHikVisionMonitor::onClickedSelecetReviewPage()//切换回放页面
{
	ui.stackedWidget->setCurrentIndex(1);
}

void CHikVisionMonitor::onClickedSelecetPreviewPage()//切换预览页面
{
	ui.stackedWidget->setCurrentIndex(0);
}

void CHikVisionMonitor::onClickedAlarmDevice()
{
	ui.stackedWidget->setCurrentIndex(3);
}

void CHikVisionMonitor::onClickedChooseCamara1()
{
	qDebug() << "ChooseCamara 1" << endl;
	m_iChooseCamaraValue = 1;
	ui.frame->setStyleSheet("background:transparent;border:4px outset red;");
	ui.frame_2->setStyleSheet(NULL);  //设置窗口无边框
	ui.frame_3->setStyleSheet(NULL);  //设置窗口无边框
	ui.frame_4->setStyleSheet(NULL);  //设置窗口无边框
	ui.reviewFrame->setStyleSheet("background:transparent;border:4px outset red;");
	ui.reviewFrame2->setStyleSheet(NULL);  //设置窗口无边框
	ui.reviewFrame3->setStyleSheet(NULL);  //设置窗口无边框
	ui.reviewFrame4->setStyleSheet(NULL);  //设置窗口无边框
}

void CHikVisionMonitor::onClickedChooseCamara2()
{
	qDebug() << "ChooseCamara 2" << endl;
	m_iChooseCamaraValue = 2;
	ui.frame_2->setStyleSheet("background:transparent;border:4px outset red;");
	ui.frame->setStyleSheet(NULL);  //设置窗口无边框
	ui.frame_3->setStyleSheet(NULL);  //设置窗口无边框
	ui.frame_4->setStyleSheet(NULL);  //设置窗口无边框
	ui.reviewFrame2->setStyleSheet("background:transparent;border:4px outset red;");
	ui.reviewFrame->setStyleSheet(NULL);  //设置窗口无边框
	ui.reviewFrame3->setStyleSheet(NULL);  //设置窗口无边框
	ui.reviewFrame4->setStyleSheet(NULL);  //设置窗口无边框
}

void CHikVisionMonitor::onClickedChooseCamara3()
{
	qDebug() << "ChooseCamara 3" << endl;
	m_iChooseCamaraValue = 3;
	ui.frame_3->setStyleSheet("background:transparent;border:4px outset red;");
	ui.frame_2->setStyleSheet(NULL);  //设置窗口无边框
	ui.frame->setStyleSheet(NULL);  //设置窗口无边框
	ui.frame_4->setStyleSheet(NULL);  //设置窗口无边框
	ui.reviewFrame3->setStyleSheet("background:transparent;border:4px outset red;");
	ui.reviewFrame2->setStyleSheet(NULL);  //设置窗口无边框
	ui.reviewFrame->setStyleSheet(NULL);  //设置窗口无边框
	ui.reviewFrame4->setStyleSheet(NULL);  //设置窗口无边框
}

void CHikVisionMonitor::onClickedChooseCamara4()
{
	qDebug() << "ChooseCamara 4" << endl;
	m_iChooseCamaraValue = 4;
	ui.frame_4->setStyleSheet("background:transparent;border:4px outset red;");
	ui.frame_2->setStyleSheet(NULL);  //设置窗口无边框
	ui.frame_3->setStyleSheet(NULL);  //设置窗口无边框
	ui.frame->setStyleSheet(NULL);  //设置窗口无边框
	ui.reviewFrame4->setStyleSheet("background:transparent;border:4px outset red;");
	ui.reviewFrame2->setStyleSheet(NULL);  //设置窗口无边框
	ui.reviewFrame3->setStyleSheet(NULL);  //设置窗口无边框
	ui.reviewFrame->setStyleSheet(NULL);  //设置窗口无边框
}

void CHikVisionMonitor::onChangedStateVideo(const int &istate)
{
	if (nullptr != m_pcDeviceInit)
	{
		if (Qt::Checked == istate)
		{
			m_pcDeviceInit->saveRealData(m_listlPreviewID.value(m_iChooseCamaraValue - 1));
		}
		if (Qt::Unchecked == istate)
		{
			m_pcDeviceInit->stopSaveRealData(m_listlPreviewID.value(m_iChooseCamaraValue - 1));
		}
	}
}

void CHikVisionMonitor::onClickedSoundManage()
{
	if (nullptr != m_pcDeviceInit)
	{
		if (CamaraOne == m_iChooseCamaraValue)
		{
			m_pcDeviceInit->closeSound();
			m_pcDeviceInit->openSound(m_listlPreviewID.value(0));
		}
		if (CamaraTwo == m_iChooseCamaraValue)
		{
			m_pcDeviceInit->closeSound();
			m_pcDeviceInit->openSound(m_listlPreviewID.value(1));
		}
		if (CamaraThree == m_iChooseCamaraValue)
		{
			m_pcDeviceInit->closeSound();
			m_pcDeviceInit->openSound(m_listlPreviewID.value(2));
		}
		if (CamaraFour == m_iChooseCamaraValue)
		{
			m_pcDeviceInit->closeSound();
			m_pcDeviceInit->openSound(m_listlPreviewID.value(3));
		}
	}
}

void CHikVisionMonitor::soundMonitor(int isoundVal)
{
	if (nullptr != m_pcDeviceInit)
	{
		if (CamaraOne == m_iChooseCamaraValue)
		{
			m_pcDeviceInit->soundVolume(m_listlPreviewID.value(0), isoundVal);
		}
		if (CamaraTwo == m_iChooseCamaraValue)
		{
			m_pcDeviceInit->soundVolume(m_listlPreviewID.value(1), isoundVal);
		}
		if (CamaraThree == m_iChooseCamaraValue)
		{
			m_pcDeviceInit->soundVolume(m_listlPreviewID.value(2), isoundVal);
		}
		if (CamaraFour == m_iChooseCamaraValue)
		{
			m_pcDeviceInit->soundVolume(m_listlPreviewID.value(3), isoundVal);
		}
	}
}

void CHikVisionMonitor::activeTray(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
	case QSystemTrayIcon::Context:
		showMenu();
		break;
	case QSystemTrayIcon::DoubleClick:
		showWindow();
		break;
	case QSystemTrayIcon::Trigger:
		showMessage();
		break;
	}
}

void CHikVisionMonitor::showMenu()
{
	m_menu->show();
}

void CHikVisionMonitor::showWindow()
{
	this->show();
}

void CHikVisionMonitor::showMessage()
{
	m_systemTray->showMessage("Information",//消息窗口标题
		"There is a new message!",//消息内容
		QSystemTrayIcon::MessageIcon::Information,//消息窗口图标 
		5000);//消息窗口显示时长
}

void CHikVisionMonitor::slotInit()
{
	//定时器槽函数
	connect(m_pReviewPosTimer, &QTimer::timeout, this, &CHikVisionMonitor::timeOutReviewPos);
	//槽函数
	connect(ui.ReviewTreeView, &QTreeView::customContextMenuRequested, [=](const QPoint &pos)//右键菜单
	{
		qDebug() << pos;//参数pos用来传递右键点击时的鼠标的坐标，这个坐标一般是相对于控件左上角而言的
		m_findFileMenu->exec(QCursor::pos());
	});
	connect(ui.videoCheckBox, &QCheckBox::stateChanged, this, &CHikVisionMonitor::onChangedStateVideo);
	connect(ui.soundSlider, &QSlider::valueChanged, this, &CHikVisionMonitor::soundMonitor);
	connect(ui.ReviewTreeView, &QTreeView::doubleClicked, this, &CHikVisionMonitor::onDoubleClickedReview);
	connect(ui.reviewFilelistView, &QListView::doubleClicked, this, &CHikVisionMonitor::onDoubleClickedFileReview);
	connect(ui.stopButton, &QPushButton::clicked, this, &CHikVisionMonitor::onClickedStopReview);
	connect(ui.pauseButton, &QPushButton::clicked, this, &CHikVisionMonitor::onClickedReviewPause);
	connect(ui.replayButton, &QPushButton::clicked, this, &CHikVisionMonitor::onClickedRestart);
	connect(ui.quickPlayButton, &QPushButton::clicked, this, &CHikVisionMonitor::onClickedReviewFast);
	connect(ui.slowPlayButton, &QPushButton::clicked, this, &CHikVisionMonitor::onClickedReviewSlow);
	connect(ui.normalPlayButton, &QPushButton::clicked, this, &CHikVisionMonitor::onClickedReviewNormal);
	connect(ui.singleFrameButton, &QPushButton::clicked, this, &CHikVisionMonitor::onClickedReviewSingleFrame);
	connect(ui.treeView, &QTreeView::doubleClicked, this, &CHikVisionMonitor::onDoubleClickedOpenCamara);
	connect(ui.StopPreviewButton, &QPushButton::clicked, this, &CHikVisionMonitor::onClickedStopPreview);
	connect(ui.ManagementButton, &QPushButton::clicked, this, &CHikVisionMonitor::onClickedDeviceManagement);
	connect(ui.alarmDeviceButton, &QPushButton::clicked, this, &CHikVisionMonitor::onClickedAlarmDevice);
	connect(ui.ReviewButton, &QPushButton::clicked, this, &CHikVisionMonitor::onClickedSelecetReviewPage);
	connect(ui.PreviewButton, &QPushButton::clicked, this, &CHikVisionMonitor::onClickedSelecetPreviewPage);
	connect(ui.soundButton, &QPushButton::clicked, this, &CHikVisionMonitor::onClickedSoundManage);
	connect(ui.reviewStepOnLabel, &CMyLabel::clicked, this, &CHikVisionMonitor::onClickedStepOn);
	connect(ui.reviewStepBackLabel, &CMyLabel::clicked, this, &CHikVisionMonitor::onClickedStepBack);
	//信号函数
	//CDeviceManagement *m_pcDeviceManagement = new CDeviceManagement;
	connect(ui.DeviceManagementPage, SIGNAL(addSignal()), this, SLOT(getAddSignal()));
	connect(ui.DeviceManagementPage, SIGNAL(deleteSignal(int)), this, SLOT(getDeleteSignal(int)));
	connect(ui.DeviceManagementPage, SIGNAL(modifySignal()), this, SLOT(getModifySignal()));
	connect(ui.DeviceManagementPage, SIGNAL(logoutSignal()), this, SLOT(getLogoutSignal()));
	//窗口选择
	connect(ui.label, &CMyLabel::clicked, this, &CHikVisionMonitor::onClickedChooseCamara1);
	connect(ui.label, &QLabel::customContextMenuRequested, [=](const QPoint &pos)//右键菜单
	{
		qDebug() << pos;//参数pos用来传递右键点击时的鼠标的坐标，这个坐标一般是相对于控件左上角而言的
		m_iChooseCamaraValue = 1;
		m_capturePictureMenu->exec(QCursor::pos());
	});
	connect(ui.label_2, &CMyLabel::clicked, this, &CHikVisionMonitor::onClickedChooseCamara2);
	connect(ui.label_2, &QLabel::customContextMenuRequested, [=](const QPoint &pos)//右键菜单
	{
		qDebug() << pos;//参数pos用来传递右键点击时的鼠标的坐标，这个坐标一般是相对于控件左上角而言的
		m_iChooseCamaraValue = 2;
		m_capturePictureMenu->exec(QCursor::pos());
	});
	connect(ui.label_3, &CMyLabel::clicked, this, &CHikVisionMonitor::onClickedChooseCamara3);
	connect(ui.label_3, &QLabel::customContextMenuRequested, [=](const QPoint &pos)//右键菜单
	{
		qDebug() << pos;//参数pos用来传递右键点击时的鼠标的坐标，这个坐标一般是相对于控件左上角而言的
		m_iChooseCamaraValue = 3;
		m_capturePictureMenu->exec(QCursor::pos());
	});
	connect(ui.label_4, &CMyLabel::clicked, this, &CHikVisionMonitor::onClickedChooseCamara4);
	connect(ui.label_4, &QLabel::customContextMenuRequested, [=](const QPoint &pos)//右键菜单
	{
		qDebug() << pos;//参数pos用来传递右键点击时的鼠标的坐标，这个坐标一般是相对于控件左上角而言的
		m_iChooseCamaraValue = 4;
		m_capturePictureMenu->exec(QCursor::pos());
	});
	connect(ui.ReviewLabel, &CMyLabel::clicked, this, &CHikVisionMonitor::onClickedChooseCamara1);
	connect(ui.ReviewLabel_2, &CMyLabel::clicked, this, &CHikVisionMonitor::onClickedChooseCamara2);
	connect(ui.ReviewLabel_3, &CMyLabel::clicked, this, &CHikVisionMonitor::onClickedChooseCamara3);
	connect(ui.ReviewLabel_4, &CMyLabel::clicked, this, &CHikVisionMonitor::onClickedChooseCamara4);
	//托盘菜单
	connect(m_systemTray, &QSystemTrayIcon::activated, this, &CHikVisionMonitor::activeTray);//点击托盘，执行相应的动作
	connect(m_action1, &QAction::triggered, this, &CHikVisionMonitor::showWindow);
	connect(m_action2, &QAction::triggered, this, &CHikVisionMonitor::showMessage);
	connect(m_systemTray, &QSystemTrayIcon::messageClicked, this, &CHikVisionMonitor::showWindow);//点击消息框，显示主窗口
	//录像查找菜单
	connect(m_findFileAction, &QAction::triggered, [=]()
	{
		m_vecstruFindDataInfotmp.clear();
		if (nullptr != m_pcDeviceInit)
		{
			QModelIndex index = ui.ReviewTreeView->selectionModel()->currentIndex();
			QDateTime beginDateTime = ui.BeginDateTimeEdit->dateTime();
			QDateTime endDateTime = ui.EndDateTimeEdit->dateTime();
			long lFindHandle = m_pcDeviceInit->findFile(index.data(UserID).toInt(), beginDateTime, endDateTime, index.data(Channel).toInt());
			while (1003 != m_pcDeviceInit->returnRes)
			{
				m_vecstruFindDataInfotmp.push_back(m_pcDeviceInit->findNextFile(lFindHandle));
			}	
			fineFileRes(index.data(UserID).toInt(), index.data(Channel).toInt());
		}
	});
	//抓图菜单
	connect(m_capturePictureAction, &QAction::triggered, [=]()
	{
		if (nullptr != m_pcDeviceInit)
		{
			if (CamaraOne == m_iChooseCamaraValue)
			{
				m_pcDeviceInit->capturePicture(m_listlPreviewID.value(0));
			}
			if (CamaraTwo == m_iChooseCamaraValue)
			{
				m_pcDeviceInit->capturePicture(m_listlPreviewID.value(1));
			}
			if (CamaraThree == m_iChooseCamaraValue)
			{
				m_pcDeviceInit->capturePicture(m_listlPreviewID.value(2));
			}
			if (CamaraFour == m_iChooseCamaraValue)
			{
				m_pcDeviceInit->capturePicture(m_listlPreviewID.value(3));
			}
		}	
	});
}

bool CHikVisionMonitor::eventFilter(QObject *obj, QEvent *event)//双击全屏与缩小
{
	if (obj == ui.label)
	{
		if (event->type() == QEvent::MouseButtonDblClick)
		{
			m_iClickNum++;
			if (0 == m_iClickNum % 2)
			{
				ui.label->setWindowFlags(Qt::Window);//该函数表示将窗口设为顶层窗口，因为函数showFullScreen只对顶级窗口有效，原始的顶级窗口是this
				ui.label->showFullScreen();		//全屏显示函数
			}
			else
			{
				ui.label->setWindowFlags(Qt::SubWindow);
				ui.label->showNormal();
			};
		}
		return QObject::eventFilter(obj, event);
	}

	if (obj == ui.label_2)
	{
		if (event->type() == QEvent::MouseButtonDblClick)
		{
			m_iClickNum++;
			if (0 == m_iClickNum % 2)
			{
				ui.label_2->setWindowFlags(Qt::Window);//该函数表示将窗口设为顶层窗口，因为函数showFullScreen只对顶级窗口有效，原始的顶级窗口是this
				ui.label_2->showFullScreen();		//全屏显示函数
			}
			else
			{
				ui.label_2->setWindowFlags(Qt::SubWindow);
				ui.label_2->showNormal();
			};
		}
		return QObject::eventFilter(obj, event);
	}

	if (obj == ui.label_3)
	{
		if (event->type() == QEvent::MouseButtonDblClick)
		{
			m_iClickNum++;
			if (0 == m_iClickNum % 2)
			{
				ui.label_3->setWindowFlags(Qt::Window);//该函数表示将窗口设为顶层窗口，因为函数showFullScreen只对顶级窗口有效，原始的顶级窗口是this
				ui.label_3->showFullScreen();		//全屏显示函数
			}
			else
			{
				ui.label_3->setWindowFlags(Qt::SubWindow);
				ui.label_3->showNormal();
			};
		}
		return QObject::eventFilter(obj, event);
	}

	if (obj == ui.label_4)
	{
		if (event->type() == QEvent::MouseButtonDblClick)
		{
			m_iClickNum++;
			if (0 == m_iClickNum % 2)
			{
				ui.label_4->setWindowFlags(Qt::Window);//该函数表示将窗口设为顶层窗口，因为函数showFullScreen只对顶级窗口有效，原始的顶级窗口是this
				ui.label_4->showFullScreen();		//全屏显示函数
			}
			else
			{
				ui.label_4->setWindowFlags(Qt::SubWindow);
				ui.label_4->showNormal();
			};
		}
		return QObject::eventFilter(obj, event);
	}
}