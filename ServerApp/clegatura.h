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
    static bool verfyConection(QString playerName);
    static bool sendAnswearToChallenger(QString challenger, QString playerName, QString raspuns);
};

#endif // CLEGATURA_H
