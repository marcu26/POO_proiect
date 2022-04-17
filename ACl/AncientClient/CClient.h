#pragma once
#include "CResurse.h"
#include <QTcpSocket>

class CClient:public QObject
{
private:

	std::string username;
	std::string pass;
	CResurse resurse;
    friend class Singelton;

    QTcpSocket socket;

public slots:
	void onReadyRead();
public:

    CClient() {};
    ~CClient();

    void connect_client(QString ip, int port);
	void buy(const int& cerere);
	void sendChallange() {};
	void processChallange() {};
    void sendInfoToServer(QString string);

};

