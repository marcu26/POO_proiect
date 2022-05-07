#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Singleton.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_LogInB_clicked()
{
    Singleton::getInstance().showLW();
    this->hide();
}


void MainWindow::on_SingInB_clicked()
{
    Singleton::getInstance().showSW();
    this->hide();
}

void MainWindow::changeStyleSheet()
{
    QString func;
    func=".QWidget{background-image:url("+Singleton::getInstance().getPath()+"/Media/poza.png); background-position: center; }";
    this->centralWidget()->setStyleSheet(func);
    func=".QWidget{background-image:url("+Singleton::getInstance().getPath()+"/Media/logo2.png); background-position: center; }";
    this->ui->widget->setStyleSheet(func);
}

