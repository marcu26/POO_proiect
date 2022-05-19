#include "windowadunare.h"
#include "ui_windowadunare.h"
#include "Singleton.h"
#include <QListWidgetItem>
#include <QtDebug>


void windowAdunare::addAndSet()
{
    Singleton::getInstance().addandset();
}

void windowAdunare::addSold()
{
     Singleton::getInstance().getCl().getResurse().getSold().modifyNumber(nrSold);
     Singleton::getInstance().getCl().sendInfoToServer(Singleton::getInstance().getCl().getResurse().getResourcesString());
     nrSold=0;
     this->ui->nrSold->setText("Nr: "+QString::number(nrSold));
}

void windowAdunare::addMed()
{
     Singleton::getInstance().getCl().getResurse().getMed().modifyNumber(nrMed);
     Singleton::getInstance().getCl().sendInfoToServer(Singleton::getInstance().getCl().getResurse().getResourcesString());
     nrMed=0;
     this->ui->nrMed->setText("Nr: "+QString::number(nrMed));
}

void windowAdunare::addCav()
{
     Singleton::getInstance().getCl().getResurse().getCav().modifyNumber(nrCav);
     Singleton::getInstance().getCl().sendInfoToServer(Singleton::getInstance().getCl().getResurse().getResourcesString());
     nrCav=0;
     this->ui->nrCav->setText("Nr: "+QString::number(nrCav));
}

windowAdunare::windowAdunare(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowAdunare)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
      timer->start(2000);
    connect(timer,&QTimer::timeout, this, &windowAdunare::addAndSet);
    connect(timerMed, &QTimer::timeout, this, &windowAdunare::addMed);
    connect(timerCav, &QTimer::timeout, this, &windowAdunare::addCav);
    connect(timerSold, &QTimer::timeout, this, &windowAdunare::addSold);
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
    this->ui->players->hide();
    this->ui->nrCav->hide();
    this->ui->nrMed->hide();
    this->ui->nrSold->hide();
}

windowAdunare::~windowAdunare()
{
    delete ui;
}

void windowAdunare::setTexts(CResurse res)
{
   QString num=QString::number(res.getWorker().getNumber());
   ui->Muncitori->setText("Munictori: "+num);

   num=QString::number(res.getSold().getNumber());
   ui->Soldati->setText("Soldati: "+num);

   num=QString::number(res.getCav().getNumber());
   ui->Cavalerie->setText("Cavalerie: "+num);

   num=QString::number(res.getMed().getNumber());
   ui->Medici->setText("Medici: "+num);

   num=QString::number(res.getGalbeni());
   ui->Galbeni->setText("Galbeni: "+num);
}

void windowAdunare::on_LogInB_clicked()
{
   this->hide();
   Singleton::getInstance().getCl().sendInfoToServer(Singleton::getInstance().getCl().getResurse().getResourcesString());
   Singleton::getInstance().showMW();
   this->hideThings();
   Singleton::getInstance().getCl().clearSocket();
   Singleton::getInstance().getCl().sendInfoToServer("k");
}

bool windowAdunare::isV()
{
    return this->isVisible();
}

void windowAdunare::changeStyleSheet()
{
    QString func;
    func=".QWidget{background-image:url("+Singleton::getInstance().getPath()+"/Media/poza1.jpg); background-position: center; }";
    this->ui->widget->setStyleSheet(func);
    func="background-image:url("+Singleton::getInstance().getPath()+"/Media/poza4.jpg);"+"background-color: rgba(0, 0, 0,80%);border-style: solid; border-width: 4px;border-radius: 10px;border-color:black;";
    this->ui->ScSoldati->setStyleSheet(func);
    func="background-image:url("+Singleton::getInstance().getPath()+"/Media/poza5.jpg);"+"background-color: rgba(0, 0, 0,80%);border-style: solid; border-width: 4px;border-radius: 10px;border-color:black;";
    this->ui->ScMedici->setStyleSheet(func);
    func="background-image:url("+Singleton::getInstance().getPath()+"/Media/poza8.jpg);"+"background-color: rgba(0, 0, 0,80%);border-style: solid; border-width: 4px;border-radius: 10px;border-color:black;";
    this->ui->ScCav->setStyleSheet(func);
}

void windowAdunare::showBuildings()
{
    this->changeStyleSheet();
    if(Singleton::getInstance().getCl().getResurse().getMili()==1)
    {
        this->ui->ScCav->show();
        this->ui->sold->show();
        this->ui->nrCav->show();

        this->ui->ScSoldati->show();
        this->ui->sold_3->show();
        this->ui->nrSold->show();
    }
    if(Singleton::getInstance().getCl().getResurse().getMedic()==1)
    {
        this->ui->ScMedici->show();
        this->ui->sold_2->show();
        this->ui->nrMed->show();
    }

}

void windowAdunare::on_Shop_clicked()
{
    Singleton::getInstance().showSHW();
}


void windowAdunare::on_ScSoldati_clicked()
{
    if(Singleton::getInstance().getCl().getResurse().getGalbeni()>=30 && nrSold < 5)
    {
        Singleton::getInstance().getCl().getResurse().subGalbeni(30);
        nrSold++;
        this->ui->nrSold->setText("Nr: "+QString::number(nrSold));
        timerSold->start(3000);
    }
}


void windowAdunare::on_ScCav_clicked()
{
    if(Singleton::getInstance().getCl().getResurse().getGalbeni()>=50 && nrCav<5)
    {
        Singleton::getInstance().getCl().getResurse().subGalbeni(50);
        nrCav++;
        this->ui->nrCav->setText("Nr: "+QString::number(nrCav));
        timerCav->start(4500);
    }
}


void windowAdunare::on_ScMedici_clicked()
{
    if(Singleton::getInstance().getCl().getResurse().getGalbeni()>=40 && nrMed<3)
    {
        Singleton::getInstance().getCl().getResurse().subGalbeni(40);
        nrMed++;
        this->ui->nrMed->setText("Nr: "+QString::number(nrMed));
        timerMed->start(3000);
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
    {
        this->ui->listWidget->hide();
        this->ui->players->show();
    }
    else
          this->ui->players->hide();

}


void windowAdunare::on_Duel_clicked()
{
   if(this->ui->listWidget->isVisible()==false)
   {
    this->ui->listWidget->clear();
    Singleton::getInstance().getCl().sendInfoToServer("4");

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
    Singleton::getInstance().setDusman(this->ui->lineEdit->text());
    if(this->ui->lineEdit->text()!="")
    {
    s="5 ";
    s+=this->ui->lineEdit->text();
    Singleton::getInstance().getCl().sendInfoToServer(s);
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
     Singleton::getInstance().getCl().sendInfoToServer("9 "+Singleton::getInstance().getDusman()+" 0");
     this->ui->provocare->hide();
}

void windowAdunare::aRefuzat()
{
    this->ui->user_refuz->setText("Jucatorul "+Singleton::getInstance().getDusman()+" a refuzat duelul");
    this->ui->user_refuz->show();
}

//ai castigat/ai pierdut
void windowAdunare::setShowText(QString s)
{
    this->ui->user_refuz->setText(s);
    this->ui->user_refuz->show();
}


void windowAdunare::on_Accept_clicked()
{
    Singleton::getInstance().showATW();
    Singleton::getInstance().getCl().sendInfoToServer("9 "+Singleton::getInstance().getDusman()+" 1");
    this->ui->provocare->hide();
    this->hide();
    Singleton::getInstance().getCl().clearSocket();
    Singleton::getInstance().getCl().sendInfoToServer("a "+Singleton::getInstance().getDusman());
}

void windowAdunare::hideThings()
{
    this->ui->user_refuz->hide();
    this->ui->provocare->hide();
    this->ui->ScSoldati->hide();
    this->ui->ScCav->hide();
    this->ui->sold->hide();
    this->ui->sold_2->hide();
    this->ui->sold_3->hide();
    this->ui->listWidget->hide();
    this->ui->lineEdit->setEnabled(false);
    this->ui->user_refuz->hide();
    this->ui->provocare->hide();
    this->ui->players->hide();
    this->ui->nrCav->hide();
    this->ui->nrMed->hide();
    this->ui->nrSold->hide();
}

void windowAdunare::setPlayer()
{
     this->ui->player->setText("User: "+Singleton::getInstance().getCl().getUName());
}

void windowAdunare::updateWL()
{
    this->ui->wins->setText("Castiguri: "+QString::number(Singleton::getInstance().getWins()));
    this->ui->loses->setText("Infrangeri: "+QString::number(Singleton::getInstance().getLoses()));
}
