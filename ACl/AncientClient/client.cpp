#include "client.h"
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>



Client::Client(QString ip,int port)
{
    socket.connectToHost(ip,port);
    connect(&socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void Client::onReadyRead()
{
    QByteArray datas = socket.readAll();

    qDebug() <<datas<<"\n";

    QString answ = QString(datas);
}

Client::~Client()
{
}


