#ifndef CFACTORYCLIENT_H
#define CFACTORYCLIENT_H

#include "iclient.h"

class CFactoryClient
{
public:
    static IClient *getClient(qintptr socketDescriptor);
};

#endif // CFACTORYCLIENT_H
