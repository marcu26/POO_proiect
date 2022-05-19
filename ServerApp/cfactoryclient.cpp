#include "cfactoryclient.h"
#include "CClient.h"

IClient *CFactoryClient::getClient(qintptr socketDescriptor)
{
    IClient *client = new CClient(socketDescriptor);
    return client;
}
