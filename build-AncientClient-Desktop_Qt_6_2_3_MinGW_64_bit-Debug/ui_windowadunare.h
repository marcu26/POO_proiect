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
#include <QtWidgets/QListWidget>
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
    QPushButton *Duel;
    QFrame *frame_2;
    QLineEdit *lineEdit;
    QPushButton *Provoaca;
    QLabel *Banner;
    QPushButton *ScSoldati;
    QPushButton *ScMedici;
    QLabel *sold;
    QLabel *sold_2;
    QPushButton *ScCav;
    QLabel *sold_3;
    QFrame *provocare;
    QPushButton *Accept;
    QPushButton *Refuz;
    QLabel *user;
    QLabel *user_refuz;
    QListWidget *listWidget;

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
        widget->setStyleSheet(QString::fromUtf8(""));
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
        LogInB->setGeometry(QRect(660, 20, 101, 41));
        LogInB->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;"));
        Shop = new QPushButton(widget);
        Shop->setObjectName(QString::fromUtf8("Shop"));
        Shop->setGeometry(QRect(500, 20, 101, 41));
        Shop->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;"));
        Duel = new QPushButton(widget);
        Duel->setObjectName(QString::fromUtf8("Duel"));
        Duel->setGeometry(QRect(340, 20, 101, 41));
        Duel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;"));
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
        Provoaca = new QPushButton(frame_2);
        Provoaca->setObjectName(QString::fromUtf8("Provoaca"));
        Provoaca->setGeometry(QRect(180, 190, 101, 41));
        Provoaca->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;"));
        Banner = new QLabel(frame_2);
        Banner->setObjectName(QString::fromUtf8("Banner"));
        Banner->setGeometry(QRect(70, 50, 341, 31));
        Banner->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255,0%);"));
        ScSoldati = new QPushButton(widget);
        ScSoldati->setObjectName(QString::fromUtf8("ScSoldati"));
        ScSoldati->setGeometry(QRect(60, 270, 121, 61));
        QFont font;
        font.setBold(true);
        ScSoldati->setFont(font);
        ScSoldati->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgba(0, 0, 0,80%);\n"
"border-style: solid;\n"
"border-width: 4px;\n"
"border-radius: 10px;\n"
"border-color:black;"));
        ScMedici = new QPushButton(widget);
        ScMedici->setObjectName(QString::fromUtf8("ScMedici"));
        ScMedici->setGeometry(QRect(60, 410, 121, 61));
        ScMedici->setFont(font);
        ScMedici->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"border-style: solid;\n"
"border-width: 4px;\n"
"border-radius: 10px;\n"
"border-color:black"));
        sold = new QLabel(widget);
        sold->setObjectName(QString::fromUtf8("sold"));
        sold->setGeometry(QRect(60, 290, 121, 20));
        sold->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        sold->setAlignment(Qt::AlignCenter);
        sold_2 = new QLabel(widget);
        sold_2->setObjectName(QString::fromUtf8("sold_2"));
        sold_2->setGeometry(QRect(60, 430, 121, 20));
        sold_2->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        sold_2->setAlignment(Qt::AlignCenter);
        ScCav = new QPushButton(widget);
        ScCav->setObjectName(QString::fromUtf8("ScCav"));
        ScCav->setGeometry(QRect(60, 340, 121, 61));
        ScCav->setFont(font);
        ScCav->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"border-style: solid;\n"
"border-width: 4px;\n"
"border-radius: 10px;\n"
"border-color:black"));
        sold_3 = new QLabel(widget);
        sold_3->setObjectName(QString::fromUtf8("sold_3"));
        sold_3->setGeometry(QRect(60, 360, 121, 20));
        sold_3->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);"));
        sold_3->setAlignment(Qt::AlignCenter);
        provocare = new QFrame(widget);
        provocare->setObjectName(QString::fromUtf8("provocare"));
        provocare->setGeometry(QRect(390, 110, 441, 201));
        provocare->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0,80%);"));
        provocare->setFrameShape(QFrame::StyledPanel);
        provocare->setFrameShadow(QFrame::Raised);
        Accept = new QPushButton(provocare);
        Accept->setObjectName(QString::fromUtf8("Accept"));
        Accept->setGeometry(QRect(70, 120, 101, 41));
        Accept->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;"));
        Refuz = new QPushButton(provocare);
        Refuz->setObjectName(QString::fromUtf8("Refuz"));
        Refuz->setGeometry(QRect(260, 120, 101, 41));
        Refuz->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;"));
        user = new QLabel(provocare);
        user->setObjectName(QString::fromUtf8("user"));
        user->setGeometry(QRect(0, 30, 441, 31));
        user->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,0%);"));
        user->setAlignment(Qt::AlignCenter);
        user_refuz = new QLabel(widget);
        user_refuz->setObjectName(QString::fromUtf8("user_refuz"));
        user_refuz->setGeometry(QRect(280, 70, 441, 31));
        user_refuz->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: rgb(255, 0, 0);"));
        user_refuz->setAlignment(Qt::AlignCenter);
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(200, 230, 261, 361));
        listWidget->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0, 0, 0,80%);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;"));
        frame_2->raise();
        frame->raise();
        LogInB->raise();
        Shop->raise();
        Duel->raise();
        ScSoldati->raise();
        ScMedici->raise();
        sold->raise();
        sold_2->raise();
        ScCav->raise();
        sold_3->raise();
        provocare->raise();
        user_refuz->raise();
        listWidget->raise();

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
        Duel->setText(QCoreApplication::translate("windowAdunare", "Duel", nullptr));
        Provoaca->setText(QCoreApplication::translate("windowAdunare", "Provoaca", nullptr));
        Banner->setText(QCoreApplication::translate("windowAdunare", "Introdu numele jucatorului pe care vrei sa il provoci", nullptr));
        ScSoldati->setText(QString());
        ScMedici->setText(QString());
        sold->setText(QCoreApplication::translate("windowAdunare", "Instruire soldati", nullptr));
        sold_2->setText(QCoreApplication::translate("windowAdunare", "Instruire medici", nullptr));
        ScCav->setText(QString());
        sold_3->setText(QCoreApplication::translate("windowAdunare", "Instruire cavalerie", nullptr));
        Accept->setText(QCoreApplication::translate("windowAdunare", "Accept", nullptr));
        Refuz->setText(QCoreApplication::translate("windowAdunare", "Refuz", nullptr));
        user->setText(QCoreApplication::translate("windowAdunare", "Jucatorul x v-a provocat la duel", nullptr));
        user_refuz->setText(QCoreApplication::translate("windowAdunare", "Jucatorul x v-a refuzat duelul", nullptr));
    } // retranslateUi

};

namespace Ui {
    class windowAdunare: public Ui_windowAdunare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWADUNARE_H
