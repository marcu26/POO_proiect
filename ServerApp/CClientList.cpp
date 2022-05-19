#include "CClientList.h"

CClientList *CClientList::instance = nullptr;
CClientList::CClientList()
{

}

void CClientList::addClient(IClient *client)
{
    list.push_back(client);
}

void CClientList::eraseInactivePointer()
{
    list.erase(std::remove_if(list.begin(), list.end(), [](IClient* i) { return (i->getActivate()==false); }),
            list.end());
}

void CClientList::setOnInArena(QString playerName)
{
    for(auto &it:list)
    {
        if(it->getUsername() == playerName)
            it->setInArena(1);
    }
}

void CClientList::setOffInArena(QString playerName)
{
    for(auto &it:list)
    {
        if(it->getUsername() == playerName)
            it->setInArena(0);
    }
}

bool CClientList::getPlayerInArena(QString playerName)
{
    for(auto &it:list)
    {
        if(it->getUsername() == playerName)
            return it->getInArena();
    }
}

QString CClientList::getPlayersList()
{
    QString players="";

    for(auto &it:list)
    {
        players+= it->getUsername();
        players+=' ';
    }

    return players;
}

QString CClientList::getPlayerListWithoutUser(qintptr socketDescrpitor)
{
    QString players="";

    for(auto &it:list)
    {
       if(it->getSocketDescriptor()!=socketDescrpitor && it->getUsername()!="" && it->getInArena()==0)
       {
           players+= it->getUsername();
           players+=' ';
       }
    }

    return players;
}

QTcpSocket *CClientList::getPlayerSocket(QString username)
{
    for(auto &it:list)
    {
        if(it->getUsername()==username)
            return it->getSocket();
    }
    return nullptr;
}

IClient* CClientList::getPlayer(QString username)
{
    for (auto& it : list)
    {
        if (it->getUsername() == username)
            return it;
    }
    return nullptr;
}

void CClientList::destroy()
{
    if(instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}

CClientList &CClientList::getInstance()
{
    if(instance == nullptr)
    {
        instance = new CClientList();
    }
    return (*instance);
}

IClient *CClientList::operator [](const qintptr socketDescriptor)
{
   IClient *client = nullptr;
   for(auto &it:list)
   {
       if(socketDescriptor == it->getSocketDescriptor())
       {
           client = it;
           break;
       }
   }
   return client;
}
