#ifndef WINDOWADUNARE_H
#define WINDOWADUNARE_H
#include "CResurse.h"
#include <QTimer>
#include <QDialog>
#include <QListWidgetItem>


namespace Ui {
class windowAdunare;
}

class windowAdunare : public QDialog
{
    Q_OBJECT

private:
    int nrMed=0;
    int nrSold=0;
    int nrCav=0;

    QTimer *timerMed = new QTimer(this);
    QTimer *timerCav =new QTimer(this);
    QTimer *timerSold = new QTimer(this);


public:
    explicit windowAdunare(QWidget *parent = nullptr);
    ~windowAdunare();
    void setTexts(CResurse res);
    static void addAndSet();
    void setShowText(QString s);
    void addMed();
    void addCav();
    void addSold();

private slots:
    void on_LogInB_clicked();

    void on_Shop_clicked();

    void on_ScSoldati_clicked();

    void on_ScCav_clicked();

    void on_ScMedici_clicked();

    void on_Duel_clicked();

    void on_listWidget_itemPressed(QListWidgetItem *item);

    void on_Provoaca_clicked();

    void on_Refuz_clicked();

    void on_Accept_clicked();


private:
    Ui::windowAdunare *ui;
public:
    bool isV();
    void changeStyleSheet();
    void showBuildings();
    void setPlayers(QString s);
    void maProvoci(QString s);
    void aRefuzat();
    void hideThings();
    void setPlayer();
    void updateWL();
};

#endif // WINDOWADUNARE_H
