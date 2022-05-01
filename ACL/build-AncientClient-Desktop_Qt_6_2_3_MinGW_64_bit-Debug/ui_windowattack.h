/********************************************************************************
** Form generated from reading UI file 'windowattack.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWATTACK_H
#define UI_WINDOWATTACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windowAttack
{
public:
    QWidget *widget;

    void setupUi(QDialog *windowAttack)
    {
        if (windowAttack->objectName().isEmpty())
            windowAttack->setObjectName(QString::fromUtf8("windowAttack"));
        windowAttack->resize(800, 600);
        windowAttack->setMinimumSize(QSize(800, 600));
        windowAttack->setMaximumSize(QSize(800, 600));
        widget = new QWidget(windowAttack);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 800, 600));
        widget->setStyleSheet(QString::fromUtf8("   .QWidget{background-image:url( C:/Users/marcu/Desktop/ACL/AncientClient/Media/poza3.jpg); background-position: center; }"));

        retranslateUi(windowAttack);

        QMetaObject::connectSlotsByName(windowAttack);
    } // setupUi

    void retranslateUi(QDialog *windowAttack)
    {
        windowAttack->setWindowTitle(QCoreApplication::translate("windowAttack", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class windowAttack: public Ui_windowAttack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWATTACK_H
