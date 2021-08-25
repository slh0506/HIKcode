/********************************************************************************
** Form generated from reading UI file 'CAlarmDevice.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALARMDEVICE_H
#define UI_CALARMDEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CAlarmDevice
{
public:
    QWidget *alarmerInfoWidget;
    QTableView *alarmerInfoTableView;
    QPushButton *exitButton;
    QGridLayout *gridLayout;
    QTableView *alarmTableView;
    QPushButton *SetupAlarmChanButton;
    QPushButton *CloseAlarmChanButton;
    QPushButton *StartListenButton;
    QPushButton *StopListenButton;

    void setupUi(QWidget *CAlarmDevice)
    {
        if (CAlarmDevice->objectName().isEmpty())
            CAlarmDevice->setObjectName(QStringLiteral("CAlarmDevice"));
        CAlarmDevice->resize(949, 658);
        alarmerInfoWidget = new QWidget(CAlarmDevice);
        alarmerInfoWidget->setObjectName(QStringLiteral("alarmerInfoWidget"));
        alarmerInfoWidget->setGeometry(QRect(157, 95, 681, 391));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(164, 169, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(209, 212, 247, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(82, 84, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(109, 113, 160, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        alarmerInfoWidget->setPalette(palette);
        alarmerInfoWidget->setAutoFillBackground(true);
        alarmerInfoTableView = new QTableView(alarmerInfoWidget);
        alarmerInfoTableView->setObjectName(QStringLiteral("alarmerInfoTableView"));
        alarmerInfoTableView->setGeometry(QRect(120, 60, 481, 192));
        exitButton = new QPushButton(alarmerInfoWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(600, 0, 75, 23));
        gridLayout = new QGridLayout(CAlarmDevice);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        alarmTableView = new QTableView(CAlarmDevice);
        alarmTableView->setObjectName(QStringLiteral("alarmTableView"));

        gridLayout->addWidget(alarmTableView, 0, 0, 1, 4);

        SetupAlarmChanButton = new QPushButton(CAlarmDevice);
        SetupAlarmChanButton->setObjectName(QStringLiteral("SetupAlarmChanButton"));

        gridLayout->addWidget(SetupAlarmChanButton, 1, 0, 1, 1);

        CloseAlarmChanButton = new QPushButton(CAlarmDevice);
        CloseAlarmChanButton->setObjectName(QStringLiteral("CloseAlarmChanButton"));

        gridLayout->addWidget(CloseAlarmChanButton, 1, 1, 1, 1);

        StartListenButton = new QPushButton(CAlarmDevice);
        StartListenButton->setObjectName(QStringLiteral("StartListenButton"));

        gridLayout->addWidget(StartListenButton, 1, 2, 1, 1);

        StopListenButton = new QPushButton(CAlarmDevice);
        StopListenButton->setObjectName(QStringLiteral("StopListenButton"));

        gridLayout->addWidget(StopListenButton, 1, 3, 1, 1);


        retranslateUi(CAlarmDevice);

        QMetaObject::connectSlotsByName(CAlarmDevice);
    } // setupUi

    void retranslateUi(QWidget *CAlarmDevice)
    {
        CAlarmDevice->setWindowTitle(QApplication::translate("CAlarmDevice", "CAlarmDevice", Q_NULLPTR));
        exitButton->setText(QApplication::translate("CAlarmDevice", "exit", Q_NULLPTR));
        SetupAlarmChanButton->setText(QApplication::translate("CAlarmDevice", "SetupAlarmChan", Q_NULLPTR));
        CloseAlarmChanButton->setText(QApplication::translate("CAlarmDevice", "CloseAlarmChan", Q_NULLPTR));
        StartListenButton->setText(QApplication::translate("CAlarmDevice", "StartListen", Q_NULLPTR));
        StopListenButton->setText(QApplication::translate("CAlarmDevice", "StopListen", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CAlarmDevice: public Ui_CAlarmDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALARMDEVICE_H
