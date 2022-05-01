#include "CClient.h"
#include "CShop.h"
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>
#include "Singleton.h"
#include <QRegularExpression>
#include <QElapsedTimer>

void CClient::buy(const int& cerere)
{
	CShop& shop = CShop::getInstance();
	shop.showAutorizatii();
	shop.showMuncitori();

	if (cerere == 1)
	{
		if (resurse.getGalbeni() >= 100)
		{
            //resurse.addAutorizatie("AutorizatieScoalaMilitara");
			resurse.subGalbeni(100);
		}
		else
			std::cout << "Nu aveti destui galbeni\n";
	}
	else if (cerere == 2)
	{
		if (resurse.getGalbeni() >= 100)
		{
            //resurse.addAutorizatie("AutorizatieScoalaMedici");
			resurse.subGalbeni(100);
		}
		else
			std::cout << "Nu aveti destui galbeni\n";
	}
	else if (cerere == 3)
	{
		if (resurse.getGalbeni() >= 20)
		{
			resurse.subGalbeni(20);
			resurse.addMuncitor();
		}
		else
			std::cout << "Nu aveti destui galbeni\n";
	}
}




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



}

CClient::~CClient()
{
}

void CClient::sendInfoToServer(QString string)
{
    this->socket.write(string.toUtf8());
}
