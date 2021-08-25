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

#define NET_DVR_PLAYSTART        1//��ʼ����
#define NET_DVR_PLAYPAUSE        3//��ͣ����
#define NET_DVR_PLAYRESTART      4//�ָ����ţ�����ͣ����ý��ָ���ͣǰ���ٶȲ��ţ�
#define NET_DVR_PLAYFAST         5//���
#define NET_DVR_PLAYSLOW         6//����
#define NET_DVR_PLAYNORMAL       7//�����ٶȲ���
#define NET_DVR_PLAYFRAME        8//��֡�ţ��ָ������ط�ʹ��NET_DVR_PLAYNORMAL���
#define NET_DVR_PLAYSETPOS       12//�ı��ļ��طŵĽ���
#define NET_DVR_PLAYGETPOS       13//��ȡ�ļ��طŵĽ���
#define NET_DVR_PLAYGETTIME      14//��ȡ��ǰ�Ѿ����ŵ�ʱ��(���ļ��طŵ�ʱ����Ч)
#define NET_DVR_GETTOTALTIME     17//��ȡ��ǰ�����ļ��ܵ�ʱ��(���ļ��طŵ�ʱ����Ч)

typedef enum tagDeviceInformation//ö�����ݿ���Ϣ
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

typedef enum tagCamaraChoose//ö�ٴ���ѡ����Ϣ
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
	//�����źŲۺ���
	void getAddSignal();
	void getDeleteSignal(const int &iNum);
	void getModifySignal();
	void getLogoutSignal();
protected:
	//��д�麯��ʵ��ȫ��
	virtual bool eventFilter(QObject *obj, QEvent *event);
private:
	//�ۺ���
	void slotInit();
	//����treeview�ڵ�
	void addMonitor();
	//�طŲ�������
	void reviewStatusControl(const long &lStatus);
	//���ò���¼��item
	void fineFileRes(const int &iUserID,const int &iChannel);
private:
	Ui::CHikVisionMonitorClass ui;
	CMonitorDatabase *m_pcDatabase{ nullptr };
	CDeviceInit *m_pcDeviceInit{ nullptr };
	QStandardItemModel* m_pPreviewModel{ nullptr };
	QStandardItemModel* m_pReviewModel{ nullptr };
	QStandardItemModel* m_pFindFileModel{ nullptr };
	int m_iChooseCamaraValue{ 1 };//��������ͷ�ĸ����ڵı�־λ
	CMonitorDatabase::struSqliteData m_struItemInfo;
	long m_lreviewID{-1};
	QList<long>m_listlPreviewID{ 0,0,0,0 };//���PreviewID
	QList<long>m_listlReviewID{ 0,0,0,0 };//���reviewID
	QList<DWORD>m_listdwReviewPos{ 0,0,0,0 };
	QList<std::pair<long, long> >m_listlReviewInformation{std::make_pair(0,0),std::make_pair(0,0), std::make_pair(0,0), std::make_pair(0,0)};//���userid��Ӧ��reviewID
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
	//������豸�������
	void onClickedDeviceManagement();
	//�㿪�豸��������
	void onClickedAlarmDevice();
	//���ֹͣԤ��
	void onClickedStopPreview();
	//���ֹͣ�ط�
	void onClickedStopReview();
	//˫����Ԥ��
	void onDoubleClickedOpenCamara(const QModelIndex &index = QModelIndex());
	//˫���򿪻ط�
	void onDoubleClickedReview(const QModelIndex &index = QModelIndex());
	//˫��ѡ�е��ļ��򿪻ط�
	void onDoubleClickedFileReview(const QModelIndex &index = QModelIndex());
	//�����طŽ���
	//�����ͣ�ط�
	void onClickedReviewPause();
	//����ָ����ţ���ͣǰ�ı��٣�
	void onClickedRestart();
	//������
	void onClickedReviewFast();
	//�������
	void onClickedReviewSlow();
	//����������ٲ���
	void onClickedReviewNormal();
	//�����֡����
	void onClickedReviewSingleFrame();
	//���ѡ��һ�Ŵ���
	void onClickedChooseCamara1();
	//���ѡ�ж��Ŵ���
	void onClickedChooseCamara2();
	//���ѡ�����Ŵ���
	void onClickedChooseCamara3();
	//���ѡ���ĺŴ���
	void onClickedChooseCamara4();
	//����򿪻ط�ҳ��
	void onClickedSelecetReviewPage();
	//�����Ԥ��ҳ��
	void onClickedSelecetPreviewPage();
	//������
	void onClickedStepOn();
	//�������
	void onClickedStepBack();
	//������
	void onClickedSoundManage();
	//��������
	void soundMonitor(int isoundVal);
	//���̲���
	void activeTray(QSystemTrayIcon::ActivationReason reason);
	//��ʾ����
	void showWindow();
	//��ʾ��Ϣ��
	void showMessage();
	//��ʾ�˵�
	void showMenu();
	//¼�����
	void onChangedStateVideo(const int &istate);
	//�طŽ��ȶ�ʱ��ˢ��
	void timeOutReviewPos();
};
