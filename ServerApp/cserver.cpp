#include "cserver.h"
#include "cexception.h"
#include "cfactoryclient.h"

CServer* CServer::instance = nullptr;

CServer::CServer(QObject *parent)
    : QTcpServer{parent}, list{CClientList::getInstance()}
{

}
                                            //IAU O CLASA SEPARATA IN CARE O SA INCLUD DOAR THRAD_LIST, SI PRINTT-O FUNCTIE STATICA VOI ACCESA LISTA SI VOI DA CA PARAMETRUL THREADUL CARE VREA SA VADA LISTA SI O VOI TRIMITE.VA TREBUI SA FAC TOTUSI CA LISTA SA FIE DE TIP SINGLETON SA O POT ACCESA CU USURINTA
CServer& CServer::getInstance()
{
    if(instance == nullptr)
    {
        instance = new CServer(instance);
        return *instance;
    }
    return *instance;
}

void CServer::startServer()
{
    if(this->listen(QHostAddress::Any,4452))        //serverul asteapta conectiuni de la orice adresa IP pe portul 4452
    {
        qDebug() <<"Ancient Server activat!\n";
    }
    else
    {
       throw new CException("Ancient Server Picat",-1);
    }
}

void CServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Conectare...";
    IClient *client = CFactoryClient::getClient(socketDescriptor);
    list.addClient(client);
}
