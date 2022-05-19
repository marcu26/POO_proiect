#ifndef CPROTOCOL_H
#define CPROTOCOL_H

#include <QString>
#include <QTcpSocket>

class CProtocol
{
public:
    CProtocol();

    void intepretRequest(QString req);
};

#endif // CPROTOCOL_H
