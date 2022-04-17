/********************************************************************************
** Form generated from reading UI file 'singinwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGINWINDOW_H
#define UI_SINGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SingInWindow
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QLineEdit *Pass;
    QLineEdit *uName;
    QLabel *label_4;
    QFrame *frame;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;

    void setupUi(QDialog *SingInWindow)
    {
        if (SingInWindow->objectName().isEmpty())
            SingInWindow->setObjectName(QString::fromUtf8("SingInWindow"));
        SingInWindow->resize(800, 600);
        widget = new QWidget(SingInWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-40, -10, 851, 641));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setEnabled(true);
        widget_2->setGeometry(QRect(-50, -50, 1001, 791));
        widget_2->setStyleSheet(QString::fromUtf8("   .QWidget{background-image:url( D:/ACl/AncientClient/Media/poza.png); background-position: center; }"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 120, 401, 41));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,60%);"));
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 390, 83, 29));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(470, 460, 83, 29));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        Pass = new QLineEdit(widget_2);
        Pass->setObjectName(QString::fromUtf8("Pass"));
        Pass->setGeometry(QRect(370, 290, 301, 31));
        uName = new QLineEdit(widget_2);
        uName->setObjectName(QString::fromUtf8("uName"));
        uName->setGeometry(QRect(370, 220, 301, 28));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(true);
        label_4->setGeometry(QRect(390, 550, 231, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 0, 0,80%);"));
        label_4->setAlignment(Qt::AlignCenter);
        frame = new QFrame(widget_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(240, 200, 491, 141));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0,60%);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 81, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0, 0%);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 90, 81, 20));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0, 0%);"));
        label_3->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(true);
        label_5->setGeometry(QRect(390, 510, 231, 20));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:rgb(0, 85, 127)"));
        label_5->setAlignment(Qt::AlignCenter);
        frame->raise();
        label->raise();
        pushButton->raise();
        pushButton_4->raise();
        Pass->raise();
        uName->raise();
        label_4->raise();
        label_5->raise();

        retranslateUi(SingInWindow);

        QMetaObject::connectSlotsByName(SingInWindow);
    } // setupUi

    void retranslateUi(QDialog *SingInWindow)
    {
        SingInWindow->setWindowTitle(QCoreApplication::translate("SingInWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SingInWindow", "Pune credentialele pentru a te inregistra", nullptr));
        pushButton->setText(QCoreApplication::translate("SingInWindow", "Finnish", nullptr));
        pushButton_4->setText(QCoreApplication::translate("SingInWindow", "Back", nullptr));
        label_4->setText(QCoreApplication::translate("SingInWindow", "Username sau parola invalide", nullptr));
        label_2->setText(QCoreApplication::translate("SingInWindow", "Username", nullptr));
        label_3->setText(QCoreApplication::translate("SingInWindow", "Parola", nullptr));
        label_5->setText(QCoreApplication::translate("SingInWindow", "Autentificare cu succes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SingInWindow: public Ui_SingInWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGINWINDOW_H
