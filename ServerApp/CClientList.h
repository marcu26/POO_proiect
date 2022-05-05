#ifndef CCLIENTLIST_H
#define CCLIENTLIST_H


#include "CClient.h"
#include <QVector>

class CClientList
{
private:
    QVector<CClient *> list;
    static CClientList *instance;

public:

    void addClient(CClient * client);
    void eraseInactivePointer();
    QString getPlayersList();
    QString getPlayerListWithoutUser(qintptr socketDescrpitor);
    QTcpSocket * getPlayerSocket(QString username);
    CClient* getPlayer(QString username);
    void destroy();
    static CClientList &getInstance();

private:
    CClientList();
    CClientList(const CClientList &obj) = delete;
    CClientList(const CClientList &&obj) = delete;
};

#endif // CCLIENTLIST_H
