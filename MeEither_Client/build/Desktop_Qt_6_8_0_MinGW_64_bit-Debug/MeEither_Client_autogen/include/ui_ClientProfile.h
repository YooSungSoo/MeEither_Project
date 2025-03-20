/********************************************************************************
** Form generated from reading UI file 'ClientProfile.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTPROFILE_H
#define UI_CLIENTPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientProfile
{
public:
    QGroupBox *profilePhotoBox;
    QLabel *profilePhotoLabel;
    QGroupBox *userInfoBox;
    QLabel *nicknameLabel;
    QLabel *ageLabel;
    QLabel *genderLabel;
    QLabel *mbtiLabel;
    QPushButton *closeButton;
    QGroupBox *travelStyleBox;
    QLabel *travelStyleLabel;
    QGroupBox *preferredDestinationsBox;
    QLabel *preferredDestinationsLabel;

    void setupUi(QWidget *ClientProfile)
    {
        if (ClientProfile->objectName().isEmpty())
            ClientProfile->setObjectName("ClientProfile");
        ClientProfile->resize(581, 434);
        profilePhotoBox = new QGroupBox(ClientProfile);
        profilePhotoBox->setObjectName("profilePhotoBox");
        profilePhotoBox->setGeometry(QRect(20, 20, 251, 200));
        profilePhotoLabel = new QLabel(profilePhotoBox);
        profilePhotoLabel->setObjectName("profilePhotoLabel");
        profilePhotoLabel->setGeometry(QRect(20, 30, 211, 151));
        profilePhotoLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        userInfoBox = new QGroupBox(ClientProfile);
        userInfoBox->setObjectName("userInfoBox");
        userInfoBox->setGeometry(QRect(290, 20, 261, 201));
        nicknameLabel = new QLabel(userInfoBox);
        nicknameLabel->setObjectName("nicknameLabel");
        nicknameLabel->setGeometry(QRect(10, 40, 241, 20));
        ageLabel = new QLabel(userInfoBox);
        ageLabel->setObjectName("ageLabel");
        ageLabel->setGeometry(QRect(10, 80, 241, 20));
        genderLabel = new QLabel(userInfoBox);
        genderLabel->setObjectName("genderLabel");
        genderLabel->setGeometry(QRect(10, 120, 241, 20));
        mbtiLabel = new QLabel(userInfoBox);
        mbtiLabel->setObjectName("mbtiLabel");
        mbtiLabel->setGeometry(QRect(10, 160, 241, 20));
        closeButton = new QPushButton(ClientProfile);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(240, 390, 100, 30));
        travelStyleBox = new QGroupBox(ClientProfile);
        travelStyleBox->setObjectName("travelStyleBox");
        travelStyleBox->setGeometry(QRect(20, 230, 531, 71));
        travelStyleLabel = new QLabel(travelStyleBox);
        travelStyleLabel->setObjectName("travelStyleLabel");
        travelStyleLabel->setGeometry(QRect(10, 40, 491, 21));
        travelStyleLabel->setAlignment(Qt::AlignmentFlag::AlignTop);
        preferredDestinationsBox = new QGroupBox(ClientProfile);
        preferredDestinationsBox->setObjectName("preferredDestinationsBox");
        preferredDestinationsBox->setGeometry(QRect(20, 310, 531, 71));
        preferredDestinationsLabel = new QLabel(preferredDestinationsBox);
        preferredDestinationsLabel->setObjectName("preferredDestinationsLabel");
        preferredDestinationsLabel->setGeometry(QRect(10, 40, 491, 21));
        preferredDestinationsLabel->setAlignment(Qt::AlignmentFlag::AlignTop);

        retranslateUi(ClientProfile);

        QMetaObject::connectSlotsByName(ClientProfile);
    } // setupUi

    void retranslateUi(QWidget *ClientProfile)
    {
        ClientProfile->setWindowTitle(QCoreApplication::translate("ClientProfile", "\355\224\204\353\241\234\355\225\204", nullptr));
        ClientProfile->setStyleSheet(QCoreApplication::translate("ClientProfile", "\n"
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
"    QLabel {\n"
"        font-size: 14px;\n"
"        font-weight: bold;\n"
"        color: #4682b4;\n"
"    }\n"
"    QGroupBox {\n"
"        border: 1px solid #4682b4;\n"
"        border-radius: 8px;\n"
"        margin-top: 10px;\n"
"        padding: 10px;\n"
"    }\n"
"   ", nullptr));
        profilePhotoBox->setTitle(QCoreApplication::translate("ClientProfile", "\355\224\204\353\241\234\355\225\204 \354\202\254\354\247\204", nullptr));
        profilePhotoLabel->setStyleSheet(QCoreApplication::translate("ClientProfile", "\n"
"      QLabel {\n"
"          border: 1px solid #87ceeb;\n"
"          background-color: #ffffff;\n"
"      }\n"
"     ", nullptr));
        profilePhotoLabel->setText(QCoreApplication::translate("ClientProfile", "\354\235\264\353\257\270\354\247\200\352\260\200 \354\227\206\354\212\265\353\213\210\353\213\244", nullptr));
        userInfoBox->setTitle(QCoreApplication::translate("ClientProfile", "\354\202\254\354\232\251\354\236\220 \354\240\225\353\263\264", nullptr));
        nicknameLabel->setText(QCoreApplication::translate("ClientProfile", "\353\213\211\353\204\244\354\236\204:", nullptr));
        ageLabel->setText(QCoreApplication::translate("ClientProfile", "\353\202\230\354\235\264: ", nullptr));
        genderLabel->setText(QCoreApplication::translate("ClientProfile", "\354\204\261\353\263\204:", nullptr));
        mbtiLabel->setText(QCoreApplication::translate("ClientProfile", "MBTI: ", nullptr));
        closeButton->setText(QCoreApplication::translate("ClientProfile", "\353\213\253\352\270\260", nullptr));
        travelStyleBox->setTitle(QCoreApplication::translate("ClientProfile", "\354\227\254\355\226\211 \354\212\244\355\203\200\354\235\274", nullptr));
        travelStyleLabel->setText(QString());
        preferredDestinationsBox->setTitle(QCoreApplication::translate("ClientProfile", "\354\204\240\355\230\270 \354\247\200\354\227\255", nullptr));
        preferredDestinationsLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ClientProfile: public Ui_ClientProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTPROFILE_H
