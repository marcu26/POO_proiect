#ifndef CMULTIPROT_H
#define CMULTIPROT_H

#include "iprotocol.h"

class CMultiProt : public IProtocol
{
private:
    void duelRequest(QString req, qintptr socketDescriptor);
    void setPauseForOpponent(QString req, qintptr socketDescriptor);
    void endPauseForOpponent(QString req);
    void recieveChallengedAnswer (QString req, qintptr socketDescriptor);
    void sendOpponentArmy(CDataBase &database, QString req, qintptr socketDescriptor);
    void manageAttack(QString req, qintptr socketDescriptor);
    void manageHeal(QString req, qintptr socketDescriptor);
    void manageLoseMasaVerde(QString req, qintptr socketDescriptor);

public:
    CMultiProt();

     virtual void executeProtocol(CDataBase &database,QString req, qintptr socketDescriptor) override;

};

#endif // CMULTIPROT_H
