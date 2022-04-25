#include "clegatura.h"
#include "cserver.h"

CLegatura::CLegatura()
{

}

void CLegatura::sendPlayersList(QTcpSocket *socket)
{
    CClientList &list = CClientList::getInstance();

    list.eraseInactivePointer();
    QString players = list.getPlayersList();

    socket->write(players.toUtf8());
}

void CLegatura::sendPlayersListWithoutUser(QTcpSocket *socket, qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();

    list.eraseInactivePointer();
    QString players = list.getPlayerListWithoutUser(socketDescriptor);

    socket->write(players.toUtf8());
}

void CLegatura::sendMessageToOpponent(QTcpSocket *socket,QString playerName ,QString opponentName)
{
     CClientList &list = CClientList::getInstance();

     list.eraseInactivePointer();
     QTcpSocket* opponent = list.getPlayerSocket(opponentName);
     if(opponent == nullptr)
         socket->write("Oponentul nu este conectat!");
     else
     {
         opponent->write(("Jucatorul: "+playerName+" v-a provocat la un duel!").toUtf8());
     }
}
