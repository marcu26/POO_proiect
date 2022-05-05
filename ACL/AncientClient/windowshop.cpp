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
    if(Singleton::getInstance().cl.resurse.getMedic()==0)
    {

        if(Singleton::getInstance().cl.resurse.getGalbeni()>=100)
        {
        Singleton::getInstance().cl.resurse.setMedic(1);
        Singleton::getInstance().cl.resurse.subGalbeni(100);
        Singleton::getInstance().showAW();
        Singleton::getInstance().cl.sendInfoToServer(Singleton::getInstance().cl.resurse.getResourcesString());
        }
    }
}


void windowShop::on_AutoMili_clicked()
{

    if(Singleton::getInstance().cl.resurse.getMili()==0)
    {
        if(Singleton::getInstance().cl.resurse.getGalbeni()>=100)
        {
        Singleton::getInstance().cl.resurse.setMili(1);
        Singleton::getInstance().cl.resurse.subGalbeni(100);
        Singleton::getInstance().showAW();
        Singleton::getInstance().cl.sendInfoToServer(Singleton::getInstance().cl.resurse.getResourcesString());
        }
    }

}


void windowShop::on_Muncitori_clicked()
{

        if(Singleton::getInstance().cl.resurse.getGalbeni()>=20)
        {
            Singleton::getInstance().cl.resurse.subGalbeni(20);
            Singleton::getInstance().cl.resurse.addMuncitor();
            Singleton::getInstance().showAW();
            Singleton::getInstance().cl.sendInfoToServer(Singleton::getInstance().cl.resurse.getResourcesString());

        }
}

