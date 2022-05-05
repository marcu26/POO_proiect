#include "clegatura.h"
#include "cserver.h"

CLegatura::CLegatura()
{

}

void CLegatura::sendPlayersList(QTcpSocket *socket)
{
    CClientList &list = CClientList::getInstance();

    list.eraseInactivePointer();
    QString players = "3 ";
    players += list.getPlayersList();

    socket->flush();
    socket->write(players.toUtf8());
}

void CLegatura::sendPlayersListWithoutUser(QTcpSocket *socket, qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();

    list.eraseInactivePointer();
     QString players = "4 ";
     players += list.getPlayerListWithoutUser(socketDescriptor);

    socket->flush();
    socket->write(players.toUtf8());
}

void CLegatura::sendMessageToOpponent(QTcpSocket *socket,QString playerName ,QString opponentName)
{
     CClientList &list = CClientList::getInstance();

     list.eraseInactivePointer();
     QTcpSocket* opponent = list.getPlayerSocket(opponentName);
     if(opponent == nullptr)
     {
         socket->flush();
         socket->write("5 0");              //jucatorul nu este conectat
     }
     else
     {
         socket->flush();
         opponent->write(("5 "+playerName).toUtf8());    //jucatorul este conectat
     }
}

void CLegatura::setPauseForOpponent(QTcpSocket *socket, QString opponentName)
{
     CClientList &list = CClientList::getInstance();

     list.eraseInactivePointer();
      QTcpSocket* opponent = list.getPlayerSocket(opponentName);
      if(opponent == nullptr)
      {
          socket->flush();
          socket->write("8 Oponentul s-a deconectat!");
      }
      else
      {
          opponent->flush();
          opponent->write("8 PAUZA");
      }

}

bool CLegatura::verfyConection(QString playerName)
{
    CClientList &list = CClientList::getInstance();

    list.eraseInactivePointer();
    CClient * client = list.getPlayer(playerName);
    if(client == nullptr)
        return 0;
    return 1;
}

bool CLegatura::sendAnswearToChallenger(QString challenger, QString playerName, QString raspuns)
{
    CClientList &list = CClientList::getInstance();

    list.eraseInactivePointer();
    QTcpSocket* challen = list.getPlayerSocket(challenger);

    if(challenger != nullptr)
    {
        challen->flush();
        challen->write(("9 "+raspuns+" "+playerName).toUtf8());
    }
}
