#include "windowshop.h"
#include "ui_windowshop.h"
#include "Singleton.h"

windowShop::windowShop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowShop)
{
    ui->setupUi(this);
}

windowShop::~windowShop()
{
    delete ui;
}

void windowShop::on_Close_clicked()
{
    this->hide();
}


void windowShop::on_Provoaca_2_clicked()
{
    if(Singleton::getInstance().getCl().getResurse().getMedic()==0)
    {

        if(Singleton::getInstance().getCl().getResurse().getGalbeni()>=100)
        {
        Singleton::getInstance().getCl().getResurse().setMedic(1);
        Singleton::getInstance().getCl().getResurse().subGalbeni(100);
        Singleton::getInstance().showAW();
        Singleton::getInstance().getCl().sendInfoToServer(Singleton::getInstance().getCl().getResurse().getResourcesString());
        }
    }
}


void windowShop::on_AutoMili_clicked()
{

    if(Singleton::getInstance().getCl().getResurse().getMili()==0)
    {
        if(Singleton::getInstance().getCl().getResurse().getGalbeni()>=100)
        {
        Singleton::getInstance().getCl().getResurse().setMili(1);
        Singleton::getInstance().getCl().getResurse().subGalbeni(100);
        Singleton::getInstance().showAW();
        Singleton::getInstance().getCl().sendInfoToServer(Singleton::getInstance().getCl().getResurse().getResourcesString());
        }
    }

}


void windowShop::on_Muncitori_clicked()
{

        if(Singleton::getInstance().getCl().getResurse().getGalbeni()>=20)
        {
            Singleton::getInstance().getCl().getResurse().subGalbeni(20);
            Singleton::getInstance().getCl().getResurse().addMuncitor();
            Singleton::getInstance().showAW();
            Singleton::getInstance().getCl().sendInfoToServer(Singleton::getInstance().getCl().getResurse().getResourcesString());

        }
}

