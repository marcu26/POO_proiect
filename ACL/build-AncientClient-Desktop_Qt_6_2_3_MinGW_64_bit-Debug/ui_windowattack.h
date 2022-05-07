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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windowAttack
{
public:
    QWidget *widget;
    QPushButton *useSold;
    QPushButton *useCav;
    QPushButton *useMed;
    QFrame *Initial;
    QLabel *Init;
    QLabel *SoldI;
    QLabel *CavI;
    QLabel *MedI;
    QFrame *Curent;
    QLabel *Curent_2;
    QLabel *SoldC;
    QLabel *CavC;
    QLabel *MedC;
    QFrame *Final;
    QLabel *Final_2;
    QLabel *SoldF;
    QLabel *CavF;
    QLabel *MedF;
    QPushButton *Exit;
    QPushButton *Pause;
    QLabel *SoldLabel;
    QLabel *CavLabel;
    QLabel *MedLabel;

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
        widget->setStyleSheet(QString::fromUtf8(""));
        useSold = new QPushButton(widget);
        useSold->setObjectName(QString::fromUtf8("useSold"));
        useSold->setGeometry(QRect(120, 30, 91, 81));
        QFont font;
        font.setBold(true);
        useSold->setFont(font);
        useSold->setAutoFillBackground(false);
        useCav = new QPushButton(widget);
        useCav->setObjectName(QString::fromUtf8("useCav"));
        useCav->setGeometry(QRect(360, 30, 91, 81));
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        useCav->setFont(font1);
        useMed = new QPushButton(widget);
        useMed->setObjectName(QString::fromUtf8("useMed"));
        useMed->setGeometry(QRect(590, 30, 91, 81));
        useMed->setFont(font);
        Initial = new QFrame(widget);
        Initial->setObjectName(QString::fromUtf8("Initial"));
        Initial->setGeometry(QRect(60, 160, 211, 291));
        Initial->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0,80%);"));
        Initial->setFrameShape(QFrame::StyledPanel);
        Initial->setFrameShadow(QFrame::Raised);
        Init = new QLabel(Initial);
        Init->setObjectName(QString::fromUtf8("Init"));
        Init->setGeometry(QRect(0, 10, 211, 20));
        Init->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0%);\n"
"color: rgb(255, 255, 255);"));
        Init->setAlignment(Qt::AlignCenter);
        SoldI = new QLabel(Initial);
        SoldI->setObjectName(QString::fromUtf8("SoldI"));
        SoldI->setGeometry(QRect(20, 90, 191, 20));
        SoldI->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0%);\n"
"color:rgb(255,255,255);"));
        SoldI->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        CavI = new QLabel(Initial);
        CavI->setObjectName(QString::fromUtf8("CavI"));
        CavI->setGeometry(QRect(20, 150, 191, 20));
        CavI->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0%);\n"
"color:rgb(255,255,255);"));
        CavI->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        MedI = new QLabel(Initial);
        MedI->setObjectName(QString::fromUtf8("MedI"));
        MedI->setGeometry(QRect(20, 210, 191, 20));
        MedI->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0%);\n"
"color:rgb(255,255,255);"));
        MedI->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Curent = new QFrame(widget);
        Curent->setObjectName(QString::fromUtf8("Curent"));
        Curent->setGeometry(QRect(300, 160, 211, 291));
        Curent->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0,80%);"));
        Curent->setFrameShape(QFrame::StyledPanel);
        Curent->setFrameShadow(QFrame::Raised);
        Curent_2 = new QLabel(Curent);
        Curent_2->setObjectName(QString::fromUtf8("Curent_2"));
        Curent_2->setGeometry(QRect(0, 10, 211, 20));
        Curent_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0%);\n"
"color:rgb(255,255,255);"));
        Curent_2->setAlignment(Qt::AlignCenter);
        SoldC = new QLabel(Curent);
        SoldC->setObjectName(QString::fromUtf8("SoldC"));
        SoldC->setGeometry(QRect(20, 90, 191, 20));
        SoldC->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0%);\n"
"color:rgb(255,255,255);"));
        SoldC->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        CavC = new QLabel(Curent);
        CavC->setObjectName(QString::fromUtf8("CavC"));
        CavC->setGeometry(QRect(20, 150, 191, 20));
        CavC->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0%);\n"
"color:rgb(255,255,255);"));
        CavC->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        MedC = new QLabel(Curent);
        MedC->setObjectName(QString::fromUtf8("MedC"));
        MedC->setGeometry(QRect(20, 210, 191, 20));
        MedC->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0%);\n"
"color:rgb(255,255,255);"));
        MedC->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Final = new QFrame(widget);
        Final->setObjectName(QString::fromUtf8("Final"));
        Final->setGeometry(QRect(540, 160, 211, 291));
        Final->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0,80%);"));
        Final->setFrameShape(QFrame::StyledPanel);
        Final->setFrameShadow(QFrame::Raised);
        Final_2 = new QLabel(Final);
        Final_2->setObjectName(QString::fromUtf8("Final_2"));
        Final_2->setGeometry(QRect(0, 10, 211, 20));
        Final_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0%);\n"
"color:rgb(255,255,255);"));
        Final_2->setAlignment(Qt::AlignCenter);
        SoldF = new QLabel(Final);
        SoldF->setObjectName(QString::fromUtf8("SoldF"));
        SoldF->setGeometry(QRect(20, 90, 191, 20));
        SoldF->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0%);\n"
"color:rgb(255,255,255);"));
        SoldF->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        CavF = new QLabel(Final);
        CavF->setObjectName(QString::fromUtf8("CavF"));
        CavF->setGeometry(QRect(20, 150, 191, 20));
        CavF->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0%);\n"
"color:rgb(255,255,255);"));
        CavF->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        MedF = new QLabel(Final);
        MedF->setObjectName(QString::fromUtf8("MedF"));
        MedF->setGeometry(QRect(20, 210, 191, 20));
        MedF->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0%);\n"
"color:rgb(255,255,255);"));
        MedF->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Exit = new QPushButton(widget);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(660, 510, 91, 41));
        Exit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;"));
        Pause = new QPushButton(widget);
        Pause->setObjectName(QString::fromUtf8("Pause"));
        Pause->setGeometry(QRect(540, 510, 91, 41));
        Pause->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;"));
        SoldLabel = new QLabel(widget);
        SoldLabel->setObjectName(QString::fromUtf8("SoldLabel"));
        SoldLabel->setGeometry(QRect(120, 85, 91, 20));
        SoldLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0, 0, 50%);\n"
"color: rgb(255, 255, 255);"));
        SoldLabel->setAlignment(Qt::AlignCenter);
        CavLabel = new QLabel(widget);
        CavLabel->setObjectName(QString::fromUtf8("CavLabel"));
        CavLabel->setGeometry(QRect(360, 85, 91, 20));
        CavLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0, 0, 50%);\n"
"color: rgb(255, 255, 255);"));
        CavLabel->setAlignment(Qt::AlignCenter);
        MedLabel = new QLabel(widget);
        MedLabel->setObjectName(QString::fromUtf8("MedLabel"));
        MedLabel->setGeometry(QRect(590, 85, 91, 20));
        MedLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0, 0, 50%);\n"
"color: rgb(255, 255, 255);"));
        MedLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(windowAttack);

        QMetaObject::connectSlotsByName(windowAttack);
    } // setupUi

    void retranslateUi(QDialog *windowAttack)
    {
        windowAttack->setWindowTitle(QCoreApplication::translate("windowAttack", "Dialog", nullptr));
        useSold->setText(QString());
        useCav->setText(QString());
        useMed->setText(QString());
        Init->setText(QCoreApplication::translate("windowAttack", "Trupe initiale", nullptr));
        SoldI->setText(QCoreApplication::translate("windowAttack", "Soldati: 0", nullptr));
        CavI->setText(QCoreApplication::translate("windowAttack", "Cavalerie: 0", nullptr));
        MedI->setText(QCoreApplication::translate("windowAttack", "Medici: 0", nullptr));
        Curent_2->setText(QCoreApplication::translate("windowAttack", "Trupe curente", nullptr));
        SoldC->setText(QCoreApplication::translate("windowAttack", "Soldati: 0", nullptr));
        CavC->setText(QCoreApplication::translate("windowAttack", "Cavalerie: 0", nullptr));
        MedC->setText(QCoreApplication::translate("windowAttack", "Medici: 0", nullptr));
        Final_2->setText(QCoreApplication::translate("windowAttack", "Trupe dusman", nullptr));
        SoldF->setText(QCoreApplication::translate("windowAttack", "Soldati: 0", nullptr));
        CavF->setText(QCoreApplication::translate("windowAttack", "Cavalerie: 0", nullptr));
        MedF->setText(QCoreApplication::translate("windowAttack", "Medici: 0", nullptr));
        Exit->setText(QCoreApplication::translate("windowAttack", "Exit", nullptr));
        Pause->setText(QCoreApplication::translate("windowAttack", "Pause", nullptr));
        SoldLabel->setText(QCoreApplication::translate("windowAttack", "Soldati", nullptr));
        CavLabel->setText(QCoreApplication::translate("windowAttack", "Cavalerie", nullptr));
        MedLabel->setText(QCoreApplication::translate("windowAttack", "Medici", nullptr));
    } // retranslateUi

};

namespace Ui {
    class windowAttack: public Ui_windowAttack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWATTACK_H
