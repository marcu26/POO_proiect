#include "CClient.h"
#include "clegatura.h"
#include "cexception.h"
#include "CFactoryLog.h"

CClient::CClient(qintptr ID, QObject *parent)
    :AbsClient(ID,parent)
{
    connect(socket, SIGNAL(readyRead()),this,SLOT(onReadyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()),this,SLOT(onDisconnected()),Qt::DirectConnection);

    qDebug() <<"Client: "<<this->socketDescriptor<<"\n";
    active = 1;
}

void CClient::onReadyRead()
{
        QByteArray data = socket->readAll();

        QString req(data);

        qDebug() <<socketDescriptor<<": "<<req<<"\n";
        interpret.interpretProtocolType(database,req, this->socketDescriptor);
}

void CClient::felicita()
{
    socket->flush();
    socket->write("\n\n\n\n\n\n\n\nFelicitari!!!!!!!!!!!!!!!!!!");
}


void CClient::onDisconnected()
{
    qDebug() <<"S-a deconectat: "<<this->socketDescriptor<<"\n";
    active = 0;
    CFactoryLog::getLog(LOG_OUT)->writeMessage(this->getUsername());
    this->socket->deleteLater();
    database.deletePLayerFromArena(this->username);
}

