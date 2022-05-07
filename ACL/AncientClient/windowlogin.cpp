#include "windowlogin.h"
#include "ui_windowlogin.h"
#include "Singleton.h"

WindowLogIn::WindowLogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowLogIn)
{
    ui->setupUi(this);
    ui->invalid->hide();
}

WindowLogIn::~WindowLogIn()
{
    delete ui;
}

void WindowLogIn::on_BackB_clicked()
{
    Singleton::getInstance().showMW();
    this->hide();
}


void WindowLogIn::on_finnishB_clicked()
{

    if(!Singleton::getInstance().hasSpaces(ui->uName->text()) && (ui->uName->text().size()>=8))
    {
         if(!Singleton::getInstance().hasSpaces(ui->Pass->text()) && (ui->Pass->text().size()>=8))
         {
            QString str="1 "+ui->uName->text()+" "+ui->Pass->text();
            Singleton::getInstance().getCl().sendInfoToServer(str);
         }
         else
         {
         ui->invalid->show();
         }
    }
    else
    {
    ui->invalid->show();
    }
}

void WindowLogIn::allIsWrong()
{
    ui->invalid->show();
}

void WindowLogIn::allIsGood()
{
    this->hide();
}

void WindowLogIn::changeStyleSheet()
{
    QString func;
    func=".QWidget{background-image:url("+Singleton::getInstance().getPath()+"/Media/poza.png); background-position: center; }";
    this->ui->widget->setStyleSheet(func);
}

