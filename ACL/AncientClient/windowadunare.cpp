#include "windowadunare.h"
#include "ui_windowadunare.h"
#include "Singleton.h"
#include <QElapsedTimer>
#include <QTimer>

void windowAdunare::addAndSet()
{
    Singleton::getInstance().addandset();

}


windowAdunare::windowAdunare(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowAdunare)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &windowAdunare::addAndSet);
    timer->start(2000);
}

windowAdunare::~windowAdunare()
{
    delete ui;
}

void windowAdunare::setTexts(CResurse res)
{
   QString num=QString::number(res.worker.getNumber());
   ui->Muncitori->setText("Munictori: "+num);

   num=QString::number(res.sold.getNumber());
   ui->Soldati->setText("Soldati: "+num);

   num=QString::number(res.cav.getNumber());
   ui->Cavalerie->setText("Cavalerie: "+num);

   num=QString::number(res.med.getNumber());
   ui->Medici->setText("Medici: "+num);

   num=QString::number(res.galbeni);
   ui->Galbeni->setText("Galbeni: "+num);
}

void windowAdunare::on_LogInB_clicked()
{
   this->hide();
   Singleton::getInstance().cl.sendInfoToServer(Singleton::getInstance().cl.resurse.getResourcesString());
   Singleton::getInstance().showMW();
}

bool windowAdunare::isV()
{
    return this->isVisible();
}

