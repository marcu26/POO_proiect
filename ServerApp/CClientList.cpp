#include "CClientList.h"

CClientList *CClientList::instance = nullptr;
CClientList::CClientList()
{

}

void CClientList::addClient(CClient *client)
{
    list.push_back(client);
}

void CClientList::eraseInactivePointer()
{
    list.erase(std::remove_if(list.begin(), list.end(), [](CClient* i) { return (i->getActivate()==false); }),
            list.end());
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
       if(it->getSocketDescriptor()!=socketDescrpitor)
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

CClient* CClientList::getPlayer(QString username)
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
