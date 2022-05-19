#include "CClient.h"
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>
#include "Singleton.h"
#include <QRegularExpression>
#include <QElapsedTimer>
#include "protocolinterpreter.h"
#include <QMessageBox>
#include "exceptieconectare.h"





void CClient::connect_client(QString ip, int port)
{

    try
    {
        socket.connectToHost(ip,port);
        connect(&socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        if(!socket.waitForConnected(1000))
            throw(ExceptieConectare("Clientul nu se poate conecta la server"));
    }
     catch (ExceptieConectare &e)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Exception",e.getMsg());
        messageBox.setFixedSize(500,200);
        exit(1);
    }

}

void CClient::onReadyRead()
{

    QByteArray datas = socket.readAll();

    qDebug() <<datas<<"\n";

    QString answ = QString(datas);

    ProtocolInterpreter::callFunction(answ);


}

CClient::~CClient()
{
}

void CClient::sendInfoToServer(QString string)
{
    this->socket.write(string.toUtf8());
}
