#ifndef WINDOWADUNARE_H
#define WINDOWADUNARE_H
#include "CResurse.h"

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class windowAdunare;
}

class windowAdunare : public QDialog
{
    Q_OBJECT

public:
    explicit windowAdunare(QWidget *parent = nullptr);
    ~windowAdunare();
    void setTexts(CResurse res);
    static void addAndSet();

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

private:
    Ui::windowAdunare *ui;
public:
    bool isV();
    void changeStyleSheet();
    void showBuildings();
    void setPlayers(QString s);
    void maProvoci(QString s);
    void aRefuzat();
};

#endif // WINDOWADUNARE_H
