#include "windowattack.h"
#include "ui_windowattack.h"
#include "Singleton.h"
#include "QTimer"

windowAttack::windowAttack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowAttack)
{
    ui->setupUi(this);
    this->ui->ExitFrame->hide();
    this->ui->pauseFr->hide();
    this->ui->FrameAtc->hide();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &windowAttack::endPause);
    timer2 = new QTimer(this);
    connect(timer2, &QTimer::timeout, this, &windowAttack::makePauseAvalabile);
    this->ui->labelFara->hide();
}

windowAttack::~windowAttack()
{
    delete ui;
}

void windowAttack::changeStyleSheet()
{
    QString func;
    func=".QWidget{background-image:url("+Singleton::getInstance().getPath()+"/Media/poza3.png); background-position: center; }";
    this->ui->widget->setStyleSheet(func);

    func="background-image:url("+Singleton::getInstance().getPath()+"/Media/poza7.jpg);"+"background-color: rgba(0, 0, 0,80%);border-style: solid; border-width: 3px;border-radius: 10px;border-color:black;";
    this->ui->useSold->setStyleSheet(func);

    func="background-image:url("+Singleton::getInstance().getPath()+"/Media/poza6.png);"+"background-color: rgba(0, 0, 0,80%);border-style: solid; border-width: 3px;border-radius: 10px;border-color:black;";
    this->ui->useCav->setStyleSheet(func);

    func="background-image:url("+Singleton::getInstance().getPath()+"/Media/poza4.png);"+"background-color: rgba(0, 0, 0,80%);border-style: solid; border-width: 3px;border-radius: 10px;border-color:black;";
    this->ui->useMed->setStyleSheet(func);

    effect.setSource(QUrl::fromLocalFile(Singleton::getInstance().getPath()+"/Media/Tonghioiu.wav"));
    effect.setLoopCount(1);
    effect.setVolume(0.25f);


    effect1.setSource(QUrl::fromLocalFile(Singleton::getInstance().getPath()+"/Media/Mihnea.wav"));
    effect1.setLoopCount(1);
    effect1.setVolume(0.25f);


    effect2.setSource(QUrl::fromLocalFile(Singleton::getInstance().getPath()+"/Media/Marcu.wav"));
    effect2.setLoopCount(1);
    effect2.setVolume(0.25f);

}

void windowAttack::setTexts()
{
    this->ui->SoldI->setText("Soldati: "+QString::number(Singleton::getInstance().getCl().getResurse().getSold().getNumber()));
    this->ui->CavI->setText("Cavalerie: "+QString::number(Singleton::getInstance().getCl().getResurse().getCav().getNumber()));
    this->ui->MedI->setText("Medici: "+QString::number(Singleton::getInstance().getCl().getResurse().getMed().getNumber()));

    this->ui->SoldC->setText("Soldati: "+QString::number(Singleton::getInstance().getCl().getResurse().getSold().getNumber()));
    this->ui->CavC->setText("Cavalerie: "+QString::number(Singleton::getInstance().getCl().getResurse().getCav().getNumber()));
    this->ui->MedC->setText("Medici: "+QString::number(Singleton::getInstance().getCl().getResurse().getMed().getNumber()));

    soldC=Singleton::getInstance().getCl().getResurse().getSold().getNumber();
    cavC=Singleton::getInstance().getCl().getResurse().getCav().getNumber();
    medC=Singleton::getInstance().getCl().getResurse().getMed().getNumber();

    this->ui->dusman->setText(Singleton::getInstance().getDusman());
}

void windowAttack::setMyText(QString text)
{
    QStringList l=text.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    this->ui->SoldC->setText("Soldati: "+l[1]);
    this->ui->CavC->setText("Cavalerie: "+l[2]);
    this->ui->MedC->setText("Medici: "+l[3]);
    soldC=l[1].toInt();
    cavC=l[2].toInt();
    medC=l[3].toInt();
}


void windowAttack::setTextDusman(QString s)
{
    QStringList l=s.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    this->ui->SoldF->setText("Soldati: "+l[1]);
    this->ui->CavF->setText("Cavalerie: "+l[2]);
    this->ui->MedF->setText("Medici: "+l[3]);

    soldD=l[1].toInt();
    cavD=l[2].toInt();
    medD=l[3].toInt();
}

void windowAttack::on_Exit_clicked()
{
    this->ui->ExitFrame->show();
}


void windowAttack::on_Nu_clicked()
{
    this->ui->ExitFrame->hide();
}


void windowAttack::on_Da_clicked()
{
    this->hide();
    Singleton::getInstance().showAW();
    this->ui->ExitFrame->hide();
    this->ui->pauseFr->hide();
    Singleton::getInstance().getCl().sendInfoToServer("q "+Singleton::getInstance().getDusman());
}


void windowAttack::on_useSold_clicked()
{
    if(isMyTurn==1 && soldC>0)
    {
    effect.play();
    trupa=1;
    this->ui->trupa->setText("Folosesti soldatii");
    this->ui->FrameAtc->show();
    act="b ";
    this->ui->labelFara->hide();
    }

    else if(isMyTurn==1 && soldC==0)
    {
        this->ui->labelFara->setText("Nu mai ai trupe din categoria soldati");
        this->ui->labelFara->show();
    }

}


void windowAttack::on_useCav_clicked()
{
    if(isMyTurn==1 && cavC>0){
     effect2.play();
     trupa=2;
     this->ui->trupa->setText("Folosesti cavaleria");
     this->ui->FrameAtc->show();
     act="b ";
     this->ui->labelFara->hide();
    }
    else if(isMyTurn==1 && cavC==0)
    {
        this->ui->labelFara->setText("Nu mai ai trupe din categoria cavalerie");
        this->ui->labelFara->show();
    }

}


void windowAttack::on_useMed_clicked()
{
    if(isMyTurn==1 && medC>0)
    {
     effect1.play();
     trupa=3;
     this->ui->trupa->setText("Folosesti medicii");
     this->ui->FrameAtc->show();
     act="m ";
     this->ui->labelFara->hide();
    }

    else if(isMyTurn==1 && medC==0)
    {
        this->ui->labelFara->setText("Nu mai ai trupe din categoria medici");
        this->ui->labelFara->show();
    }
}


void windowAttack::on_Pause_clicked()
{
    if(canPause==1)
    {
    this->ui->pauseFr->show();
    this->ui->FrameAtc->hide();
    Singleton::getInstance().getCl().sendInfoToServer("8 "+Singleton::getInstance().getDusman());
    timer->start(5000);
    canPause=0;
    timer2->start(10000);
    }
}


void windowAttack::on_close_clicked()
{
    this->ui->pauseFr->hide();
    Singleton::getInstance().getCl().sendInfoToServer("e "+Singleton::getInstance().getDusman());
}

void windowAttack::endPause()
{
    this->ui->pauseFr->hide();
    Singleton::getInstance().getCl().sendInfoToServer("e "+Singleton::getInstance().getDusman());
}


void windowAttack::on_Cancel_clicked()
{
    trupa=0;
    this->ui->FrameAtc->hide();
}


void windowAttack::on_SoldA_clicked()
{
    if(soldD>0){
    Singleton::getInstance().getCl().sendInfoToServer(act+QString::number(trupa)+" "+Singleton::getInstance().getDusman()+" 1");
    this->ui->FrameAtc->hide();
    isMyTurn=0;
    this->ui->tura->setStyleSheet("background-color:rgb(85,0,0)");}
}


void windowAttack::on_CavA_clicked()
{
    if(cavD>0){
    Singleton::getInstance().getCl().sendInfoToServer(act+QString::number(trupa)+" "+Singleton::getInstance().getDusman()+" 2");
    this->ui->FrameAtc->hide();
    isMyTurn=0;
     this->ui->tura->setStyleSheet("background-color:rgb(85,0,0)");}
}


void windowAttack::on_MedA_clicked()
{
    Singleton::getInstance().getCl().sendInfoToServer(act+QString::number(trupa)+" "+Singleton::getInstance().getDusman()+" 3");
    this->ui->FrameAtc->hide();
    isMyTurn=0;
    this->ui->tura->setStyleSheet("background-color:rgb(85,0,0)");
}

void windowAttack::punePauza()
{

    this->ui->pauseFr->show();
    this->ui->close->hide();

}

void windowAttack::endPause2()
{
    this->ui->close->show();
    this->ui->pauseFr->hide();
}

void windowAttack::makePauseAvalabile()
{
    canPause=1;
}

void windowAttack::setTuraBox(QString s)
{
    this->ui->tura->setStyleSheet(s);
}

void windowAttack::setPlayer()
{
    this->ui->player->setText("User: "+Singleton::getInstance().getCl().getUName());
}
