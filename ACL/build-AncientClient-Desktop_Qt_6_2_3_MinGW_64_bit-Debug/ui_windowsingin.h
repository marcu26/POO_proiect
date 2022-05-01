/********************************************************************************
** Form generated from reading UI file 'windowsingin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWSINGIN_H
#define UI_WINDOWSINGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowSingIn
{
public:
    QLabel *succes;
    QFrame *frame;
    QLabel *uname;
    QLabel *pass;
    QLineEdit *Pass_2;
    QLabel *cpass;
    QLineEdit *Pass;
    QLineEdit *uName;
    QPushButton *finnishB;
    QPushButton *BackB;
    QLabel *invalid;
    QLabel *banner;
    QWidget *widget;

    void setupUi(QDialog *WindowSingIn)
    {
        if (WindowSingIn->objectName().isEmpty())
            WindowSingIn->setObjectName(QString::fromUtf8("WindowSingIn"));
        WindowSingIn->resize(800, 600);
        WindowSingIn->setMinimumSize(QSize(800, 600));
        WindowSingIn->setMaximumSize(QSize(800, 600));
        succes = new QLabel(WindowSingIn);
        succes->setObjectName(QString::fromUtf8("succes"));
        succes->setEnabled(true);
        succes->setGeometry(QRect(290, 510, 231, 20));
        succes->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:rgb(0, 85, 127)"));
        succes->setAlignment(Qt::AlignCenter);
        frame = new QFrame(WindowSingIn);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(140, 160, 500, 190));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0,60%);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        uname = new QLabel(frame);
        uname->setObjectName(QString::fromUtf8("uname"));
        uname->setGeometry(QRect(30, 35, 81, 20));
        uname->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0, 0%);"));
        uname->setAlignment(Qt::AlignCenter);
        pass = new QLabel(frame);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setGeometry(QRect(30, 85, 51, 20));
        pass->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0, 0%);"));
        pass->setAlignment(Qt::AlignCenter);
        Pass_2 = new QLineEdit(frame);
        Pass_2->setObjectName(QString::fromUtf8("Pass_2"));
        Pass_2->setGeometry(QRect(170, 130, 301, 31));
        Pass_2->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);"));
        Pass_2->setEchoMode(QLineEdit::Password);
        cpass = new QLabel(frame);
        cpass->setObjectName(QString::fromUtf8("cpass"));
        cpass->setGeometry(QRect(30, 135, 131, 20));
        cpass->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0, 0%);"));
        cpass->setAlignment(Qt::AlignCenter);
        Pass = new QLineEdit(frame);
        Pass->setObjectName(QString::fromUtf8("Pass"));
        Pass->setGeometry(QRect(170, 80, 301, 31));
        Pass->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255)"));
        Pass->setEchoMode(QLineEdit::Password);
        uName = new QLineEdit(frame);
        uName->setObjectName(QString::fromUtf8("uName"));
        uName->setGeometry(QRect(170, 30, 301, 28));
        uName->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255)"));
        finnishB = new QPushButton(WindowSingIn);
        finnishB->setObjectName(QString::fromUtf8("finnishB"));
        finnishB->setGeometry(QRect(370, 390, 90, 35));
        finnishB->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        BackB = new QPushButton(WindowSingIn);
        BackB->setObjectName(QString::fromUtf8("BackB"));
        BackB->setGeometry(QRect(370, 450, 90, 35));
        BackB->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        invalid = new QLabel(WindowSingIn);
        invalid->setObjectName(QString::fromUtf8("invalid"));
        invalid->setEnabled(true);
        invalid->setGeometry(QRect(290, 550, 231, 20));
        invalid->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 0, 0,80%);"));
        invalid->setAlignment(Qt::AlignCenter);
        banner = new QLabel(WindowSingIn);
        banner->setObjectName(QString::fromUtf8("banner"));
        banner->setGeometry(QRect(200, 40, 400, 40));
        banner->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,60%);"));
        banner->setAlignment(Qt::AlignCenter);
        widget = new QWidget(WindowSingIn);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-90, -50, 900, 700));
        widget->setStyleSheet(QString::fromUtf8("   .QWidget{background-image:url( C:/Users/marcu/Desktop/ACL/AncientClient/Media/poza.png); background-position: center; }"));
        widget->raise();
        succes->raise();
        frame->raise();
        finnishB->raise();
        BackB->raise();
        invalid->raise();
        banner->raise();

        retranslateUi(WindowSingIn);

        QMetaObject::connectSlotsByName(WindowSingIn);
    } // setupUi

    void retranslateUi(QDialog *WindowSingIn)
    {
        WindowSingIn->setWindowTitle(QCoreApplication::translate("WindowSingIn", "Dialog", nullptr));
        succes->setText(QCoreApplication::translate("WindowSingIn", "Autentificare cu succes", nullptr));
        uname->setText(QCoreApplication::translate("WindowSingIn", "Username", nullptr));
        pass->setText(QCoreApplication::translate("WindowSingIn", "Parola", nullptr));
        cpass->setText(QCoreApplication::translate("WindowSingIn", "Confirmare parola", nullptr));
        finnishB->setText(QCoreApplication::translate("WindowSingIn", "Finnish", nullptr));
        BackB->setText(QCoreApplication::translate("WindowSingIn", "Back", nullptr));
        invalid->setText(QCoreApplication::translate("WindowSingIn", "Username sau parola invalide", nullptr));
        banner->setText(QCoreApplication::translate("WindowSingIn", "Pune credentialele pentru a te inregistra", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowSingIn: public Ui_WindowSingIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSINGIN_H
