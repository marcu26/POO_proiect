#include <QCoreApplication>
#include <QString>

#include "cserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CServer &sever = CServer::getInstance();
    sever.startServer();

    return a.exec();
}
//172.16.31.9
