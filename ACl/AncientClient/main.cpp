#include "mainwindow.h"
#include "Singleton.h"
#include <QApplication>
#include <QFile>
#include <QtDebug>
#include <fstream>
#include <QString>
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    Singleton::getInstance().setPath("C:/Users/marcu/Desktop/ACL/AncientClient");
    Singleton::getInstance().connectToServer();
    Singleton::getInstance().setBG();
    Singleton::getInstance().showMW();


    return a.exec();
}
