#include "connectw.h"
#include "ui_connectw.h"
#include "singletonwo.h"

ConnectW::ConnectW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectW)
{
    ui->setupUi(this);
     ui->label_4->hide();


}

ConnectW::~ConnectW()
{
    delete ui;
}

void ConnectW::on_pushButton_4_clicked()
{
    Singleton::getInstance().showMW();
    this->hide();

}


void ConnectW::on_pushButton_clicked()
{
    if(!Singleton::getInstance().hasSpaces(ui->uName->text()) && (ui->uName->text().size()>=8))
    {
         if(!Singleton::getInstance().hasSpaces(ui->Pass->text()) && (ui->Pass->text().size()>=8))
         {
            QString str="2 "+ui->uName->text()+" "+ui->Pass->text();
            Singleton::getInstance().cl.sendInfoToServer(str);
             ui->label_4->hide();
         }
         else
         {
         ui->label_4->show();
         }
    }
    else
    {
    ui->label_4->show();
    }

}

