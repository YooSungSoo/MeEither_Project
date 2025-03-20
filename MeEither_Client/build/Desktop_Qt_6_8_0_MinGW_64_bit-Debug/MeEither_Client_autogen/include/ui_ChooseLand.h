/********************************************************************************
** Form generated from reading UI file 'ChooseLand.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSELAND_H
#define UI_CHOOSELAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseLand
{
public:
    QLabel *headerLabel;
    QWidget *buttonContainer;
    QPushButton *northEuropeButton;
    QPushButton *westEuropeButton;
    QPushButton *eastEuropeButton;
    QPushButton *eurasiaButton;
    QPushButton *centralAsiaButton;
    QPushButton *eastAsiaButton;
    QPushButton *southEastAsiaButton;
    QPushButton *oceaniaButton;
    QPushButton *northAmericaButton;
    QPushButton *southAmericaButton;
    QPushButton *antarcticaButton;
    QPushButton *arcticButton;

    void setupUi(QWidget *ChooseLand)
    {
        if (ChooseLand->objectName().isEmpty())
            ChooseLand->setObjectName("ChooseLand");
        ChooseLand->resize(770, 395);
        headerLabel = new QLabel(ChooseLand);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setGeometry(QRect(150, 20, 471, 50));
        headerLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        buttonContainer = new QWidget(ChooseLand);
        buttonContainer->setObjectName("buttonContainer");
        buttonContainer->setGeometry(QRect(10, 80, 750, 300));
        northEuropeButton = new QPushButton(buttonContainer);
        northEuropeButton->setObjectName("northEuropeButton");
        northEuropeButton->setGeometry(QRect(50, 20, 150, 50));
        westEuropeButton = new QPushButton(buttonContainer);
        westEuropeButton->setObjectName("westEuropeButton");
        westEuropeButton->setGeometry(QRect(220, 20, 150, 50));
        eastEuropeButton = new QPushButton(buttonContainer);
        eastEuropeButton->setObjectName("eastEuropeButton");
        eastEuropeButton->setGeometry(QRect(390, 20, 150, 50));
        eurasiaButton = new QPushButton(buttonContainer);
        eurasiaButton->setObjectName("eurasiaButton");
        eurasiaButton->setGeometry(QRect(560, 20, 150, 50));
        centralAsiaButton = new QPushButton(buttonContainer);
        centralAsiaButton->setObjectName("centralAsiaButton");
        centralAsiaButton->setGeometry(QRect(50, 100, 150, 50));
        eastAsiaButton = new QPushButton(buttonContainer);
        eastAsiaButton->setObjectName("eastAsiaButton");
        eastAsiaButton->setGeometry(QRect(220, 100, 150, 50));
        southEastAsiaButton = new QPushButton(buttonContainer);
        southEastAsiaButton->setObjectName("southEastAsiaButton");
        southEastAsiaButton->setGeometry(QRect(390, 100, 150, 50));
        oceaniaButton = new QPushButton(buttonContainer);
        oceaniaButton->setObjectName("oceaniaButton");
        oceaniaButton->setGeometry(QRect(560, 100, 150, 50));
        northAmericaButton = new QPushButton(buttonContainer);
        northAmericaButton->setObjectName("northAmericaButton");
        northAmericaButton->setGeometry(QRect(50, 180, 150, 50));
        southAmericaButton = new QPushButton(buttonContainer);
        southAmericaButton->setObjectName("southAmericaButton");
        southAmericaButton->setGeometry(QRect(220, 180, 150, 50));
        antarcticaButton = new QPushButton(buttonContainer);
        antarcticaButton->setObjectName("antarcticaButton");
        antarcticaButton->setGeometry(QRect(390, 180, 150, 50));
        arcticButton = new QPushButton(buttonContainer);
        arcticButton->setObjectName("arcticButton");
        arcticButton->setGeometry(QRect(560, 180, 150, 50));

        retranslateUi(ChooseLand);

        QMetaObject::connectSlotsByName(ChooseLand);
    } // setupUi

    void retranslateUi(QWidget *ChooseLand)
    {
        ChooseLand->setWindowTitle(QCoreApplication::translate("ChooseLand", "\353\214\200\353\245\231 \354\204\240\355\203\235", nullptr));
        ChooseLand->setStyleSheet(QCoreApplication::translate("ChooseLand", "\n"
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
"        font-size: 16px; /* \352\270\200\354\236\220 \355\201\254\352\270\260 \354\246\235\352\260\200 */\n"
"        padding: 5px 10px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #4682b4;\n"
"    }\n"
"    QLabel {\n"
"        font-size: 18px; /* \355\227\244\353\215\224 \352\270\200\354\236\220 \355\201\254\352\270\260 \354\246\235\352\260\200 */\n"
"        font-weight: bold;\n"
"        color: #4682b4;\n"
"    }\n"
"   ", nullptr));
        headerLabel->setText(QCoreApplication::translate("ChooseLand", "\353\217\231\355\226\211\354\235\204 \354\260\276\352\263\240\354\236\220 \355\225\230\353\212\224 \353\214\200\353\245\231\354\235\204 \354\204\240\355\203\235\355\225\230\354\204\270\354\232\224", nullptr));
        northEuropeButton->setText(QCoreApplication::translate("ChooseLand", "\353\266\201\354\234\240\353\237\275", nullptr));
        westEuropeButton->setText(QCoreApplication::translate("ChooseLand", "\354\204\234\354\234\240\353\237\275", nullptr));
        eastEuropeButton->setText(QCoreApplication::translate("ChooseLand", "\353\217\231\354\234\240\353\237\275", nullptr));
        eurasiaButton->setText(QCoreApplication::translate("ChooseLand", "\354\234\240\353\235\274\354\213\234\354\225\204", nullptr));
        centralAsiaButton->setText(QCoreApplication::translate("ChooseLand", "\354\244\221\354\225\231\354\225\204\354\213\234\354\225\204", nullptr));
        eastAsiaButton->setText(QCoreApplication::translate("ChooseLand", "\353\217\231\354\225\204\354\213\234\354\225\204", nullptr));
        southEastAsiaButton->setText(QCoreApplication::translate("ChooseLand", "\353\217\231\353\202\250\354\225\204\354\213\234\354\225\204", nullptr));
        oceaniaButton->setText(QCoreApplication::translate("ChooseLand", "\354\230\244\354\204\270\354\225\204\353\213\210\354\225\204", nullptr));
        northAmericaButton->setText(QCoreApplication::translate("ChooseLand", "\353\266\201\354\225\204\353\251\224\353\246\254\354\271\264", nullptr));
        southAmericaButton->setText(QCoreApplication::translate("ChooseLand", "\353\202\250\354\225\204\353\251\224\353\246\254\354\271\264", nullptr));
        antarcticaButton->setText(QCoreApplication::translate("ChooseLand", "\353\202\250\352\267\271", nullptr));
        arcticButton->setText(QCoreApplication::translate("ChooseLand", "\353\266\201\352\267\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseLand: public Ui_ChooseLand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSELAND_H
