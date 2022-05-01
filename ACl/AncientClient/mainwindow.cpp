#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Singleton.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->centralWidget()->setStyleSheet(".QWidget{background-image:url( D:/ACl/AncientClient/Media/poza.png); background-position: center; }");

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

