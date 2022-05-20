#include "csingleprot.h"
#include "CClientList.h"
#include "clegatura.h"
#include "cfactorylog.h"

CSingleProt::CSingleProt()
{

}

void CSingleProt::executeProtocol(CDataBase &database,QString req, qintptr socketDescriptor)
{
    if(req[0] == '1')
       autentification(database,req, socketDescriptor);
   else if(req[0] == '2')
        registerUser(database,req, socketDescriptor);
   else if(req[0] == '6')
        transmitResource(database,socketDescriptor);
    else if (req[0] == '7')
        saveResource(database,req,socketDescriptor);
    else if (req[0] == 'k')
        deleteName(socketDescriptor);
    else if (req[0] == 's')
        transmitStats(database, socketDescriptor);
}

void CSingleProt::autentification(CDataBase &database,QString &req, qintptr socketDescriptor)             //VERIFICARE DACA NU ESTE DEJA CONECTAT
{
    CClientList &list = CClientList::getInstance();
    IClient *client = list[socketDescriptor];
    database.connectDataBase();
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    qDebug() <<l.value(1)<<" --- "<<l.value(2)<<"\n";

    if(database.verifyCredentials(l.value(1), l.value(2))==true && CLegatura::verfyConection(l.value(1))==0)
       {
        client->setUsername(l.value(1));
        CFactoryLog::getLog(LOG_IN)->writeMessage(client->getUsername());
        client->getSocket()->flush();
        client->getSocket()->write("1 1");                   //REUSIT
        transmitResource(database, client->getSocketDescriptor());
        client->setInArena(0);
        }
    else
    {
        CFactoryLog::getLog(ERROR)->writeMessage("Un utilizator a incercat sa se autentifice, dar nu credentialele nu au fost corecte");
        client->getSocket()->flush();
        client->getSocket()->write("1 0");                   //ESUAT
    }

}

void CSingleProt::registerUser(CDataBase &database, QString &req, qintptr socketDescriptor)
{
       CClientList &list = CClientList::getInstance();
       IClient *client = list[socketDescriptor];
       database.connectDataBase();
       QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
       qDebug() <<l.value(1)<<" --- "<<l.value(2)<<"\n";

       if(database.addUser(l.value(1),l.value(2))==-1)
       {
           client->getSocket()->flush();
           client->getSocket()->write("2 0");                   //ESUAT
           qDebug () <<"Username Luat\n";
           CFactoryLog::getLog(ERROR)->writeMessage("Un Utilizator a incercat sa se inregistreze cu un username deja existent");
       }
       else
       {
          client->setUsername(l.value(1));         // -- nu trebuie sa ii dau username-ul pt ca nu se mai poate autentifica dupa
          client->getSocket()->flush();
          client->getSocket()->write("2 1");                   //REUSIT
          transmitResource(database, client->getSocketDescriptor());
          CFactoryLog::getLog(REGISTER)->writeMessage("");
       }
}

void CSingleProt::saveResource(CDataBase &database, QString req, qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();
    IClient *client = list[socketDescriptor];
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

     database.connectDataBase();

     database.updateResources(l, client->getUsername());
}

void CSingleProt::deleteName(qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();
    IClient *client = list[socketDescriptor];

    client->setUsername("");
}

void CSingleProt::transmitStats(CDataBase &database, qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();
    IClient *client = list[socketDescriptor];

   QString s = database.getStats(client->getUsername());
   QString stats = "s "+s;
   qDebug()<<stats;
   client->getSocket()->flush();
   client->getSocket()->write(stats.toUtf8());
}

void CSingleProt::transmitResource(CDataBase &database, qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();
    IClient *client = list[socketDescriptor];

    database.connectDataBase();
    QString resources = "6 ";
    resources += database.getResources(client->getUsername());

    client->getSocket()->flush();
    client->getSocket()->write(resources.toUtf8());

}
