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
};

#endif // CCLIENT_H
