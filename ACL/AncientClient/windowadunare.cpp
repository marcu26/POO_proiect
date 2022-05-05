#include "windowadunare.h"
#include "ui_windowadunare.h"
#include "Singleton.h"
#include <QElapsedTimer>
#include <QTimer>
#include <QListWidgetItem>

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
    this->ui->ScMedici->hide();
    this->ui->ScSoldati->hide();
    this->ui->ScCav->hide();
    this->ui->sold->hide();
    this->ui->sold_2->hide();
    this->ui->sold_3->hide();
    this->ui->listWidget->hide();
    this->ui->lineEdit->setEnabled(false);
    this->ui->user_refuz->hide();
    this->ui->provocare->hide();
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
   this->ui->ScMedici->hide();
   this->ui->ScSoldati->hide();
   this->ui->ScCav->hide();
   this->ui->sold->hide();
   this->ui->sold_2->hide();
   this->ui->sold_3->hide();
   this->ui->provocare->hide();
   this->ui->Refuz->hide();
}

bool windowAdunare::isV()
{
    return this->isVisible();
}

void windowAdunare::changeStyleSheet()
{
    QString func;
    func=".QWidget{background-image:url("+Singleton::getInstance().path+"/Media/poza1.jpg); background-position: center; }";
    this->ui->widget->setStyleSheet(func);
    func="background-image:url("+Singleton::getInstance().path+"/Media/poza4.jpg);"+"background-color: rgba(0, 0, 0,80%);border-style: solid; border-width: 4px;border-radius: 10px;border-color:black;";
    this->ui->ScSoldati->setStyleSheet(func);
    func="background-image:url("+Singleton::getInstance().path+"/Media/poza5.jpg);"+"background-color: rgba(0, 0, 0,80%);border-style: solid; border-width: 4px;border-radius: 10px;border-color:black;";
    this->ui->ScMedici->setStyleSheet(func);
    func="background-image:url("+Singleton::getInstance().path+"/Media/poza6.jpg);"+"background-color: rgba(0, 0, 0,80%);border-style: solid; border-width: 4px;border-radius: 10px;border-color:black;";
    this->ui->ScCav->setStyleSheet(func);

}

void windowAdunare::showBuildings()
{
    this->changeStyleSheet();
    if(Singleton::getInstance().cl.resurse.aMili==1)
    {
        this->ui->ScCav->show();
        this->ui->sold->show();
        this->ui->ScSoldati->show();
        this->ui->sold_3->show();
    }
    if(Singleton::getInstance().cl.resurse.aMedic==1)
    {
        this->ui->ScMedici->show();
        this->ui->sold_2->show();
    }
}

void windowAdunare::on_Shop_clicked()
{
    Singleton::getInstance().showSHW();
}


void windowAdunare::on_ScSoldati_clicked()
{
    if(Singleton::getInstance().cl.resurse.getGalbeni()>=30)
    {
        Singleton::getInstance().cl.resurse.subGalbeni(30);
        Singleton::getInstance().cl.resurse.sold.modifyNumber(1);
        Singleton::getInstance().showAW();
        Singleton::getInstance().cl.sendInfoToServer(Singleton::getInstance().cl.resurse.getResourcesString());
    }
}


void windowAdunare::on_ScCav_clicked()
{
    if(Singleton::getInstance().cl.resurse.getGalbeni()>=50)
    {
        Singleton::getInstance().cl.resurse.subGalbeni(50);
        Singleton::getInstance().cl.resurse.cav.modifyNumber(1);
        Singleton::getInstance().showAW();
        Singleton::getInstance().cl.sendInfoToServer(Singleton::getInstance().cl.resurse.getResourcesString());
    }
}


void windowAdunare::on_ScMedici_clicked()
{
    if(Singleton::getInstance().cl.resurse.getGalbeni()>=40)
    {
        Singleton::getInstance().cl.resurse.subGalbeni(40);
        Singleton::getInstance().cl.resurse.med.modifyNumber(1);
        Singleton::getInstance().showAW();
        Singleton::getInstance().cl.sendInfoToServer(Singleton::getInstance().cl.resurse.getResourcesString());
    }
}

void windowAdunare::setPlayers(QString s)
{
    QStringList l = s.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    for(auto &it:l)
    {
        if(it!="4")
        {
            this->ui->listWidget->addItem(it);
        }
    }
     this->ui->listWidget->show();
    if(this->ui->listWidget->count()==0)
        this->ui->listWidget->hide();
}


void windowAdunare::on_Duel_clicked()
{
   if(this->ui->listWidget->isVisible()==false)
   {
    this->ui->listWidget->clear();
    Singleton::getInstance().cl.sendInfoToServer("4");

   }
}


void windowAdunare::on_listWidget_itemPressed(QListWidgetItem *item)
{
    this->ui->lineEdit->setText(item->text());
    this->ui->listWidget->hide();
}




void windowAdunare::on_Provoaca_clicked()
{
    QString s;
    if(this->ui->lineEdit->text()!="")
    {
    s="5 ";
    s+=this->ui->lineEdit->text();
    Singleton::getInstance().cl.sendInfoToServer(s);
    }

}

void windowAdunare::maProvoci(QString s)
{
    QStringList l = s.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    Singleton::getInstance().setDusman(l[1]);
    this->ui->user->setText("Jucatorul " +l[1]+" v-a provocat la duel");
    this->ui->provocare->show();

}


void windowAdunare::on_Refuz_clicked()
{
     Singleton::getInstance().cl.sendInfoToServer("9 "+Singleton::getInstance().getDusman()+" 0");
     this->ui->provocare->hide();
}

void windowAdunare::aRefuzat()
{
    this->ui->user_refuz->setText("Jucatorul "+Singleton::getInstance().getDusman()+" a refuzat duelul");
    this->ui->user_refuz->show();
}
