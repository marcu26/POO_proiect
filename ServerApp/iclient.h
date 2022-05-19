#ifndef ICLIENT_H
#define ICLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>

class IClient
{
public:
   virtual void felicita() = 0;
   virtual  void autentification(QString &req) = 0;
   virtual void registerUser(QString &req) = 0;
   virtual bool getActivate() = 0;
   virtual  QString getUsername() = 0 ;
   virtual  QTcpSocket *getSocket()  = 0;
   virtual  qintptr getSocketDescriptor()  = 0;
   virtual  void duelRequest(QString) = 0;
   virtual  void transmitResource()= 0;
   virtual  void saveResource(QString req)= 0;
   virtual  void setPauseForOpponent(QString req)= 0;
   virtual   void recieveChallengedAnswer(QString answ)= 0;
   virtual  void sendOpponentArmy(QString req)= 0;
   virtual  void manageAttack(QString req)= 0;
   virtual  void endPauseForOpponent(QString req)= 0;
   virtual  void manageHeal(QString req)= 0;
   virtual   void manageLoseMasaVerde(QString req)= 0;
   virtual   void deleteName()= 0;
   virtual    bool getInArena() =0;
   virtual   void setInArena(const bool &a) =0;
   virtual void transmitStats() = 0;
};

#endif // ICLIENT_H
