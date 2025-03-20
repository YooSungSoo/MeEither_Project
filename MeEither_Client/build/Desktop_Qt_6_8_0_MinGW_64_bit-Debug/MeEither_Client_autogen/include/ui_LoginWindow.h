/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLabel *headerLabel;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QPushButton *signUpButton;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(400, 260);
        headerLabel = new QLabel(LoginWindow);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setGeometry(QRect(100, 20, 200, 40));
        headerLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        usernameLineEdit = new QLineEdit(LoginWindow);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(100, 80, 200, 30));
        passwordLineEdit = new QLineEdit(LoginWindow);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(100, 120, 200, 30));
        passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        loginButton = new QPushButton(LoginWindow);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(100, 160, 90, 30));
        signUpButton = new QPushButton(LoginWindow);
        signUpButton->setObjectName("signUpButton");
        signUpButton->setGeometry(QRect(210, 160, 90, 30));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MeEither - \353\241\234\352\267\270\354\235\270", nullptr));
        LoginWindow->setStyleSheet(QCoreApplication::translate("LoginWindow", "\n"
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
"    QLineEdit {\n"
"        border: 1px solid #87ceeb;\n"
"        border-radius: 5px;\n"
"        padding: 5px;\n"
"    }\n"
"   ", nullptr));
        headerLabel->setStyleSheet(QCoreApplication::translate("LoginWindow", "\n"
"     QLabel {\n"
"         font-size: 24px;\n"
"         font-weight: bold;\n"
"         color: #4682b4;\n"
"     }\n"
"    ", nullptr));
        headerLabel->setText(QCoreApplication::translate("LoginWindow", "MeEither", nullptr));
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\354\225\204\354\235\264\353\224\224 \354\236\205\353\240\245", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\353\271\204\353\260\200\353\262\210\355\230\270 \354\236\205\353\240\245", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "\353\241\234\352\267\270\354\235\270", nullptr));
        signUpButton->setText(QCoreApplication::translate("LoginWindow", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
