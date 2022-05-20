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
    bool getActivate() {return active;}
    QString getUsername() {return username;}
    bool getInArena() {return inArena;}
    void setInArena(const bool &a) {inArena = a;};
    virtual void setUsername(const QString& name ) override {this->username = name;};

    virtual ~CClient() {};
};

#endif // CCLIENT_H
