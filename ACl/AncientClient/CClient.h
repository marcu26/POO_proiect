#pragma once
#include "CResurse.h"
#include <QTcpSocket>
#include <QString>

class CClient:public QObject
{
    Q_OBJECT



private:


    QString username;

    QTcpSocket socket;
    CResurse resurse;

public slots:
    void onReadyRead();
public:
    CClient() {};
    virtual ~CClient();

    CResurse &getResurse(){return resurse;};
    void connect_client(QString ip, int port);
    void sendInfoToServer(QString string);
    void clearSocket(){socket.flush();};
    void setUName(QString name){this->username=name;};
    QString getUName(){return username;};

};

