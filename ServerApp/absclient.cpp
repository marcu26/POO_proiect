#include "absclient.h"
#include "cfactorylog.h"

AbsClient::AbsClient(qintptr id, QObject *parent)
    :QObject(parent), database{CDataBase::getInstance()}
{
    this->socketDescriptor = id;            //socketDescriptor = portul la care este conectat clientul
    socket = new QTcpSocket();

    if(!this->socket->setSocketDescriptor(this->socketDescriptor))
    {
        qDebug() <<"Eroare la stabilirea conexiunii dintre server si client\n";
        CFactoryLog::getLog(ERROR)->writeMessage("Eroare la stabilirea conexiunii dintre server si client");
        return;
    }
}
