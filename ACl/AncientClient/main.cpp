#include "mainwindow.h"
#include "Singleton.h"
#include <QApplication>
#include <QElapsedTimer>
#include <QTimer>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Singleton::getInstance().showMW() ;
    Singleton::getInstance().cl.connect_client("172.16.31.9",4452);



    return a.exec();
}
