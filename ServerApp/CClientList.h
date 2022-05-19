#ifndef CCLIENTLIST_H
#define CCLIENTLIST_H


#include "iclient.h"
#include <QVector>

class CClientList
{
private:
    QVector<IClient *> list;
    static CClientList *instance;

public:

    void addClient(IClient * client);
    void eraseInactivePointer();
    void setOnInArena(QString playerName);
    void setOffInArena(QString playerName);
    bool getPlayerInArena(QString playerName);
    QString getPlayersList();
    QString getPlayerListWithoutUser(qintptr socketDescrpitor);
    QTcpSocket * getPlayerSocket(QString username);
    IClient* getPlayer(QString username);
    void destroy();
    static CClientList &getInstance();

    IClient* operator [] (const qintptr socketDescriptor);

private:
    CClientList();
    CClientList(const CClientList &obj) = delete;
    CClientList(const CClientList &&obj) = delete;
};

#endif // CCLIENTLIST_H
