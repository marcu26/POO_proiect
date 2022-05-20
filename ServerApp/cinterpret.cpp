#include "cinterpret.h"
#include "cfactoryprot.h"
#include "cexception.h"

CInterpret::CInterpret()
{
    prot = nullptr;
}

void CInterpret::interpretProtocolType(CDataBase &database,QString req, qintptr socketDescriptor)
{
    if(req[0] == '1' || req[0] == '2' || req[0] == '6' || req[0] == '7' || req[0] == 'k' || req[0] == 's')
    {
        prot = CFactoryProt::getProt(Single);
        prot->executeProtocol(database,req,socketDescriptor);
        delete prot;
        prot = nullptr;
    }
    else if(req[0] == '3' || req[0] == '4' || req[0] == '5' || req[0] =='8' || req[0] == 'e' || req[0] == '9' || req[0] == 'a' || req[0] == 'b' || req[0] == 'm' || req[0] == 'q')
    {
        prot = CFactoryProt::getProt(Interaction);
        prot->executeProtocol(database,req,socketDescriptor);
        delete prot;
        prot = nullptr;
    }
    else
    {
         throw new CException("Protocol nerecunoscut!",-7);
    }
}
