#ifndef CCLIENTTHREAD_H
#define CCLIENTTHREAD_H

#include <QThread>
#include <QDebug>
#include <QTcpSocket>

#include "cdatabase.h"

class CClientThread : public QThread        //fiecare client va reprezenta un thread
{
    Q_OBJECT

private:
    QTcpSocket *socket;             //conectiunea clientului
    qintptr socketDescriptor;
    QString username;
    CDataBase database;

public slots:
    void onReadyRead();
    void onDisconnected();

public:
    CClientThread(qintptr id, QObject *parent = 0);
    void run();
    void felicita();
    void autentification(QString &req);
    void registerUser(QString &req);
};

#endif // CCLIENTTHREAD_H
