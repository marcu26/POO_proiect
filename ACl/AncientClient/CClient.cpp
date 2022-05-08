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

    if(answ[0]=='5' and answ[2]!='0')
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
          Singleton::getInstance().atw.setTurn(1);
          Singleton::getInstance().atw.setTuraBox("background-color:rgb(0,85,0)");
      }

    if(answ[0]=='a')
    {
        Singleton::getInstance().atw.setTextDusman(answ); //setez datele despre dusman
    }

    if(answ[0]=='8')  //io am gata pauza
    {
        Singleton::getInstance().atw.punePauza();
    }

    if(answ[0]=='e') // ala o gatat pauza
    {
        Singleton::getInstance().atw.endPause2();
    }

    if(answ[0]=='d') //Am Atacat
    {
        Singleton::getInstance().atw.setTextDusman(answ);
    }

    if(answ[0]=='c') //amFostAtacat
    {
        Singleton::getInstance().atw.setMyText(answ);
        Singleton::getInstance().atw.setTurn(1);
        Singleton::getInstance().atw.setTuraBox("background-color:rgb(0,85,0)");
    }

    if(answ[0]=='f') // o folosit ala medicii
    {
        Singleton::getInstance().atw.setTextDusman(answ);
        Singleton::getInstance().atw.setTurn(1);
        Singleton::getInstance().atw.setTuraBox("background-color:rgb(0,85,0)");
    }

    if(answ[0]=='g') //folosesc medicii
    {
         Singleton::getInstance().atw.setMyText(answ);
    }

    if(answ[0]=='w')
    {
        Singleton::getInstance().atw.hide();
        Singleton::getInstance().getCl().getResurse().addGalbeni(1000);
        Singleton::getInstance().aw.setShowText("Felicitari, ati castigat duleul!");
        Singleton::getInstance().aw.show();
        Singleton::getInstance().cl.sendInfoToServer(Singleton::getInstance().cl.resurse.getResourcesString());
    }

    if(answ[0]=='l')
    {
        Singleton::getInstance().atw.hide();
        Singleton::getInstance().aw.setShowText("Ati pierdut, mult succes data viitoare!");
        Singleton::getInstance().aw.show();
    }




}

CClient::~CClient()
{
}

void CClient::sendInfoToServer(QString string)
{
    this->socket.write(string.toUtf8());
}
