/********************************************************************************
** Form generated from reading UI file 'CHikVisionMonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHIKVISIONMONITOR_H
#define UI_CHIKVISIONMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mylabel.h>
#include "Alarmdevice.h"
#include "cdevicemanagement.h"

QT_BEGIN_NAMESPACE

class Ui_CHikVisionMonitorClass
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *ReviewButton;
    QPushButton *PreviewButton;
    QPushButton *ManagementButton;
    QPushButton *alarmDeviceButton;
    QStackedWidget *stackedWidget;
    QWidget *PreviewPage;
    QGridLayout *gridLayout_9;
    QPushButton *StopPreviewButton;
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    CMyLabel *label;
    QFrame *frame_2;
    QGridLayout *gridLayout_6;
    CMyLabel *label_2;
    QFrame *frame_3;
    QGridLayout *gridLayout_7;
    CMyLabel *label_3;
    QFrame *frame_4;
    QGridLayout *gridLayout_8;
    CMyLabel *label_4;
    QCheckBox *videoCheckBox;
    QSlider *soundSlider;
    QPushButton *soundButton;
    QTreeView *treeView;
    QWidget *ReviewPage;
    QGridLayout *gridLayout_13;
    QLabel *TimeBeginLabel;
    QLabel *TimeEndLabel;
    QVBoxLayout *verticalLayout;
    QDateTimeEdit *BeginDateTimeEdit;
    QDateTimeEdit *EndDateTimeEdit;
    QGridLayout *gridLayout_12;
    QFrame *reviewFrame;
    QGridLayout *gridLayout_2;
    CMyLabel *ReviewLabel;
    QFrame *reviewFrame2;
    QGridLayout *gridLayout_5;
    CMyLabel *ReviewLabel_2;
    QFrame *reviewFrame3;
    QGridLayout *gridLayout_10;
    CMyLabel *ReviewLabel_3;
    QFrame *reviewFrame4;
    QGridLayout *gridLayout_11;
    CMyLabel *ReviewLabel_4;
    QTreeView *ReviewTreeView;
    QListView *reviewFilelistView;
    QHBoxLayout *horizontalLayout_4;
    CMyLabel *reviewStepBackLabel;
    QLabel *totalTimeLabel;
    CMyLabel *reviewStepOnLabel;
    QPushButton *stopButton;
    QPushButton *pauseButton;
    QPushButton *replayButton;
    QPushButton *slowPlayButton;
    QPushButton *quickPlayButton;
    QPushButton *normalPlayButton;
    QPushButton *singleFrameButton;
    CDeviceManagement *DeviceManagementPage;
    CAlarmDevice *AlarmDevicePage;

    void setupUi(QWidget *CHikVisionMonitorClass)
    {
        if (CHikVisionMonitorClass->objectName().isEmpty())
            CHikVisionMonitorClass->setObjectName(QStringLiteral("CHikVisionMonitorClass"));
        CHikVisionMonitorClass->resize(993, 745);
        CHikVisionMonitorClass->setAutoFillBackground(false);
        gridLayout_3 = new QGridLayout(CHikVisionMonitorClass);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ReviewButton = new QPushButton(CHikVisionMonitorClass);
        ReviewButton->setObjectName(QStringLiteral("ReviewButton"));

        horizontalLayout->addWidget(ReviewButton);

        PreviewButton = new QPushButton(CHikVisionMonitorClass);
        PreviewButton->setObjectName(QStringLiteral("PreviewButton"));

        horizontalLayout->addWidget(PreviewButton);

        ManagementButton = new QPushButton(CHikVisionMonitorClass);
        ManagementButton->setObjectName(QStringLiteral("ManagementButton"));

        horizontalLayout->addWidget(ManagementButton);

        alarmDeviceButton = new QPushButton(CHikVisionMonitorClass);
        alarmDeviceButton->setObjectName(QStringLiteral("alarmDeviceButton"));

        horizontalLayout->addWidget(alarmDeviceButton);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(CHikVisionMonitorClass);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setAutoFillBackground(true);
        PreviewPage = new QWidget();
        PreviewPage->setObjectName(QStringLiteral("PreviewPage"));
        gridLayout_9 = new QGridLayout(PreviewPage);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_9->setHorizontalSpacing(6);
        gridLayout_9->setVerticalSpacing(0);
        StopPreviewButton = new QPushButton(PreviewPage);
        StopPreviewButton->setObjectName(QStringLiteral("StopPreviewButton"));

        gridLayout_9->addWidget(StopPreviewButton, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, -1, 0);
        frame = new QFrame(PreviewPage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new CMyLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setAutoFillBackground(false);
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setWordWrap(false);
        label->setOpenExternalLinks(false);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        frame_2 = new QFrame(PreviewPage);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_2 = new CMyLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setMidLineWidth(0);

        gridLayout_6->addWidget(label_2, 0, 0, 1, 1);


        gridLayout->addWidget(frame_2, 0, 1, 1, 1);

        frame_3 = new QFrame(PreviewPage);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        label_3 = new CMyLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(label_3, 0, 0, 1, 1);


        gridLayout->addWidget(frame_3, 1, 0, 1, 1);

        frame_4 = new QFrame(PreviewPage);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_4);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        label_4 = new CMyLabel(frame_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFrameShape(QFrame::Box);
        label_4->setFrameShadow(QFrame::Sunken);
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_4->setMargin(0);
        label_4->setIndent(-1);
        label_4->setOpenExternalLinks(false);

        gridLayout_8->addWidget(label_4, 0, 0, 1, 1);


        gridLayout->addWidget(frame_4, 1, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout, 0, 1, 1, 4);

        videoCheckBox = new QCheckBox(PreviewPage);
        videoCheckBox->setObjectName(QStringLiteral("videoCheckBox"));

        gridLayout_9->addWidget(videoCheckBox, 1, 2, 1, 1);

        soundSlider = new QSlider(PreviewPage);
        soundSlider->setObjectName(QStringLiteral("soundSlider"));
        soundSlider->setMaximum(100);
        soundSlider->setSingleStep(5);
        soundSlider->setPageStep(5);
        soundSlider->setValue(50);
        soundSlider->setTracking(true);
        soundSlider->setOrientation(Qt::Horizontal);
        soundSlider->setInvertedAppearance(false);
        soundSlider->setTickPosition(QSlider::NoTicks);

        gridLayout_9->addWidget(soundSlider, 1, 4, 1, 1);

        soundButton = new QPushButton(PreviewPage);
        soundButton->setObjectName(QStringLiteral("soundButton"));

        gridLayout_9->addWidget(soundButton, 1, 3, 1, 1);

        treeView = new QTreeView(PreviewPage);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        treeView->setTextElideMode(Qt::ElideLeft);
        treeView->setAutoExpandDelay(-1);
        treeView->setIndentation(20);
        treeView->setUniformRowHeights(false);
        treeView->setItemsExpandable(true);
        treeView->setWordWrap(false);
        treeView->header()->setDefaultSectionSize(100);
        treeView->header()->setMinimumSectionSize(25);

        gridLayout_9->addWidget(treeView, 0, 0, 1, 1);

        gridLayout_9->setColumnStretch(1, 2);
        gridLayout_9->setColumnStretch(2, 2);
        gridLayout_9->setColumnStretch(3, 2);
        gridLayout_9->setColumnStretch(4, 2);
        stackedWidget->addWidget(PreviewPage);
        ReviewPage = new QWidget();
        ReviewPage->setObjectName(QStringLiteral("ReviewPage"));
        gridLayout_13 = new QGridLayout(ReviewPage);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        TimeBeginLabel = new QLabel(ReviewPage);
        TimeBeginLabel->setObjectName(QStringLiteral("TimeBeginLabel"));
        TimeBeginLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_13->addWidget(TimeBeginLabel, 0, 0, 1, 1);

        TimeEndLabel = new QLabel(ReviewPage);
        TimeEndLabel->setObjectName(QStringLiteral("TimeEndLabel"));
        TimeEndLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_13->addWidget(TimeEndLabel, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        BeginDateTimeEdit = new QDateTimeEdit(ReviewPage);
        BeginDateTimeEdit->setObjectName(QStringLiteral("BeginDateTimeEdit"));
        BeginDateTimeEdit->setDateTime(QDateTime(QDate(2021, 6, 15), QTime(0, 0, 0)));
        BeginDateTimeEdit->setCalendarPopup(true);

        verticalLayout->addWidget(BeginDateTimeEdit);

        EndDateTimeEdit = new QDateTimeEdit(ReviewPage);
        EndDateTimeEdit->setObjectName(QStringLiteral("EndDateTimeEdit"));
        EndDateTimeEdit->setDateTime(QDateTime(QDate(2021, 6, 16), QTime(15, 0, 0)));
        EndDateTimeEdit->setCalendarPopup(true);

        verticalLayout->addWidget(EndDateTimeEdit);


        gridLayout_13->addLayout(verticalLayout, 0, 1, 2, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        reviewFrame = new QFrame(ReviewPage);
        reviewFrame->setObjectName(QStringLiteral("reviewFrame"));
        reviewFrame->setFrameShape(QFrame::StyledPanel);
        reviewFrame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(reviewFrame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        ReviewLabel = new CMyLabel(reviewFrame);
        ReviewLabel->setObjectName(QStringLiteral("ReviewLabel"));
        ReviewLabel->setEnabled(true);
        ReviewLabel->setAutoFillBackground(false);
        ReviewLabel->setFrameShape(QFrame::Box);
        ReviewLabel->setFrameShadow(QFrame::Plain);
        ReviewLabel->setLineWidth(1);
        ReviewLabel->setTextFormat(Qt::AutoText);
        ReviewLabel->setScaledContents(false);
        ReviewLabel->setWordWrap(false);
        ReviewLabel->setOpenExternalLinks(false);

        gridLayout_2->addWidget(ReviewLabel, 0, 0, 1, 1);


        gridLayout_12->addWidget(reviewFrame, 0, 0, 1, 1);

        reviewFrame2 = new QFrame(ReviewPage);
        reviewFrame2->setObjectName(QStringLiteral("reviewFrame2"));
        reviewFrame2->setFrameShape(QFrame::StyledPanel);
        reviewFrame2->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(reviewFrame2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        ReviewLabel_2 = new CMyLabel(reviewFrame2);
        ReviewLabel_2->setObjectName(QStringLiteral("ReviewLabel_2"));
        ReviewLabel_2->setFrameShape(QFrame::Box);
        ReviewLabel_2->setFrameShadow(QFrame::Plain);
        ReviewLabel_2->setMidLineWidth(1);

        gridLayout_5->addWidget(ReviewLabel_2, 0, 0, 1, 1);


        gridLayout_12->addWidget(reviewFrame2, 0, 1, 1, 1);

        reviewFrame3 = new QFrame(ReviewPage);
        reviewFrame3->setObjectName(QStringLiteral("reviewFrame3"));
        reviewFrame3->setFrameShape(QFrame::StyledPanel);
        reviewFrame3->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(reviewFrame3);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        ReviewLabel_3 = new CMyLabel(reviewFrame3);
        ReviewLabel_3->setObjectName(QStringLiteral("ReviewLabel_3"));
        ReviewLabel_3->setFrameShape(QFrame::Box);

        gridLayout_10->addWidget(ReviewLabel_3, 0, 0, 1, 1);


        gridLayout_12->addWidget(reviewFrame3, 1, 0, 1, 1);

        reviewFrame4 = new QFrame(ReviewPage);
        reviewFrame4->setObjectName(QStringLiteral("reviewFrame4"));
        reviewFrame4->setFrameShape(QFrame::StyledPanel);
        reviewFrame4->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(reviewFrame4);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        ReviewLabel_4 = new CMyLabel(reviewFrame4);
        ReviewLabel_4->setObjectName(QStringLiteral("ReviewLabel_4"));
        ReviewLabel_4->setFrameShape(QFrame::Box);

        gridLayout_11->addWidget(ReviewLabel_4, 0, 0, 1, 1);


        gridLayout_12->addWidget(reviewFrame4, 1, 1, 1, 1);


        gridLayout_13->addLayout(gridLayout_12, 0, 2, 4, 1);

        ReviewTreeView = new QTreeView(ReviewPage);
        ReviewTreeView->setObjectName(QStringLiteral("ReviewTreeView"));

        gridLayout_13->addWidget(ReviewTreeView, 2, 0, 1, 2);

        reviewFilelistView = new QListView(ReviewPage);
        reviewFilelistView->setObjectName(QStringLiteral("reviewFilelistView"));

        gridLayout_13->addWidget(reviewFilelistView, 3, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        reviewStepBackLabel = new CMyLabel(ReviewPage);
        reviewStepBackLabel->setObjectName(QStringLiteral("reviewStepBackLabel"));
        reviewStepBackLabel->setPixmap(QPixmap(QString::fromUtf8(":/CHikVisionMonitor/Resources/stepback.png")));
        reviewStepBackLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(reviewStepBackLabel);

        totalTimeLabel = new QLabel(ReviewPage);
        totalTimeLabel->setObjectName(QStringLiteral("totalTimeLabel"));
        totalTimeLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(totalTimeLabel);

        reviewStepOnLabel = new CMyLabel(ReviewPage);
        reviewStepOnLabel->setObjectName(QStringLiteral("reviewStepOnLabel"));
        reviewStepOnLabel->setPixmap(QPixmap(QString::fromUtf8(":/CHikVisionMonitor/Resources/stepon.png")));

        horizontalLayout_4->addWidget(reviewStepOnLabel);

        stopButton = new QPushButton(ReviewPage);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        horizontalLayout_4->addWidget(stopButton);

        pauseButton = new QPushButton(ReviewPage);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        horizontalLayout_4->addWidget(pauseButton);

        replayButton = new QPushButton(ReviewPage);
        replayButton->setObjectName(QStringLiteral("replayButton"));

        horizontalLayout_4->addWidget(replayButton);

        slowPlayButton = new QPushButton(ReviewPage);
        slowPlayButton->setObjectName(QStringLiteral("slowPlayButton"));

        horizontalLayout_4->addWidget(slowPlayButton);

        quickPlayButton = new QPushButton(ReviewPage);
        quickPlayButton->setObjectName(QStringLiteral("quickPlayButton"));

        horizontalLayout_4->addWidget(quickPlayButton);

        normalPlayButton = new QPushButton(ReviewPage);
        normalPlayButton->setObjectName(QStringLiteral("normalPlayButton"));

        horizontalLayout_4->addWidget(normalPlayButton);

        singleFrameButton = new QPushButton(ReviewPage);
        singleFrameButton->setObjectName(QStringLiteral("singleFrameButton"));

        horizontalLayout_4->addWidget(singleFrameButton);


        gridLayout_13->addLayout(horizontalLayout_4, 4, 0, 1, 3);

        gridLayout_13->setColumnStretch(2, 10);
        stackedWidget->addWidget(ReviewPage);
        DeviceManagementPage = new CDeviceManagement();
        DeviceManagementPage->setObjectName(QStringLiteral("DeviceManagementPage"));
        stackedWidget->addWidget(DeviceManagementPage);
        AlarmDevicePage = new CAlarmDevice();
        AlarmDevicePage->setObjectName(QStringLiteral("AlarmDevicePage"));
        stackedWidget->addWidget(AlarmDevicePage);

        gridLayout_3->addWidget(stackedWidget, 1, 0, 1, 1);


        retranslateUi(CHikVisionMonitorClass);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(CHikVisionMonitorClass);
    } // setupUi

    void retranslateUi(QWidget *CHikVisionMonitorClass)
    {
        CHikVisionMonitorClass->setWindowTitle(QApplication::translate("CHikVisionMonitorClass", "CHikVisionMonitor", Q_NULLPTR));
        ReviewButton->setText(QApplication::translate("CHikVisionMonitorClass", "ReView", Q_NULLPTR));
        PreviewButton->setText(QApplication::translate("CHikVisionMonitorClass", "Preview", Q_NULLPTR));
        ManagementButton->setText(QApplication::translate("CHikVisionMonitorClass", "DeviceManagement", Q_NULLPTR));
        alarmDeviceButton->setText(QApplication::translate("CHikVisionMonitorClass", "AlarmDevice", Q_NULLPTR));
        StopPreviewButton->setText(QApplication::translate("CHikVisionMonitorClass", "StopPreview", Q_NULLPTR));
        label->setText(QApplication::translate("CHikVisionMonitorClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:600; font-style:italic;\">Camara</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("CHikVisionMonitorClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:600; font-style:italic;\">Camara</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("CHikVisionMonitorClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:600; font-style:italic;\">Camara</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("CHikVisionMonitorClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:600; font-style:italic;\">Camara</span></p></body></html>", Q_NULLPTR));
        videoCheckBox->setText(QString());
        soundButton->setText(QApplication::translate("CHikVisionMonitorClass", "OpenSound", Q_NULLPTR));
        TimeBeginLabel->setText(QApplication::translate("CHikVisionMonitorClass", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        TimeEndLabel->setText(QApplication::translate("CHikVisionMonitorClass", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        ReviewLabel->setText(QApplication::translate("CHikVisionMonitorClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:600; font-style:italic;\">Camara</span></p></body></html>", Q_NULLPTR));
        ReviewLabel_2->setText(QApplication::translate("CHikVisionMonitorClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:600; font-style:italic;\">Camara</span></p></body></html>", Q_NULLPTR));
        ReviewLabel_3->setText(QApplication::translate("CHikVisionMonitorClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:600; font-style:italic;\">Camara</span></p></body></html>", Q_NULLPTR));
        ReviewLabel_4->setText(QApplication::translate("CHikVisionMonitorClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:600; font-style:italic;\">Camara</span></p></body></html>", Q_NULLPTR));
        reviewStepBackLabel->setText(QString());
        totalTimeLabel->setText(QString());
        reviewStepOnLabel->setText(QString());
        stopButton->setText(QApplication::translate("CHikVisionMonitorClass", "stop", Q_NULLPTR));
        pauseButton->setText(QApplication::translate("CHikVisionMonitorClass", "pause", Q_NULLPTR));
        replayButton->setText(QApplication::translate("CHikVisionMonitorClass", "repaly", Q_NULLPTR));
        slowPlayButton->setText(QApplication::translate("CHikVisionMonitorClass", "slowplay", Q_NULLPTR));
        quickPlayButton->setText(QApplication::translate("CHikVisionMonitorClass", "quickplay", Q_NULLPTR));
        normalPlayButton->setText(QApplication::translate("CHikVisionMonitorClass", "normalplay", Q_NULLPTR));
        singleFrameButton->setText(QApplication::translate("CHikVisionMonitorClass", "singleframe", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CHikVisionMonitorClass: public Ui_CHikVisionMonitorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHIKVISIONMONITOR_H
