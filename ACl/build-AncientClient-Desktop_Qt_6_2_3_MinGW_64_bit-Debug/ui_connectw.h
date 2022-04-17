/********************************************************************************
** Form generated from reading UI file 'connectw.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTW_H
#define UI_CONNECTW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectW
{
public:
    QWidget *widget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QFrame *frame;
    QLineEdit *uName;
    QLabel *label_2;
    QLineEdit *Pass;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *ConnectW)
    {
        if (ConnectW->objectName().isEmpty())
            ConnectW->setObjectName(QString::fromUtf8("ConnectW"));
        ConnectW->resize(800, 600);
        widget = new QWidget(ConnectW);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-80, -60, 1001, 791));
        widget->setStyleSheet(QString::fromUtf8("   .QWidget{background-image:url( D:/ACl/AncientClient/Media/poza.png); background-position: center; }"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 120, 401, 41));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,60%);"));
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(430, 390, 83, 29));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(430, 460, 83, 29));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        frame = new QFrame(widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(240, 210, 491, 141));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0,60%);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        uName = new QLineEdit(frame);
        uName->setObjectName(QString::fromUtf8("uName"));
        uName->setGeometry(QRect(120, 20, 301, 28));
        uName->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 20, 81, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,0%);"));
        label_2->setAlignment(Qt::AlignCenter);
        Pass = new QLineEdit(frame);
        Pass->setObjectName(QString::fromUtf8("Pass"));
        Pass->setGeometry(QRect(120, 90, 301, 31));
        Pass->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 90, 81, 20));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,0%);"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(true);
        label_4->setGeometry(QRect(360, 550, 231, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 0, 0,80%);"));
        label_4->setAlignment(Qt::AlignCenter);
        frame->raise();
        label->raise();
        pushButton->raise();
        pushButton_4->raise();
        label_4->raise();

        retranslateUi(ConnectW);

        QMetaObject::connectSlotsByName(ConnectW);
    } // setupUi

    void retranslateUi(QDialog *ConnectW)
    {
        ConnectW->setWindowTitle(QCoreApplication::translate("ConnectW", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ConnectW", "Pune credentialele pentru a te conecta", nullptr));
        pushButton->setText(QCoreApplication::translate("ConnectW", "Finnish", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ConnectW", "Back", nullptr));
        label_2->setText(QCoreApplication::translate("ConnectW", "Username", nullptr));
        label_3->setText(QCoreApplication::translate("ConnectW", "Parola", nullptr));
        label_4->setText(QCoreApplication::translate("ConnectW", "Username sau parola invalide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectW: public Ui_ConnectW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTW_H
