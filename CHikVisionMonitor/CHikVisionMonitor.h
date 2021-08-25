#pragma once
#include "include/HCNetSDK.h"
#include <QDateTime>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QDebug>
#include <QList>
#include <QIcon>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QPair>
#include <QTimer>
#include "MyLabel.h"
#include "CDeviceManagement.h"
#include "DeviceInit.h"
#include "MonitorDatabase.h"
#include "ui_CHikVisionMonitor.h"

#define NET_DVR_PLAYSTART        1//开始播放
#define NET_DVR_PLAYPAUSE        3//暂停播放
#define NET_DVR_PLAYRESTART      4//恢复播放（在暂停后调用将恢复暂停前的速度播放）
#define NET_DVR_PLAYFAST         5//快放
#define NET_DVR_PLAYSLOW         6//慢放
#define NET_DVR_PLAYNORMAL       7//正常速度播放
#define NET_DVR_PLAYFRAME        8//单帧放（恢复正常回放使用NET_DVR_PLAYNORMAL命令）
#define NET_DVR_PLAYSETPOS       12//改变文件回放的进度
#define NET_DVR_PLAYGETPOS       13//获取文件回放的进度
#define NET_DVR_PLAYGETTIME      14//获取当前已经播放的时间(按文件回放的时候有效)
#define NET_DVR_GETTOTALTIME     17//获取当前播放文件总的时间(按文件回放的时候有效)

typedef enum tagDeviceInformation//枚举数据库信息
{
	IP = Qt::UserRole + 1,
	Port = Qt::UserRole + 2,
	Username = Qt::UserRole + 3,
	Password = Qt::UserRole + 4,
	UserID = Qt::UserRole + 5,
	Channel = Qt::UserRole + 6,
	StruStartTime = Qt::UserRole + 7,
	StruStopTime = Qt::UserRole + 8
}DeviceInformation;

typedef enum tagCamaraChoose//枚举窗口选择信息
{
	CamaraOne = 1,
	CamaraTwo = 2,
	CamaraThree = 3,
	CamaraFour = 4
}CamaraChoose;

class CHikVisionMonitor : public QWidget
{
	Q_OBJECT

public:
	explicit CHikVisionMonitor(QWidget *parent = Q_NULLPTR);
public slots:
	//接收信号槽函数
	void getAddSignal();
	void getDeleteSignal(const int &iNum);
	void getModifySignal();
	void getLogoutSignal();
protected:
	//覆写虚函数实现全屏
	virtual bool eventFilter(QObject *obj, QEvent *event);
private:
	//槽函数
	void slotInit();
	//设置treeview节点
	void addMonitor();
	//回放参数设置
	void reviewStatusControl(const long &lStatus);
	//设置查找录像item
	void fineFileRes(const int &iUserID,const int &iChannel);
private:
	Ui::CHikVisionMonitorClass ui;
	CMonitorDatabase *m_pcDatabase{ nullptr };
	CDeviceInit *m_pcDeviceInit{ nullptr };
	QStandardItemModel* m_pPreviewModel{ nullptr };
	QStandardItemModel* m_pReviewModel{ nullptr };
	QStandardItemModel* m_pFindFileModel{ nullptr };
	int m_iChooseCamaraValue{ 1 };//区分摄像头四个窗口的标志位
	CMonitorDatabase::struSqliteData m_struItemInfo;
	long m_lreviewID{-1};
	QList<long>m_listlPreviewID{ 0,0,0,0 };//存放PreviewID
	QList<long>m_listlReviewID{ 0,0,0,0 };//存放reviewID
	QList<DWORD>m_listdwReviewPos{ 0,0,0,0 };
	QList<std::pair<long, long> >m_listlReviewInformation{std::make_pair(0,0),std::make_pair(0,0), std::make_pair(0,0), std::make_pair(0,0)};//存放userid对应的reviewID
	QSystemTrayIcon *m_systemTray{ nullptr };
	QMenu *m_menu{ nullptr };
	QMenu *m_capturePictureMenu{ nullptr };
	QMenu *m_findFileMenu{ nullptr };
	QAction *m_findFileAction{ nullptr };
	QAction *m_capturePictureAction{ nullptr };
	QAction *m_action1{ nullptr };
	QAction *m_action2{ nullptr };
	int m_iClickNum{ 0 };
	std::vector<NET_DVR_FINDDATA_V40> m_vecstruFindDataInfotmp;
	QTimer* m_pReviewPosTimer{ nullptr };

private slots:
	//点击打开设备管理界面
	void onClickedDeviceManagement();
	//点开设备报警界面
	void onClickedAlarmDevice();
	//点击停止预览
	void onClickedStopPreview();
	//点击停止回放
	void onClickedStopReview();
	//双击打开预览
	void onDoubleClickedOpenCamara(const QModelIndex &index = QModelIndex());
	//双击打开回放
	void onDoubleClickedReview(const QModelIndex &index = QModelIndex());
	//双击选中的文件打开回放
	void onDoubleClickedFileReview(const QModelIndex &index = QModelIndex());
	//调整回放进度
	//点击暂停回放
	void onClickedReviewPause();
	//点击恢复播放（暂停前的倍速）
	void onClickedRestart();
	//点击快放
	void onClickedReviewFast();
	//点击慢放
	void onClickedReviewSlow();
	//点击正常倍速播放
	void onClickedReviewNormal();
	//点击单帧播放
	void onClickedReviewSingleFrame();
	//点击选中一号窗口
	void onClickedChooseCamara1();
	//点击选中二号窗口
	void onClickedChooseCamara2();
	//点击选中三号窗口
	void onClickedChooseCamara3();
	//点击选中四号窗口
	void onClickedChooseCamara4();
	//点击打开回放页面
	void onClickedSelecetReviewPage();
	//点击打开预览页面
	void onClickedSelecetPreviewPage();
	//点击快进
	void onClickedStepOn();
	//点击快退
	void onClickedStepBack();
	//打开声音
	void onClickedSoundManage();
	//声音调控
	void soundMonitor(int isoundVal);
	//托盘操作
	void activeTray(QSystemTrayIcon::ActivationReason reason);
	//显示窗体
	void showWindow();
	//显示消息框
	void showMessage();
	//显示菜单
	void showMenu();
	//录像管理
	void onChangedStateVideo(const int &istate);
	//回放进度定时器刷新
	void timeOutReviewPos();
};
