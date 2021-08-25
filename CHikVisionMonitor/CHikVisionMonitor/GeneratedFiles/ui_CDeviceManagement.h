/********************************************************************************
** Form generated from reading UI file 'CDeviceManagement.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDEVICEMANAGEMENT_H
#define UI_CDEVICEMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDeviceManagement
{
public:
    QGridLayout *gridLayout_5;
    QWidget *ModifyWidget;
    QPushButton *ModifyExitButton;
    QSplitter *splitter_3;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *ModifyIPlabel;
    QLineEdit *ModifyIPLineEdit;
    QLabel *ModifyPortlabel;
    QLineEdit *ModifyPortLineEdit;
    QLabel *ModifyUsernamelabel;
    QLineEdit *ModifyUsernameLineEdit;
    QLabel *ModifyPasswordlabel;
    QLineEdit *ModifyPasswordLineEdit;
    QSplitter *splitter_4;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_4;
    QPushButton *ModifyCheckButton;
    QPushButton *ModifyCancelButton;
    QWidget *addWidget;
    QPushButton *ExitButton;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *IPlabel;
    QLineEdit *IPLineEdit;
    QLabel *Portlabel;
    QLineEdit *PortLineEdit;
    QLabel *Usernamelabel;
    QLineEdit *UsernameLineEdit;
    QLabel *Passwordlabel;
    QLineEdit *PasswordLineEdit;
    QSplitter *splitter_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QPushButton *LoginButton;
    QPushButton *LogoutButton;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *AddButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *DeleteButton;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *CDeviceManagement)
    {
        if (CDeviceManagement->objectName().isEmpty())
            CDeviceManagement->setObjectName(QStringLiteral("CDeviceManagement"));
        CDeviceManagement->resize(853, 565);
        gridLayout_5 = new QGridLayout(CDeviceManagement);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        ModifyWidget = new QWidget(CDeviceManagement);
        ModifyWidget->setObjectName(QStringLiteral("ModifyWidget"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(148, 150, 190, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(229, 230, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(188, 190, 222, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(74, 75, 95, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(99, 100, 127, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(201, 202, 222, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        ModifyWidget->setPalette(palette);
        ModifyWidget->setAutoFillBackground(true);
        ModifyWidget->setStyleSheet(QLatin1String("enum Shape {\n"
"	Box = 0x0001\n"
"};"));
        ModifyExitButton = new QPushButton(ModifyWidget);
        ModifyExitButton->setObjectName(QStringLiteral("ModifyExitButton"));
        ModifyExitButton->setGeometry(QRect(610, 0, 75, 23));
        splitter_3 = new QSplitter(ModifyWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(120, 70, 431, 241));
        splitter_3->setOrientation(Qt::Horizontal);
        layoutWidget_2 = new QWidget(splitter_3);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        gridLayout_3 = new QGridLayout(layoutWidget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        ModifyIPlabel = new QLabel(layoutWidget_2);
        ModifyIPlabel->setObjectName(QStringLiteral("ModifyIPlabel"));

        gridLayout_3->addWidget(ModifyIPlabel, 0, 0, 1, 1);

        ModifyIPLineEdit = new QLineEdit(layoutWidget_2);
        ModifyIPLineEdit->setObjectName(QStringLiteral("ModifyIPLineEdit"));

        gridLayout_3->addWidget(ModifyIPLineEdit, 0, 1, 1, 1);

        ModifyPortlabel = new QLabel(layoutWidget_2);
        ModifyPortlabel->setObjectName(QStringLiteral("ModifyPortlabel"));

        gridLayout_3->addWidget(ModifyPortlabel, 1, 0, 1, 1);

        ModifyPortLineEdit = new QLineEdit(layoutWidget_2);
        ModifyPortLineEdit->setObjectName(QStringLiteral("ModifyPortLineEdit"));

        gridLayout_3->addWidget(ModifyPortLineEdit, 1, 1, 1, 1);

        ModifyUsernamelabel = new QLabel(layoutWidget_2);
        ModifyUsernamelabel->setObjectName(QStringLiteral("ModifyUsernamelabel"));

        gridLayout_3->addWidget(ModifyUsernamelabel, 2, 0, 1, 1);

        ModifyUsernameLineEdit = new QLineEdit(layoutWidget_2);
        ModifyUsernameLineEdit->setObjectName(QStringLiteral("ModifyUsernameLineEdit"));

        gridLayout_3->addWidget(ModifyUsernameLineEdit, 2, 1, 1, 1);

        ModifyPasswordlabel = new QLabel(layoutWidget_2);
        ModifyPasswordlabel->setObjectName(QStringLiteral("ModifyPasswordlabel"));

        gridLayout_3->addWidget(ModifyPasswordlabel, 3, 0, 1, 1);

        ModifyPasswordLineEdit = new QLineEdit(layoutWidget_2);
        ModifyPasswordLineEdit->setObjectName(QStringLiteral("ModifyPasswordLineEdit"));

        gridLayout_3->addWidget(ModifyPasswordLineEdit, 3, 1, 1, 1);

        splitter_3->addWidget(layoutWidget_2);
        splitter_4 = new QSplitter(ModifyWidget);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setGeometry(QRect(120, 350, 431, 54));
        splitter_4->setOrientation(Qt::Horizontal);
        layoutWidget_3 = new QWidget(splitter_4);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        gridLayout_4 = new QGridLayout(layoutWidget_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        ModifyCheckButton = new QPushButton(layoutWidget_3);
        ModifyCheckButton->setObjectName(QStringLiteral("ModifyCheckButton"));

        gridLayout_4->addWidget(ModifyCheckButton, 0, 0, 1, 1);

        ModifyCancelButton = new QPushButton(layoutWidget_3);
        ModifyCancelButton->setObjectName(QStringLiteral("ModifyCancelButton"));

        gridLayout_4->addWidget(ModifyCancelButton, 0, 1, 1, 1);

        splitter_4->addWidget(layoutWidget_3);

        gridLayout_5->addWidget(ModifyWidget, 0, 0, 2, 2);

        addWidget = new QWidget(CDeviceManagement);
        addWidget->setObjectName(QStringLiteral("addWidget"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        addWidget->setPalette(palette1);
        addWidget->setAutoFillBackground(true);
        ExitButton = new QPushButton(addWidget);
        ExitButton->setObjectName(QStringLiteral("ExitButton"));
        ExitButton->setGeometry(QRect(640, 0, 75, 23));
        splitter = new QSplitter(addWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(140, 70, 431, 241));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        IPlabel = new QLabel(layoutWidget);
        IPlabel->setObjectName(QStringLiteral("IPlabel"));

        gridLayout->addWidget(IPlabel, 0, 0, 1, 1);

        IPLineEdit = new QLineEdit(layoutWidget);
        IPLineEdit->setObjectName(QStringLiteral("IPLineEdit"));

        gridLayout->addWidget(IPLineEdit, 0, 1, 1, 1);

        Portlabel = new QLabel(layoutWidget);
        Portlabel->setObjectName(QStringLiteral("Portlabel"));

        gridLayout->addWidget(Portlabel, 1, 0, 1, 1);

        PortLineEdit = new QLineEdit(layoutWidget);
        PortLineEdit->setObjectName(QStringLiteral("PortLineEdit"));

        gridLayout->addWidget(PortLineEdit, 1, 1, 1, 1);

        Usernamelabel = new QLabel(layoutWidget);
        Usernamelabel->setObjectName(QStringLiteral("Usernamelabel"));

        gridLayout->addWidget(Usernamelabel, 2, 0, 1, 1);

        UsernameLineEdit = new QLineEdit(layoutWidget);
        UsernameLineEdit->setObjectName(QStringLiteral("UsernameLineEdit"));

        gridLayout->addWidget(UsernameLineEdit, 2, 1, 1, 1);

        Passwordlabel = new QLabel(layoutWidget);
        Passwordlabel->setObjectName(QStringLiteral("Passwordlabel"));

        gridLayout->addWidget(Passwordlabel, 3, 0, 1, 1);

        PasswordLineEdit = new QLineEdit(layoutWidget);
        PasswordLineEdit->setObjectName(QStringLiteral("PasswordLineEdit"));

        gridLayout->addWidget(PasswordLineEdit, 3, 1, 1, 1);

        splitter->addWidget(layoutWidget);
        splitter_2 = new QSplitter(addWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(140, 350, 431, 54));
        splitter_2->setOrientation(Qt::Horizontal);
        layoutWidget1 = new QWidget(splitter_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        LoginButton = new QPushButton(layoutWidget1);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));

        gridLayout_2->addWidget(LoginButton, 0, 0, 1, 1);

        LogoutButton = new QPushButton(layoutWidget1);
        LogoutButton->setObjectName(QStringLiteral("LogoutButton"));

        gridLayout_2->addWidget(LogoutButton, 0, 1, 1, 1);

        splitter_2->addWidget(layoutWidget1);

        gridLayout_5->addWidget(addWidget, 1, 1, 1, 1);

        tableView = new QTableView(CDeviceManagement);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout_5->addWidget(tableView, 2, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        AddButton = new QPushButton(CDeviceManagement);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddButton->sizePolicy().hasHeightForWidth());
        AddButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(AddButton);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        DeleteButton = new QPushButton(CDeviceManagement);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));
        sizePolicy.setHeightForWidth(DeleteButton->sizePolicy().hasHeightForWidth());
        DeleteButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(DeleteButton);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout_5->addLayout(horizontalLayout, 4, 0, 1, 2);

        layoutWidget->raise();
        tableView->raise();
        addWidget->raise();
        ModifyWidget->raise();

        retranslateUi(CDeviceManagement);

        QMetaObject::connectSlotsByName(CDeviceManagement);
    } // setupUi

    void retranslateUi(QWidget *CDeviceManagement)
    {
        CDeviceManagement->setWindowTitle(QApplication::translate("CDeviceManagement", "CDeviceManagement", Q_NULLPTR));
        ModifyExitButton->setText(QApplication::translate("CDeviceManagement", "Exit", Q_NULLPTR));
        ModifyIPlabel->setText(QApplication::translate("CDeviceManagement", "IP\357\274\232", Q_NULLPTR));
        ModifyPortlabel->setText(QApplication::translate("CDeviceManagement", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        ModifyUsernamelabel->setText(QApplication::translate("CDeviceManagement", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        ModifyPasswordlabel->setText(QApplication::translate("CDeviceManagement", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        ModifyCheckButton->setText(QApplication::translate("CDeviceManagement", "Modify", Q_NULLPTR));
        ModifyCancelButton->setText(QApplication::translate("CDeviceManagement", "Cancel", Q_NULLPTR));
        ExitButton->setText(QApplication::translate("CDeviceManagement", "Exit", Q_NULLPTR));
        IPlabel->setText(QApplication::translate("CDeviceManagement", "IP\357\274\232", Q_NULLPTR));
        Portlabel->setText(QApplication::translate("CDeviceManagement", "\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        Usernamelabel->setText(QApplication::translate("CDeviceManagement", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        Passwordlabel->setText(QApplication::translate("CDeviceManagement", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        LoginButton->setText(QApplication::translate("CDeviceManagement", "Login", Q_NULLPTR));
        LogoutButton->setText(QApplication::translate("CDeviceManagement", "Logout", Q_NULLPTR));
        AddButton->setText(QApplication::translate("CDeviceManagement", "DeviceAdd", Q_NULLPTR));
        DeleteButton->setText(QApplication::translate("CDeviceManagement", "Delete", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CDeviceManagement: public Ui_CDeviceManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDEVICEMANAGEMENT_H
