#ifndef ICLIENT_H
#define ICLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>

class IClient
{
public:
   virtual void felicita() = 0;
   virtual bool getActivate() = 0;
   virtual  QString getUsername() = 0 ;
   virtual  QTcpSocket *getSocket()  = 0;
   virtual  qintptr getSocketDescriptor()  = 0;
   virtual    bool getInArena() =0;
   virtual   void setInArena(const bool &a) =0;
   virtual void setUsername(const QString& name ) = 0;
};

#endif // ICLIENT_H
