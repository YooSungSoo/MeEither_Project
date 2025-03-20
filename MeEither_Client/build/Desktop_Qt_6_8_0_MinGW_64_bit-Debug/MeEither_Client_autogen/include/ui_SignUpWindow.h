/********************************************************************************
** Form generated from reading UI file 'SignUpWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpWindow
{
public:
    QLabel *headerLabel;
    QLineEdit *usernameLineEdit;
    QPushButton *conform;
    QLineEdit *passwordLineEdit;
    QLineEdit *nickName;
    QDateEdit *birthDateEdit;
    QGroupBox *genderGroupBox;
    QRadioButton *checkBoxM;
    QRadioButton *checkBoxF;
    QPushButton *signUpButton;
    QGroupBox *preferContry;
    QCheckBox *northEU;
    QCheckBox *westEU;
    QCheckBox *centralAsia;
    QCheckBox *eastsouthAsia;
    QCheckBox *eastEU;
    QCheckBox *northAmerica;
    QCheckBox *southAmerica;
    QCheckBox *africa;
    QCheckBox *oseania;
    QCheckBox *arctic;
    QCheckBox *antArctic;
    QCheckBox *eastAsia;
    QGroupBox *travelStyle;
    QCheckBox *rest;
    QCheckBox *cityRest;
    QCheckBox *shopping;
    QCheckBox *foodSearch;
    QCheckBox *activity;
    QCheckBox *cultureLife;
    QCheckBox *leisurely;
    QCheckBox *busy;
    QCheckBox *trifity;
    QCheckBox *luxury;
    QCheckBox *sports;
    QCheckBox *nature;
    QGroupBox *MBTI;
    QComboBox *comboBox;

    void setupUi(QWidget *SignUpWindow)
    {
        if (SignUpWindow->objectName().isEmpty())
            SignUpWindow->setObjectName("SignUpWindow");
        SignUpWindow->resize(471, 724);
        headerLabel = new QLabel(SignUpWindow);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setGeometry(QRect(100, 20, 250, 40));
        headerLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        usernameLineEdit = new QLineEdit(SignUpWindow);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(100, 80, 250, 30));
        conform = new QPushButton(SignUpWindow);
        conform->setObjectName("conform");
        conform->setGeometry(QRect(360, 80, 80, 30));
        passwordLineEdit = new QLineEdit(SignUpWindow);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(100, 130, 250, 30));
        passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);
        nickName = new QLineEdit(SignUpWindow);
        nickName->setObjectName("nickName");
        nickName->setGeometry(QRect(100, 180, 250, 30));
        birthDateEdit = new QDateEdit(SignUpWindow);
        birthDateEdit->setObjectName("birthDateEdit");
        birthDateEdit->setGeometry(QRect(100, 230, 250, 30));
        genderGroupBox = new QGroupBox(SignUpWindow);
        genderGroupBox->setObjectName("genderGroupBox");
        genderGroupBox->setGeometry(QRect(80, 280, 151, 61));
        checkBoxM = new QRadioButton(genderGroupBox);
        checkBoxM->setObjectName("checkBoxM");
        checkBoxM->setGeometry(QRect(20, 20, 100, 20));
        checkBoxF = new QRadioButton(genderGroupBox);
        checkBoxF->setObjectName("checkBoxF");
        checkBoxF->setGeometry(QRect(80, 20, 61, 20));
        signUpButton = new QPushButton(SignUpWindow);
        signUpButton->setObjectName("signUpButton");
        signUpButton->setGeometry(QRect(190, 670, 100, 40));
        preferContry = new QGroupBox(SignUpWindow);
        preferContry->setObjectName("preferContry");
        preferContry->setGeometry(QRect(80, 360, 311, 141));
        northEU = new QCheckBox(preferContry);
        northEU->setObjectName("northEU");
        northEU->setGeometry(QRect(20, 20, 64, 18));
        westEU = new QCheckBox(preferContry);
        westEU->setObjectName("westEU");
        westEU->setGeometry(QRect(120, 20, 64, 18));
        centralAsia = new QCheckBox(preferContry);
        centralAsia->setObjectName("centralAsia");
        centralAsia->setGeometry(QRect(20, 50, 91, 18));
        eastsouthAsia = new QCheckBox(preferContry);
        eastsouthAsia->setObjectName("eastsouthAsia");
        eastsouthAsia->setGeometry(QRect(120, 50, 91, 18));
        eastEU = new QCheckBox(preferContry);
        eastEU->setObjectName("eastEU");
        eastEU->setGeometry(QRect(220, 20, 64, 18));
        northAmerica = new QCheckBox(preferContry);
        northAmerica->setObjectName("northAmerica");
        northAmerica->setGeometry(QRect(20, 80, 101, 18));
        southAmerica = new QCheckBox(preferContry);
        southAmerica->setObjectName("southAmerica");
        southAmerica->setGeometry(QRect(120, 80, 91, 18));
        africa = new QCheckBox(preferContry);
        africa->setObjectName("africa");
        africa->setGeometry(QRect(220, 80, 81, 18));
        oseania = new QCheckBox(preferContry);
        oseania->setObjectName("oseania");
        oseania->setGeometry(QRect(20, 110, 91, 18));
        arctic = new QCheckBox(preferContry);
        arctic->setObjectName("arctic");
        arctic->setGeometry(QRect(120, 110, 64, 18));
        antArctic = new QCheckBox(preferContry);
        antArctic->setObjectName("antArctic");
        antArctic->setGeometry(QRect(220, 110, 64, 18));
        eastAsia = new QCheckBox(preferContry);
        eastAsia->setObjectName("eastAsia");
        eastAsia->setGeometry(QRect(220, 50, 81, 18));
        travelStyle = new QGroupBox(SignUpWindow);
        travelStyle->setObjectName("travelStyle");
        travelStyle->setGeometry(QRect(80, 510, 311, 151));
        rest = new QCheckBox(travelStyle);
        rest->setObjectName("rest");
        rest->setGeometry(QRect(20, 30, 91, 18));
        cityRest = new QCheckBox(travelStyle);
        cityRest->setObjectName("cityRest");
        cityRest->setGeometry(QRect(120, 30, 91, 18));
        shopping = new QCheckBox(travelStyle);
        shopping->setObjectName("shopping");
        shopping->setGeometry(QRect(220, 30, 71, 18));
        foodSearch = new QCheckBox(travelStyle);
        foodSearch->setObjectName("foodSearch");
        foodSearch->setGeometry(QRect(20, 60, 91, 18));
        activity = new QCheckBox(travelStyle);
        activity->setObjectName("activity");
        activity->setGeometry(QRect(120, 60, 91, 18));
        cultureLife = new QCheckBox(travelStyle);
        cultureLife->setObjectName("cultureLife");
        cultureLife->setGeometry(QRect(220, 60, 71, 18));
        leisurely = new QCheckBox(travelStyle);
        leisurely->setObjectName("leisurely");
        leisurely->setGeometry(QRect(20, 90, 91, 18));
        busy = new QCheckBox(travelStyle);
        busy->setObjectName("busy");
        busy->setGeometry(QRect(120, 90, 91, 18));
        trifity = new QCheckBox(travelStyle);
        trifity->setObjectName("trifity");
        trifity->setGeometry(QRect(220, 90, 61, 18));
        luxury = new QCheckBox(travelStyle);
        luxury->setObjectName("luxury");
        luxury->setGeometry(QRect(20, 120, 91, 18));
        sports = new QCheckBox(travelStyle);
        sports->setObjectName("sports");
        sports->setGeometry(QRect(120, 120, 91, 18));
        nature = new QCheckBox(travelStyle);
        nature->setObjectName("nature");
        nature->setGeometry(QRect(220, 120, 71, 18));
        MBTI = new QGroupBox(SignUpWindow);
        MBTI->setObjectName("MBTI");
        MBTI->setGeometry(QRect(250, 280, 141, 61));
        comboBox = new QComboBox(MBTI);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(10, 20, 121, 31));

        retranslateUi(SignUpWindow);

        QMetaObject::connectSlotsByName(SignUpWindow);
    } // setupUi

    void retranslateUi(QWidget *SignUpWindow)
    {
        SignUpWindow->setWindowTitle(QCoreApplication::translate("SignUpWindow", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        SignUpWindow->setStyleSheet(QCoreApplication::translate("SignUpWindow", "\n"
"    QWidget {\n"
"        background-color: #f9f9f9;\n"
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
"    QLabel {\n"
"        font-size: 12px;\n"
"        color: #666666;\n"
"    }\n"
"   ", nullptr));
        headerLabel->setStyleSheet(QCoreApplication::translate("SignUpWindow", "\n"
"     QLabel {\n"
"         font-size: 24px;\n"
"         font-weight: bold;\n"
"         color: #4682b4;\n"
"     }\n"
"    ", nullptr));
        headerLabel->setText(QCoreApplication::translate("SignUpWindow", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("SignUpWindow", "\354\225\204\354\235\264\353\224\224 \354\236\205\353\240\245", nullptr));
        conform->setText(QCoreApplication::translate("SignUpWindow", "\354\244\221\353\263\265\355\231\225\354\235\270", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("SignUpWindow", "\353\271\204\353\260\200\353\262\210\355\230\270 \354\236\205\353\240\245", nullptr));
        nickName->setPlaceholderText(QCoreApplication::translate("SignUpWindow", "\353\213\211\353\204\244\354\236\204 \354\236\205\353\240\245", nullptr));
        genderGroupBox->setTitle(QCoreApplication::translate("SignUpWindow", "\354\204\261\353\263\204", nullptr));
        checkBoxM->setText(QCoreApplication::translate("SignUpWindow", "\353\202\250\354\236\220", nullptr));
        checkBoxF->setText(QCoreApplication::translate("SignUpWindow", "\354\227\254\354\236\220", nullptr));
        signUpButton->setText(QCoreApplication::translate("SignUpWindow", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        preferContry->setTitle(QCoreApplication::translate("SignUpWindow", "\354\227\254\355\226\211 \354\204\240\355\230\270 \354\247\200\354\227\255", nullptr));
        northEU->setText(QCoreApplication::translate("SignUpWindow", "\353\266\201\354\234\240\353\237\275", nullptr));
        westEU->setText(QCoreApplication::translate("SignUpWindow", "\354\204\234\354\234\240\353\237\275", nullptr));
        centralAsia->setText(QCoreApplication::translate("SignUpWindow", "\354\244\221\354\225\231 \354\225\204\354\213\234\354\225\204", nullptr));
        eastsouthAsia->setText(QCoreApplication::translate("SignUpWindow", "\353\217\231\353\202\250 \354\225\204\354\213\234\354\225\204", nullptr));
        eastEU->setText(QCoreApplication::translate("SignUpWindow", "\353\217\231\354\234\240\353\237\275", nullptr));
        northAmerica->setText(QCoreApplication::translate("SignUpWindow", "\353\266\201\354\225\204\353\251\224\353\246\254\354\271\264", nullptr));
        southAmerica->setText(QCoreApplication::translate("SignUpWindow", "\353\202\250\354\225\204\353\251\224\353\246\254\354\271\264", nullptr));
        africa->setText(QCoreApplication::translate("SignUpWindow", "\354\225\204\355\224\204\353\246\254\354\271\264", nullptr));
        oseania->setText(QCoreApplication::translate("SignUpWindow", "\354\230\244\354\204\270\354\225\204\353\213\210\354\225\204", nullptr));
        arctic->setText(QCoreApplication::translate("SignUpWindow", "\353\202\250\352\267\271", nullptr));
        antArctic->setText(QCoreApplication::translate("SignUpWindow", "\353\266\201\352\267\271", nullptr));
        eastAsia->setText(QCoreApplication::translate("SignUpWindow", "\353\217\231\354\225\204\354\213\234\354\225\204", nullptr));
        travelStyle->setTitle(QCoreApplication::translate("SignUpWindow", "\354\227\254\355\226\211 \354\212\244\355\203\200\354\235\274", nullptr));
        rest->setText(QCoreApplication::translate("SignUpWindow", "\355\234\264\354\226\221", nullptr));
        cityRest->setText(QCoreApplication::translate("SignUpWindow", "\353\217\204\354\213\254 \355\234\264\354\213\235", nullptr));
        shopping->setText(QCoreApplication::translate("SignUpWindow", "\354\207\274\355\225\221", nullptr));
        foodSearch->setText(QCoreApplication::translate("SignUpWindow", "\353\247\233\354\247\221 \355\203\220\353\260\251", nullptr));
        activity->setText(QCoreApplication::translate("SignUpWindow", "\354\225\241\355\213\260\353\271\204\355\213\260", nullptr));
        cultureLife->setText(QCoreApplication::translate("SignUpWindow", "\353\254\270\355\231\224\354\203\235\355\231\234", nullptr));
        leisurely->setText(QCoreApplication::translate("SignUpWindow", "\354\227\254\354\234\240\353\241\255\352\262\214", nullptr));
        busy->setText(QCoreApplication::translate("SignUpWindow", "\353\260\224\354\201\230\352\262\214", nullptr));
        trifity->setText(QCoreApplication::translate("SignUpWindow", "\354\225\214\353\234\260\355\225\230\352\262\214", nullptr));
        luxury->setText(QCoreApplication::translate("SignUpWindow", "\354\202\254\354\271\230\354\212\244\353\237\275\352\262\214", nullptr));
        sports->setText(QCoreApplication::translate("SignUpWindow", "\354\212\244\355\217\254\354\270\240", nullptr));
        nature->setText(QCoreApplication::translate("SignUpWindow", "\354\236\220\354\227\260", nullptr));
        MBTI->setTitle(QCoreApplication::translate("SignUpWindow", "MBTI", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("SignUpWindow", "INFP", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("SignUpWindow", "INFJ", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("SignUpWindow", "INTP", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("SignUpWindow", "INTJ", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("SignUpWindow", "ISFP", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("SignUpWindow", "ISFJ", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("SignUpWindow", "ISTP", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("SignUpWindow", "ISTJ", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("SignUpWindow", "ENFP", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("SignUpWindow", "ENFJ", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("SignUpWindow", "ENTP", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("SignUpWindow", "ENTJ", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("SignUpWindow", "ESFP", nullptr));
        comboBox->setItemText(13, QCoreApplication::translate("SignUpWindow", "ESFJ", nullptr));
        comboBox->setItemText(14, QCoreApplication::translate("SignUpWindow", "ESTP", nullptr));
        comboBox->setItemText(15, QCoreApplication::translate("SignUpWindow", "ESTJ", nullptr));

    } // retranslateUi

};

namespace Ui {
    class SignUpWindow: public Ui_SignUpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H
