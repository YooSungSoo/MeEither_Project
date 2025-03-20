/********************************************************************************
** Form generated from reading UI file 'ChatRoomList.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOMLIST_H
#define UI_CHATROOMLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatRoomList
{
public:
    QLabel *headerLabel;
    QListWidget *chatRoomListWidget;
    QPushButton *createRoomButton;
    QPushButton *joinRoomButton;
    QTableWidget *userInfoTable;
    QPushButton *viewProfileButton;
    QListWidget *state;
    QLabel *continentLabel;
    QLabel *myInformation;

    void setupUi(QWidget *ChatRoomList)
    {
        if (ChatRoomList->objectName().isEmpty())
            ChatRoomList->setObjectName("ChatRoomList");
        ChatRoomList->resize(651, 548);
        headerLabel = new QLabel(ChatRoomList);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setGeometry(QRect(10, 20, 421, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setBold(true);
        headerLabel->setFont(font);
        headerLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        chatRoomListWidget = new QListWidget(ChatRoomList);
        chatRoomListWidget->setObjectName("chatRoomListWidget");
        chatRoomListWidget->setGeometry(QRect(20, 79, 400, 371));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(10);
        font1.setBold(true);
        chatRoomListWidget->setFont(font1);
        createRoomButton = new QPushButton(ChatRoomList);
        createRoomButton->setObjectName("createRoomButton");
        createRoomButton->setGeometry(QRect(20, 470, 200, 40));
        joinRoomButton = new QPushButton(ChatRoomList);
        joinRoomButton->setObjectName("joinRoomButton");
        joinRoomButton->setGeometry(QRect(240, 470, 180, 40));
        userInfoTable = new QTableWidget(ChatRoomList);
        if (userInfoTable->columnCount() < 3)
            userInfoTable->setColumnCount(3);
        userInfoTable->setObjectName("userInfoTable");
        userInfoTable->setGeometry(QRect(440, 80, 201, 371));
        userInfoTable->setColumnCount(3);
        userInfoTable->horizontalHeader()->setVisible(true);
        userInfoTable->horizontalHeader()->setMinimumSectionSize(23);
        userInfoTable->horizontalHeader()->setDefaultSectionSize(60);
        userInfoTable->horizontalHeader()->setHighlightSections(true);
        userInfoTable->verticalHeader()->setVisible(false);
        userInfoTable->verticalHeader()->setDefaultSectionSize(17);
        viewProfileButton = new QPushButton(ChatRoomList);
        viewProfileButton->setObjectName("viewProfileButton");
        viewProfileButton->setGeometry(QRect(450, 470, 180, 40));
        state = new QListWidget(ChatRoomList);
        state->setObjectName("state");
        state->setGeometry(QRect(440, 10, 201, 61));
        state->setFont(font1);
        continentLabel = new QLabel(ChatRoomList);
        continentLabel->setObjectName("continentLabel");
        continentLabel->setGeometry(QRect(460, 20, 171, 21));
        myInformation = new QLabel(ChatRoomList);
        myInformation->setObjectName("myInformation");
        myInformation->setGeometry(QRect(460, 40, 171, 21));

        retranslateUi(ChatRoomList);

        QMetaObject::connectSlotsByName(ChatRoomList);
    } // setupUi

    void retranslateUi(QWidget *ChatRoomList)
    {
        ChatRoomList->setWindowTitle(QCoreApplication::translate("ChatRoomList", "\354\261\204\355\214\205\353\260\251 \353\252\251\353\241\235", nullptr));
        ChatRoomList->setStyleSheet(QCoreApplication::translate("ChatRoomList", "\n"
"    QWidget {\n"
"        background-color: #f0f8ff;\n"
"        font-family: Arial, sans-serif;\n"
"    }\n"
"    QPushButton {\n"
"        background-color: #87ceeb;\n"
"        border: 1px solid #4682b4;\n"
"        border-radius: 8px;\n"
"        color: white;\n"
"        font-weight: bold;\n"
"        padding: 5px 10px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #4682b4;\n"
"    }\n"
"    QListWidget, QTableWidget {\n"
"        border: 1px solid #87ceeb;\n"
"        border-radius: 5px;\n"
"        padding: 5px;\n"
"    }\n"
"    QLabel {\n"
"        font-size: 14px;\n"
"        font-weight: bold;\n"
"        color: #4682b4;\n"
"    }\n"
"   ", nullptr));
        headerLabel->setText(QCoreApplication::translate("ChatRoomList", "\353\217\231\355\226\211 \354\260\276\352\270\260 \355\224\214\353\236\253\355\217\274 MeEither\354\227\220 \354\230\244\354\213\240 \352\262\203\354\235\204 \355\231\230\354\230\201\355\225\251\353\213\210\353\213\244!", nullptr));
        createRoomButton->setText(QCoreApplication::translate("ChatRoomList", "\354\261\204\355\214\205\353\260\251 \353\247\214\353\223\244\352\270\260", nullptr));
        joinRoomButton->setText(QCoreApplication::translate("ChatRoomList", "\354\261\204\355\214\205\353\260\251 \353\223\244\354\226\264\352\260\200\352\270\260", nullptr));
        userInfoTable->setStyleSheet(QCoreApplication::translate("ChatRoomList", "\n"
"     QTableWidget {\n"
"         background-color: #f9f9f9;\n"
"         border: 1px solid #87ceeb;\n"
"         border-radius: 5px;\n"
"         padding: 5px;\n"
"     }\n"
"    ", nullptr));
        userInfoTable->setProperty("horizontalHeaderLabels", QVariant(QStringList{
            QCoreApplication::translate("ChatRoomList", "\353\213\211\353\204\244\354\236\204", nullptr),
            QCoreApplication::translate("ChatRoomList", "\353\202\230\354\235\264", nullptr),
            QCoreApplication::translate("ChatRoomList", "\354\204\261\353\263\204", nullptr)}));
        viewProfileButton->setText(QCoreApplication::translate("ChatRoomList", "\355\224\204\353\241\234\355\225\204 \353\263\264\352\270\260", nullptr));
        continentLabel->setText(QCoreApplication::translate("ChatRoomList", "\353\214\200\353\245\231", nullptr));
        myInformation->setText(QCoreApplication::translate("ChatRoomList", "\354\240\221\354\206\215\354\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatRoomList: public Ui_ChatRoomList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOMLIST_H
