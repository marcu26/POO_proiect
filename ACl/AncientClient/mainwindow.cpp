#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>
#include <QDebug>
#include <singletonwo.h>
//class SingeltonWO;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->centralWidget()->setStyleSheet(".QWidget{background-image:url( D:/ACl/AncientClient/Media/poza.png); background-position: center; }");
  //  ui->frame->setAttribute(Qt::WA_TranslucentBackground,true);

}

void MainWindow::onReadyRead()
{
    QByteArray datas = socket.readAll();

    qDebug() <<datas<<"\n";

    QString answ = QString(datas);

}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_LogInB_clicked()
{
    Singleton::getInstance().showCW();
    this->hide();
}


void MainWindow::on_SingInB_clicked()
{
    Singleton::getInstance().showSW();
    this->hide();
}

