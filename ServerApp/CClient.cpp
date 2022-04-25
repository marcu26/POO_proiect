#include "CClient.h"
#include "clegatura.h"

CClient::CClient(qintptr ID, QObject *parent)
    :QObject(parent)
{
    this->socketDescriptor = ID;            //socketDescriptor = portul la care este conectat clientul
    socket = new QTcpSocket();

    if(!this->socket->setSocketDescriptor(this->socketDescriptor))
    {
        qDebug() <<"Eroare la stabilirea conexiunii dintre server si client\n";
        return;
    }
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

        if (req[0] == '1')
            autentification(req);               //cerere pt autentificare (1 username pass)

        else if (req[0] == '2')
            registerUser(req);                      //cerere pt inregistrare (2 username pass)

        else if (req[0] == '3')
            CLegatura::sendPlayersList(socket);   //trimite lista jucatorilor cu spatiu intre ei (3)

        else if (req[0] == '4')
            CLegatura::sendPlayersListWithoutUser(socket, socketDescriptor);  //trimite lista jucatorilor fara a se pune si pe el (4)

        else if (req[0] == '5')
            duelRequest(req);               //trimite provocarea la duel (5 playerProvocat)

        else if (req[0] == '6')
            transmitResource();               //trimite jucatorului resursele aferente

        else if (req[0] == '7')
            saveResource(req);              //salvez updateurile resurselor primite de la client, le primesc astfefl (7 x y z ...);
}

void CClient::felicita()
{
    socket->write("\n\n\n\n\n\n\n\nFelicitari!!!!!!!!!!!!!!!!!!");
}

void CClient::autentification(QString &req)
{
    database.connectDataBase(QString::number(socketDescriptor));
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    qDebug() <<l.value(1)<<" --- "<<l.value(2)<<"\n";

    if(database.verifyCredentials(l.value(1), l.value(2))==true)
       {
        this->username = l.value(1);
        socket->write("Autentificare Reusita!");
        }
    else
        socket->write("Autentificare ESUATA!");
}

void CClient::registerUser(QString &req)
{
    database.connectDataBase(QString::number(socketDescriptor));
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    qDebug() <<l.value(1)<<" --- "<<l.value(2)<<"\n";

    if(database.addUser(l.value(1),l.value(2))==-1)
    {
        socket->write("Acest nume de utilizator este deja existent!");
        qDebug () <<"Username Luat\n";
    }
    else
    {
        this->username = l.value(1);
        socket->write("Inregistrare efectuata cu succes!");
    }
}

void CClient::duelRequest(QString req)
{
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

    CLegatura::sendMessageToOpponent(this->socket,this->username, l.value(1));
}

void CClient::transmitResource()
{
    database.connectDataBase(QString::number(socketDescriptor));
    QString resources = database.getResources(this->username);

    socket->write(resources.toUtf8());
}

void CClient::saveResource(QString req)
{
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    
    database.connectDataBase(QString::number(socketDescriptor));

    database.updateResources(l, this->username);
}

void CClient::onDisconnected()
{
    qDebug() <<"S-a deconectat: "<<this->socketDescriptor<<"\n";
    active = 0;
    socket->deleteLater();
}
