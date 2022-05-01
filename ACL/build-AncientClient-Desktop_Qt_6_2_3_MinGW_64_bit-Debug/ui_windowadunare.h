/********************************************************************************
** Form generated from reading UI file 'windowadunare.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWADUNARE_H
#define UI_WINDOWADUNARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windowAdunare
{
public:
    QWidget *widget;
    QFrame *frame;
    QLabel *res;
    QLabel *Galbeni;
    QLabel *Muncitori;
    QLabel *Soldati;
    QLabel *Cavalerie;
    QLabel *Medici;
    QPushButton *LogInB;
    QPushButton *Shop;
    QPushButton *Provoaca;
    QFrame *frame_2;
    QLineEdit *lineEdit;
    QPushButton *Shop_2;
    QLabel *Banner;
    QPushButton *ScSoldati;
    QPushButton *ScMedici;
    QLabel *sold;
    QLabel *sold_2;

    void setupUi(QDialog *windowAdunare)
    {
        if (windowAdunare->objectName().isEmpty())
            windowAdunare->setObjectName(QString::fromUtf8("windowAdunare"));
        windowAdunare->resize(800, 600);
        windowAdunare->setMinimumSize(QSize(800, 600));
        windowAdunare->setMaximumSize(QSize(800, 600));
        widget = new QWidget(windowAdunare);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-1, -1, 800, 600));
        widget->setStyleSheet(QString::fromUtf8("   .QWidget{background-image:url( C:/Users/marcu/Desktop/ACL/AncientClient/Media/poza1.jpg); background-position: center; }"));
        frame = new QFrame(widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 20, 201, 241));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0,80%);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        res = new QLabel(frame);
        res->setObjectName(QString::fromUtf8("res"));
        res->setGeometry(QRect(75, 10, 61, 31));
        res->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255,0%);"));
        Galbeni = new QLabel(frame);
        Galbeni->setObjectName(QString::fromUtf8("Galbeni"));
        Galbeni->setGeometry(QRect(10, 40, 181, 31));
        Galbeni->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255,0%);"));
        Muncitori = new QLabel(frame);
        Muncitori->setObjectName(QString::fromUtf8("Muncitori"));
        Muncitori->setGeometry(QRect(10, 80, 181, 31));
        Muncitori->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255,0%);"));
        Soldati = new QLabel(frame);
        Soldati->setObjectName(QString::fromUtf8("Soldati"));
        Soldati->setGeometry(QRect(10, 120, 181, 31));
        Soldati->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255,0%);"));
        Cavalerie = new QLabel(frame);
        Cavalerie->setObjectName(QString::fromUtf8("Cavalerie"));
        Cavalerie->setGeometry(QRect(10, 160, 181, 31));
        Cavalerie->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255,0%);"));
        Medici = new QLabel(frame);
        Medici->setObjectName(QString::fromUtf8("Medici"));
        Medici->setGeometry(QRect(10, 200, 181, 31));
        Medici->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255,0%);"));
        LogInB = new QPushButton(widget);
        LogInB->setObjectName(QString::fromUtf8("LogInB"));
        LogInB->setGeometry(QRect(660, 20, 101, 31));
        LogInB->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        Shop = new QPushButton(widget);
        Shop->setObjectName(QString::fromUtf8("Shop"));
        Shop->setGeometry(QRect(500, 20, 101, 31));
        Shop->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        Provoaca = new QPushButton(widget);
        Provoaca->setObjectName(QString::fromUtf8("Provoaca"));
        Provoaca->setGeometry(QRect(340, 20, 101, 31));
        Provoaca->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        frame_2 = new QFrame(widget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(280, 241, 451, 241));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0,80%);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 120, 311, 41));
        lineEdit->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255)"));
        Shop_2 = new QPushButton(frame_2);
        Shop_2->setObjectName(QString::fromUtf8("Shop_2"));
        Shop_2->setGeometry(QRect(180, 200, 101, 31));
        Shop_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        Banner = new QLabel(frame_2);
        Banner->setObjectName(QString::fromUtf8("Banner"));
        Banner->setGeometry(QRect(70, 50, 341, 31));
        Banner->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255,0%);"));
        ScSoldati = new QPushButton(widget);
        ScSoldati->setObjectName(QString::fromUtf8("ScSoldati"));
        ScSoldati->setGeometry(QRect(60, 270, 121, 101));
        QFont font;
        font.setBold(true);
        ScSoldati->setFont(font);
        ScSoldati->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-image:url(C:/Users/marcu/Desktop/ACL/AncientClient/Media/poza4.jpg);\n"
""));
        ScMedici = new QPushButton(widget);
        ScMedici->setObjectName(QString::fromUtf8("ScMedici"));
        ScMedici->setGeometry(QRect(60, 380, 121, 101));
        ScMedici->setFont(font);
        ScMedici->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-image:url(C:/Users/marcu/Desktop/ACL/AncientClient/Media/poza5.jpg);\n"
""));
        sold = new QLabel(widget);
        sold->setObjectName(QString::fromUtf8("sold"));
        sold->setGeometry(QRect(60, 310, 121, 20));
        sold->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        sold->setAlignment(Qt::AlignCenter);
        sold_2 = new QLabel(widget);
        sold_2->setObjectName(QString::fromUtf8("sold_2"));
        sold_2->setGeometry(QRect(60, 420, 121, 20));
        sold_2->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        sold_2->setAlignment(Qt::AlignCenter);
        frame_2->raise();
        frame->raise();
        LogInB->raise();
        Shop->raise();
        Provoaca->raise();
        ScSoldati->raise();
        ScMedici->raise();
        sold->raise();
        sold_2->raise();

        retranslateUi(windowAdunare);

        QMetaObject::connectSlotsByName(windowAdunare);
    } // setupUi

    void retranslateUi(QDialog *windowAdunare)
    {
        windowAdunare->setWindowTitle(QCoreApplication::translate("windowAdunare", "Dialog", nullptr));
        res->setText(QCoreApplication::translate("windowAdunare", "Resurse:", nullptr));
        Galbeni->setText(QCoreApplication::translate("windowAdunare", "Galbeni: 0", nullptr));
        Muncitori->setText(QCoreApplication::translate("windowAdunare", "Muncitori: 0", nullptr));
        Soldati->setText(QCoreApplication::translate("windowAdunare", "Soldati: 0", nullptr));
        Cavalerie->setText(QCoreApplication::translate("windowAdunare", "Cavalerie: 0", nullptr));
        Medici->setText(QCoreApplication::translate("windowAdunare", "Medici: 0", nullptr));
        LogInB->setText(QCoreApplication::translate("windowAdunare", "Exit", nullptr));
        Shop->setText(QCoreApplication::translate("windowAdunare", "Shop", nullptr));
        Provoaca->setText(QCoreApplication::translate("windowAdunare", "Duel", nullptr));
        Shop_2->setText(QCoreApplication::translate("windowAdunare", "Provoaca", nullptr));
        Banner->setText(QCoreApplication::translate("windowAdunare", "Introdu numele jucatorului pe care vrei sa il provoci", nullptr));
        ScSoldati->setText(QString());
        ScMedici->setText(QString());
        sold->setText(QCoreApplication::translate("windowAdunare", "Instruire soldati", nullptr));
        sold_2->setText(QCoreApplication::translate("windowAdunare", "Instruire medici", nullptr));
    } // retranslateUi

};

namespace Ui {
    class windowAdunare: public Ui_windowAdunare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWADUNARE_H
