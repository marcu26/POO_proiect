#ifndef CSINGLEPROT_H
#define CSINGLEPROT_H

#include "iprotocol.h"

class CSingleProt : public IProtocol
{       
private:
    void autentification(CDataBase &database,QString &req, qintptr socketDescriptor);
    void registerUser(CDataBase &database,QString &req, qintptr socketDescriptor);
    void saveResource(CDataBase &database,QString req, qintptr socketDescriptor);
    void deleteName(qintptr socketDescriptor);
    void transmitStats(CDataBase &database,qintptr socketDescriptor);
    void transmitResource(CDataBase &database, qintptr socketDescriptor);

public:
    CSingleProt();

     virtual void executeProtocol(CDataBase &database,QString req, qintptr socketDescriptor) override;
};

#endif // CSINGLEPROT_H
