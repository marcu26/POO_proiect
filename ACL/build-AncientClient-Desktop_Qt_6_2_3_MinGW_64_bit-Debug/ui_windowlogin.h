/********************************************************************************
** Form generated from reading UI file 'windowlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWLOGIN_H
#define UI_WINDOWLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowLogIn
{
public:
    QWidget *widget;
    QLabel *banner;
    QFrame *frame;
    QLabel *uname;
    QLabel *pass;
    QLineEdit *Pass;
    QLineEdit *uName;
    QPushButton *finnishB;
    QPushButton *BackB;
    QLabel *invalid;

    void setupUi(QDialog *WindowLogIn)
    {
        if (WindowLogIn->objectName().isEmpty())
            WindowLogIn->setObjectName(QString::fromUtf8("WindowLogIn"));
        WindowLogIn->resize(800, 600);
        WindowLogIn->setMinimumSize(QSize(800, 600));
        WindowLogIn->setMaximumSize(QSize(800, 600));
        widget = new QWidget(WindowLogIn);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-90, -50, 900, 700));
        widget->setStyleSheet(QString::fromUtf8(""));
        banner = new QLabel(WindowLogIn);
        banner->setObjectName(QString::fromUtf8("banner"));
        banner->setGeometry(QRect(200, 40, 400, 40));
        banner->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,60%);"));
        banner->setAlignment(Qt::AlignCenter);
        frame = new QFrame(WindowLogIn);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(140, 180, 500, 141));
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
        Pass = new QLineEdit(frame);
        Pass->setObjectName(QString::fromUtf8("Pass"));
        Pass->setGeometry(QRect(170, 80, 301, 31));
        Pass->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255)"));
        Pass->setEchoMode(QLineEdit::Password);
        uName = new QLineEdit(frame);
        uName->setObjectName(QString::fromUtf8("uName"));
        uName->setGeometry(QRect(170, 30, 301, 28));
        uName->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255)"));
        finnishB = new QPushButton(WindowLogIn);
        finnishB->setObjectName(QString::fromUtf8("finnishB"));
        finnishB->setGeometry(QRect(360, 390, 100, 45));
        finnishB->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;"));
        BackB = new QPushButton(WindowLogIn);
        BackB->setObjectName(QString::fromUtf8("BackB"));
        BackB->setGeometry(QRect(360, 460, 100, 45));
        BackB->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;"));
        invalid = new QLabel(WindowLogIn);
        invalid->setObjectName(QString::fromUtf8("invalid"));
        invalid->setEnabled(true);
        invalid->setGeometry(QRect(300, 550, 231, 20));
        invalid->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 0, 0,80%);"));
        invalid->setAlignment(Qt::AlignCenter);

        retranslateUi(WindowLogIn);

        QMetaObject::connectSlotsByName(WindowLogIn);
    } // setupUi

    void retranslateUi(QDialog *WindowLogIn)
    {
        WindowLogIn->setWindowTitle(QCoreApplication::translate("WindowLogIn", "Dialog", nullptr));
        banner->setText(QCoreApplication::translate("WindowLogIn", "Pune credentialele pentru a te conecta", nullptr));
        uname->setText(QCoreApplication::translate("WindowLogIn", "Username", nullptr));
        pass->setText(QCoreApplication::translate("WindowLogIn", "Parola", nullptr));
        finnishB->setText(QCoreApplication::translate("WindowLogIn", "Finnish", nullptr));
        BackB->setText(QCoreApplication::translate("WindowLogIn", "Back", nullptr));
        invalid->setText(QCoreApplication::translate("WindowLogIn", "Username sau parola invalide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowLogIn: public Ui_WindowLogIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWLOGIN_H
