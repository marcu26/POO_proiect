#include "windowsingin.h"
#include "ui_windowsingin.h"
#include "Singleton.h"

WindowSingIn::WindowSingIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowSingIn)
{
    ui->setupUi(this);
    ui->succes->hide();
    ui->invalid->hide();
}

WindowSingIn::~WindowSingIn()
{
    delete ui;
}

void WindowSingIn::on_BackB_clicked()
{
    Singleton::getInstance().showMW();
    ui->succes->hide();
    ui->invalid->hide();
    this->hide();
}


void WindowSingIn::on_finnishB_clicked()
{

    if(!Singleton::getInstance().hasSpaces(ui->uName->text()) && (ui->uName->text().size()>=8))
    {
         if(!Singleton::getInstance().hasSpaces(ui->Pass->text()) && (ui->Pass->text().size()>=8))
         {
             if(ui->Pass_2->text()==ui->Pass->text())
             {
            QString str="2 "+ui->uName->text()+" "+ui->Pass->text();
            Singleton::getInstance().getCl().sendInfoToServer(str);
             }
             else
             {
                 ui->succes->hide();
                 ui->invalid->show();
             }
         }
         else
         {
         ui->succes->hide();
         ui->invalid->show();
         }
    }
    else
    {
    ui->succes->hide();
    ui->invalid->show();
    }

}

void WindowSingIn::allIsGood()
{
    ui->succes->show();
    ui->invalid->hide();
}

void WindowSingIn::allIsWrong()
{
    ui->succes->hide();
    ui->invalid->show();
}

void WindowSingIn::changeStyleSheet()
{
    QString func;
    func=".QWidget{background-image:url("+Singleton::getInstance().getPath()+"/Media/poza.png); background-position: center; }";
    this->ui->widget->setStyleSheet(func);
}

