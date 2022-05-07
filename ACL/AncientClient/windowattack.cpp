#include "windowattack.h"
#include "ui_windowattack.h"
#include "Singleton.h"

windowAttack::windowAttack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowAttack)
{
    ui->setupUi(this);
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

    func="background-image:url("+Singleton::getInstance().getPath()+"/Media/poza6.jpg);"+"background-color: rgba(0, 0, 0,80%);border-style: solid; border-width: 3px;border-radius: 10px;border-color:black;";
    this->ui->useCav->setStyleSheet(func);

    func="background-image:url("+Singleton::getInstance().getPath()+"/Media/poza4.png);"+"background-color: rgba(0, 0, 0,80%);border-style: solid; border-width: 3px;border-radius: 10px;border-color:black;";
    this->ui->useMed->setStyleSheet(func);
}

void windowAttack::setTexts()
{
    this->ui->SoldI->setText("Soldati: "+QString::number(Singleton::getInstance().getCl().getResurse().getSold().getNumber()));
    this->ui->CavI->setText("Cavalerie: "+QString::number(Singleton::getInstance().getCl().getResurse().getCav().getNumber()));
    this->ui->MedI->setText("Medici: "+QString::number(Singleton::getInstance().getCl().getResurse().getMed().getNumber()));

    this->ui->SoldC->setText("Soldati: "+QString::number(Singleton::getInstance().getCl().getResurse().getSold().getNumber()));
    this->ui->CavC->setText("Cavalerie: "+QString::number(Singleton::getInstance().getCl().getResurse().getCav().getNumber()));
    this->ui->MedC->setText("Medici: "+QString::number(Singleton::getInstance().getCl().getResurse().getMed().getNumber()));
}

void windowAttack::setTextDusman(QString s)
{
    QStringList l=s.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    this->ui->SoldF->setText("Soldati: "+l[1]);
    this->ui->CavF->setText("Cavalerie: "+l[2]);
    this->ui->MedF->setText("Medici: "+l[3]);
}
