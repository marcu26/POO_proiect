#ifndef ABSCLIENT_H
#define ABSCLIENT_H

#include "iclient.h"
#include "cdatabase.h"
#include "cinterpret.h"

class AbsClient :public QObject, public IClient
{
         Q_OBJECT
protected:
    QTcpSocket *socket;             //conectiunea clientului
    qintptr socketDescriptor;
    CDataBase& database;
    CInterpret interpret;

public:
    AbsClient(qintptr id, QObject *parent = 0);

    QTcpSocket *getSocket() {return socket;}
    qintptr getSocketDescriptor() {return this->socketDescriptor;}

    virtual ~AbsClient(){};
};

#endif // ABSCLIENT_H
