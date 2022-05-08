#ifndef CCLIENT_H
#define CCLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>

#include "cdatabase.h"

class CClient : public QObject       //fiecare client va reprezenta un thread
{
    Q_OBJECT

private:
    QTcpSocket *socket;             //conectiunea clientului
    qintptr socketDescriptor;
    QString username = " ";
    CDataBase database;
    bool active;            //verifica activitatea clientului (daca mai este conectat sau nu)
    bool inArena;

public slots:
    void onReadyRead();
    void onDisconnected();

public:
    CClient(qintptr id, QObject *parent = 0);

    void felicita();
    void autentification(QString &req);
    void registerUser(QString &req);
    bool getActivate() {return active;}
    QString getUsername() {return username;}
    QTcpSocket *getSocket() {return socket;}
    qintptr getSocketDescriptor() {return this->socketDescriptor;}
    void duelRequest(QString);
    void transmitResource();
    void saveResource(QString req);
    void setPauseForOpponent(QString req);
    void recieveChallengedAnswer(QString answ);
    void sendOpponentArmy(QString req);
    void manageAttack(QString req);
    void endPauseForOpponent(QString req);
    void manageHeal(QString req);
    void manageLoseMasaVerde(QString req);
    void deleteName();
    bool getInArena() {return inArena;}
    void setInArena(const bool &a) {inArena = a;}
};

#endif // CCLIENT_H
