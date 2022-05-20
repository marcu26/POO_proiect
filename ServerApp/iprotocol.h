#ifndef IPROTOCOL_H
#define IPROTOCOL_H

#include <QDebug>
#include <QTcpSocket>
#include "cdatabase.h"

class IProtocol
{
public:
    virtual void executeProtocol(CDataBase& database,QString req, qintptr socketDescriptor) = 0;

    virtual ~IProtocol() {};
};

#endif // IPROTOCOL_H
