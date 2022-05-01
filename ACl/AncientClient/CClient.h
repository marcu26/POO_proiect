#pragma once
#include "CResurse.h"
#include <QTcpSocket>
#include <QString>

class CClient:public QObject
{
    Q_OBJECT

     friend class Singelton;
     friend class windowAdunare;
private:


	std::string username;
	std::string pass;

    QTcpSocket socket;

public slots:
    void onReadyRead();
public:
    CResurse resurse;
    CClient() {};
    virtual ~CClient();


    void connect_client(QString ip, int port);
	void buy(const int& cerere);
	void sendChallange() {};
	void processChallange() {};
    void sendInfoToServer(QString string);
};

