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
    static void sendAnswerToChallenger(QString challenger, QString playerName, QString raspuns);
    static void sendAttackMoveResult(QTcpSocket *player, QString playerName,QString opponentName, QString attackTroup, QString secondTroup);
};

#endif // CLEGATURA_H
