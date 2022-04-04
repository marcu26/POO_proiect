#pragma once
#include "CResurse.h"

class CClient
{
private:

	std::string username;
	std::string pass;
	CResurse resurse;

	QTcpSocket* socket;

public slots:
	void onReadyRead();
public:

	CClient() {}

	void buy(const int& cerere);
	void sendChallange() {};
	void processChallange() {};
	void sendInfoToServer();

	~CClient() {}
};

