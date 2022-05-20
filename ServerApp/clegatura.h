#ifndef CLEGATURA_H
#define CLEGATURA_H

#include <QTcpSocket>

class CLegatura
{
private:
    static void modifyTroupNumber(int numberAttack, int &troup);
    static void healTroup(int numberMed, int &troup, int initTroup);
    static void updateLostResources(QString name);
    static void ifZero(int &ivalue, float fvalue);

public:
    CLegatura();

    static void sendPlayersList(QTcpSocket *socket);
    static void sendPlayersList(QTcpSocket *socket, qintptr socketDescriptor);
    static void sendMessageToOpponent(QTcpSocket *socket,QString playerName ,QString opponentName);
    static void setPauseForOpponent(QTcpSocket *socket, QString opponentName);
    static void endPauseForOpponent(QString opponentName);
    static bool verfyConection(QString playerName);
    static void sendAnswerToChallenger(QString challenger, QString playerName, QString raspuns);
    static void sendAttackMoveResult(QTcpSocket *player, QString playerName,QString opponentName, QString attackTroup, QString secondTroup);
    static void sendHealResults(QString playerName, QString healedTroup, QString opponentName);
    static void loseMasaVerde(QString playerName, QString opponentName);
};

#endif // CLEGATURA_H
