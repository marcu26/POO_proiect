#include <QCoreApplication>
#include <QString>

#include "cserver.h"
#include "iexception.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try
    {
        CServer &sever = CServer::getInstance();
        sever.startServer();
    }
    catch (IException &e)
    {
        qDebug() << e.getErrorNumber();

        return e.getErrorNumber();
    }
    return a.exec();
}
//172.16.31.9
