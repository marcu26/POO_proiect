#ifndef CSERVER_H
#define CSERVER_H

#include <QTcpServer>
#include <QDebug>           //pentru afisarea mesajelor
#include <QTcpSocket>       //pt socketuri

#include "CClientList.h"

class CServer : public QTcpServer       //clasa singleton
{
    Q_OBJECT

private:
    static CServer *instance;
    CClientList& list;

public:
    static CServer &getInstance();

    void startServer();

protected:
     void incomingConnection(qintptr socketDescriptor);

private:
   // CServer () {}
    explicit CServer(QObject *parent = nullptr);
    CServer(const CServer &obj) = delete;           //renuntam la posbilitatea de a crea a copie
    CServer(const CServer &&obj) = delete;
};

#endif // CSERVER_H
