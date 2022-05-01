#ifndef CLEGATURA_H
#define CLEGATURA_H

#include <QTcpSocket>

class CLegatura
{
public:
    CLegatura();

    static void sendPlayersList(QTcpSocket *socket);
    static void sendPlayersListWithoutUser(QTcpSocket *socket, qintptr socketDescriptor);
    static void sendMessageToOpponent(QTcpSocket *socket,QString playerName ,QString opponentName);
    static void setPauseForOpponent(QTcpSocket *socket, QString opponentName);
};

#endif // CLEGATURA_H
