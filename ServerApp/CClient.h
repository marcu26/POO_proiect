#ifndef CCLIENT_H
#define CCLIENT_H

#include "absclient.h"

#include "cdatabase.h"

class CClient : public AbsClient
{
    Q_OBJECT

private:
    QString username = " ";
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
    virtual void transmitStats() override;

    virtual ~CClient() {};
};

#endif // CCLIENT_H
