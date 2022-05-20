#ifndef CINTERPRET_H
#define CINTERPRET_H

#include <QDebug>
#include <QTcpSocket>
#include "iprotocol.h"

class CInterpret
{
private:
    IProtocol *prot;
public:
    CInterpret();

    void interpretProtocolType(CDataBase &database,QString req, qintptr socketDescriptor);

};

#endif // CINTERPRET_H
