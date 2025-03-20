/********************************************************************************
** Form generated from reading UI file 'ChatWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QWidget *centralwidget;
    QListWidget *chatMessagesList;
    QLineEdit *messageLineEdit;
    QPushButton *sendButton;
    QListWidget *userListWidget;
    QPushButton *leaveRoomButton;
    QLabel *headerLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName("ChatWindow");
        ChatWindow->resize(600, 500);
        centralwidget = new QWidget(ChatWindow);
        centralwidget->setObjectName("centralwidget");
        chatMessagesList = new QListWidget(centralwidget);
        chatMessagesList->setObjectName("chatMessagesList");
        chatMessagesList->setGeometry(QRect(10, 60, 450, 350));
        messageLineEdit = new QLineEdit(centralwidget);
        messageLineEdit->setObjectName("messageLineEdit");
        messageLineEdit->setGeometry(QRect(10, 420, 450, 40));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(470, 420, 120, 40));
        userListWidget = new QListWidget(centralwidget);
        userListWidget->setObjectName("userListWidget");
        userListWidget->setGeometry(QRect(470, 59, 120, 301));
        leaveRoomButton = new QPushButton(centralwidget);
        leaveRoomButton->setObjectName("leaveRoomButton");
        leaveRoomButton->setGeometry(QRect(470, 370, 120, 40));
        headerLabel = new QLabel(centralwidget);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setGeometry(QRect(10, 10, 581, 41));
        QFont font;
        font.setPointSize(16);
        headerLabel->setFont(font);
        headerLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ChatWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChatWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 20));
        ChatWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChatWindow);
        statusbar->setObjectName("statusbar");
        ChatWindow->setStatusBar(statusbar);

        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChatWindow)
    {
        ChatWindow->setWindowTitle(QCoreApplication::translate("ChatWindow", "\354\261\204\355\214\205\353\260\251", nullptr));
        ChatWindow->setStyleSheet(QCoreApplication::translate("ChatWindow", "\n"
"    QMainWindow {\n"
"        background-color: #f2f4f9;  /* \355\214\214\354\212\244\355\205\224\355\206\244 \353\260\260\352\262\275\354\203\211 (\354\227\260\355\225\234 \355\214\214\354\212\244\355\205\224 \353\270\224\353\243\250) */\n"
"    }\n"
"    QPushButton {\n"
"        background-color: #7cb5e8;  /* \355\214\214\354\212\244\355\205\224 \353\270\224\353\243\250 \353\262\204\355\212\274 */\n"
"        border: 1px solid #4c8bf5;\n"
"        border-radius: 8px;\n"
"        color: white;\n"
"        font-weight: bold;\n"
"        padding: 10px;\n"
"        font-size: 14px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #4c8bf5;  /* \353\247\210\354\232\260\354\212\244\353\245\274 \354\230\254\353\240\270\354\235\204 \353\225\214 \355\214\214\354\212\244\355\205\224 \353\270\224\353\243\250\354\227\220\354\204\234 \354\241\260\352\270\210 \353\215\224 \354\247\204\355\225\234 \355\214\214\353\236\200\354\203\211\354\234\274\353\241\234 \353\263\200\352\262\275 */\n"
"    }\n"
""
                        "    QLineEdit {\n"
"        border: 1px solid #b5c9e2;  /* \353\260\235\354\235\200 \355\214\214\354\212\244\355\205\224 \353\270\224\353\243\250 \355\205\214\353\221\220\353\246\254 */\n"
"        border-radius: 5px;\n"
"        padding: 10px;\n"
"        font-size: 14px;\n"
"        background-color: #ffffff;  /* \355\235\260\354\203\211 \353\260\260\352\262\275 */\n"
"    }\n"
"    QListWidget {\n"
"        background-color: #ffffff;  /* \354\261\204\355\214\205 \353\251\224\354\213\234\354\247\200 \353\246\254\354\212\244\355\212\270 \353\260\260\352\262\275\354\203\211 \355\235\260\354\203\211 */\n"
"        border: 1px solid #b5c9e2;  /* \355\214\214\354\212\244\355\205\224 \353\270\224\353\243\250 \355\205\214\353\221\220\353\246\254 */\n"
"        border-radius: 5px;\n"
"        padding: 10px;\n"
"        font-size: 14px;\n"
"        color: #333;  /* \355\205\215\354\212\244\355\212\270 \354\203\211\354\203\201\354\235\200 \354\226\264\353\221\220\354\232\264 \355\232\214\354\203\211 */\n"
"    }\n"
" "
                        "   QListWidget::item {\n"
"        padding: 8px;\n"
"        border-bottom: 1px solid #f2f4f9;  /* \355\225\255\353\252\251 \352\260\204 \352\265\254\353\266\204\354\204\240 \354\203\211\354\203\201 */\n"
"    }\n"
"    QListWidget::item:selected {\n"
"        background-color: #7cb5e8;  /* \355\225\255\353\252\251 \354\204\240\355\203\235 \354\213\234 \355\214\214\354\212\244\355\205\224 \353\270\224\353\243\250 */\n"
"        color: white;\n"
"    }\n"
"    QLabel {\n"
"        font-size: 16px;\n"
"        font-weight: bold;\n"
"        color: #333;\n"
"    }\n"
"    QMenuBar {\n"
"        background-color: #f2f4f9;  /* \353\251\224\353\211\264 \353\260\224 \353\260\260\352\262\275\354\203\211 */\n"
"        color: #333;\n"
"    }\n"
"    QStatusBar {\n"
"        background-color: #f2f4f9;  /* \354\203\201\355\203\234 \353\260\224 \353\260\260\352\262\275\354\203\211 */\n"
"    }\n"
"   ", nullptr));
        messageLineEdit->setPlaceholderText(QCoreApplication::translate("ChatWindow", "\353\251\224\354\213\234\354\247\200\353\245\274 \354\236\205\353\240\245\355\225\230\354\204\270\354\232\224...", nullptr));
        sendButton->setText(QCoreApplication::translate("ChatWindow", "\354\240\204\354\206\241", nullptr));
        userListWidget->setStyleSheet(QCoreApplication::translate("ChatWindow", "\n"
"      QListWidget {\n"
"          background-color: #f9f9f9;  /* \354\202\254\354\232\251\354\236\220 \353\252\251\353\241\235 \353\260\260\352\262\275 (\353\260\235\354\235\200 \355\232\214\354\203\211) */\n"
"          border: 1px solid #b5c9e2;  /* \355\214\214\354\212\244\355\205\224 \353\270\224\353\243\250 \355\205\214\353\221\220\353\246\254 */\n"
"          border-radius: 5px;\n"
"          font-size: 14px;\n"
"      }\n"
"      QListWidget::item {\n"
"          padding: 8px;\n"
"      }\n"
"      QListWidget::item:selected {\n"
"          background-color: #7cb5e8;  /* \354\204\240\355\203\235 \354\213\234 \355\214\214\354\212\244\355\205\224 \353\270\224\353\243\250 */\n"
"          color: white;\n"
"      }\n"
"     ", nullptr));
        leaveRoomButton->setText(QCoreApplication::translate("ChatWindow", "\354\261\204\355\214\205\353\260\251 \353\202\230\352\260\200\352\270\260", nullptr));
        headerLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
