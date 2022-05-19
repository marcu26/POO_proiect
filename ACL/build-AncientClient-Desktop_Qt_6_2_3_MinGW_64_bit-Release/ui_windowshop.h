/********************************************************************************
** Form generated from reading UI file 'windowshop.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWSHOP_H
#define UI_WINDOWSHOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windowShop
{
public:
    QPushButton *Muncitori;
    QPushButton *Provoaca_2;
    QPushButton *AutoMili;
    QPushButton *Close;
    QWidget *widget;

    void setupUi(QDialog *windowShop)
    {
        if (windowShop->objectName().isEmpty())
            windowShop->setObjectName(QString::fromUtf8("windowShop"));
        windowShop->resize(300, 400);
        windowShop->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,80%);"));
        Muncitori = new QPushButton(windowShop);
        Muncitori->setObjectName(QString::fromUtf8("Muncitori"));
        Muncitori->setGeometry(QRect(50, 40, 200, 40));
        Muncitori->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 127,50%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
""));
        Provoaca_2 = new QPushButton(windowShop);
        Provoaca_2->setObjectName(QString::fromUtf8("Provoaca_2"));
        Provoaca_2->setGeometry(QRect(50, 130, 200, 40));
        Provoaca_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 127,50%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
""));
        AutoMili = new QPushButton(windowShop);
        AutoMili->setObjectName(QString::fromUtf8("AutoMili"));
        AutoMili->setGeometry(QRect(50, 220, 200, 40));
        AutoMili->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 127,50%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
""));
        Close = new QPushButton(windowShop);
        Close->setObjectName(QString::fromUtf8("Close"));
        Close->setGeometry(QRect(90, 340, 111, 40));
        Close->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(85, 0, 0,50%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
""));
        widget = new QWidget(windowShop);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-10, -20, 321, 431));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0,0,0);"));
        widget->raise();
        Muncitori->raise();
        Provoaca_2->raise();
        AutoMili->raise();
        Close->raise();

        retranslateUi(windowShop);

        QMetaObject::connectSlotsByName(windowShop);
    } // setupUi

    void retranslateUi(QDialog *windowShop)
    {
        windowShop->setWindowTitle(QCoreApplication::translate("windowShop", "Dialog", nullptr));
        Muncitori->setText(QCoreApplication::translate("windowShop", "Muncitori", nullptr));
        Provoaca_2->setText(QCoreApplication::translate("windowShop", "Autorizatie scoala medicala", nullptr));
        AutoMili->setText(QCoreApplication::translate("windowShop", "Autorizatie scoala militara", nullptr));
        Close->setText(QCoreApplication::translate("windowShop", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class windowShop: public Ui_windowShop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSHOP_H
