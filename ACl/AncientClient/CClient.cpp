#include "CClient.h"
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>
#include "Singleton.h"
#include <QRegularExpression>
#include <QElapsedTimer>




void CClient::connect_client(QString ip, int port)
{
    socket.connectToHost(ip,port);
    connect(&socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void CClient::onReadyRead()
{
    QByteArray datas = socket.readAll();

    qDebug() <<datas<<"\n";

    QString answ = QString(datas);

    if(answ=="2 0")
    {
        Singleton::getInstance().sw.allIsWrong();
    }

    if(answ=="2 1")
    {
        Singleton::getInstance().sw.allIsGood();
    }

    if(answ=="1 0")
    {
        Singleton::getInstance().lw.allIsWrong();
    }

    if(answ=="1 1")
    {
        Singleton::getInstance().lw.allIsGood();
    }

    if(answ[0]=='6')
    {
        QStringList l = answ.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

        Singleton::getInstance().cl.resurse.initResurse(l);

        Singleton::getInstance().showAW();
    }

    if(answ[0]=='4')
    {
        Singleton::getInstance().aw.setPlayers(answ);
    }

    if(answ[0]=='5')
    {
        Singleton::getInstance().aw.maProvoci(answ);
    }

    if(answ[0]=='9' && answ[2]=='0')
    {
        Singleton::getInstance().aw.aRefuzat();
    }

    if(answ[0]=='9' && answ[2]=='1')
      {
          qDebug()<<answ;
          this->sendInfoToServer("a "+Singleton::getInstance().getDusman());
          Singleton::getInstance().showATW();
          Singleton::getInstance().hideAW();
      }

    if(answ[0]=='a')
    {
        Singleton::getInstance().atw.setTextDusman(answ);
    }




}

CClient::~CClient()
{
}

void CClient::sendInfoToServer(QString string)
{
    this->socket.write(string.toUtf8());
}
