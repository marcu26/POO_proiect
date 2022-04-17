#include "cserver.h"

CServer* CServer::instance = nullptr;

CServer::CServer(QObject *parent)
    : QTcpServer{parent}
{

}

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
        qDebug() <<"Ancient Server PICAT \n";
    }
}

void CServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Conectare...";
    CClientThread *thread = new CClientThread(qintptr(socketDescriptor),this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));                   //finished() = s-a terminat executarea ; delet
    thread->start();
}
