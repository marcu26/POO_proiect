#include "singinwindow.h"
#include "singletonwo.h"
#include "ui_singinwindow.h"


SingInWindow::SingInWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingInWindow)
{
    ui->setupUi(this);
    ui->label_4->hide();
    ui->label_5->hide();
}

SingInWindow::~SingInWindow()
{
    delete ui;
}

void SingInWindow::on_pushButton_4_clicked()
{
    Singleton::getInstance().showMW();
    ui->label_4->hide();
    this->hide();
}


void SingInWindow::on_pushButton_clicked()
{
    if(!Singleton::getInstance().hasSpaces(ui->uName->text()) && (ui->uName->text().size()>=8))
    {
         if(!Singleton::getInstance().hasSpaces(ui->Pass->text()) && (ui->Pass->text().size()>=8))
         {
            QString str="1 "+ui->uName->text()+" "+ui->Pass->text();
            Singleton::getInstance().cl.sendInfoToServer(str);
             ui->label_4->hide();
             ui->label_5->show();
         }
         else
         {
         ui->label_5->hide();
         ui->label_4->show();
         }
    }
    else
    {
    ui->label_5->hide();
    ui->label_4->show();
    }

}

