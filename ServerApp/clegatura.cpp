#include "clegatura.h"
#include "cserver.h"
#include "cdatabase.h"

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
         QString ms = "5 "+playerName;
         qDebug() << ms;
         opponent->write(ms.toUtf8());    //jucatorul este conectat
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


void CLegatura::sendAnswerToChallenger(QString challenger, QString playerName, QString raspuns)
{
    CClientList &list = CClientList::getInstance();

    list.eraseInactivePointer();
    QTcpSocket* challen = list.getPlayerSocket(challenger);

    if(challen != nullptr)
    {
        challen->flush();
        QString ms = "9 "+raspuns+" "+playerName;
        challen->write(ms.toUtf8());
    }
}

void CLegatura::sendAttackMoveResult(QTcpSocket *player, QString playerName,QString opponentName, QString attackTroup, QString opponentTroup)
{
   /* CClientList &list = CClientList::getInstance();

    list.eraseInactivePointer();
    QTcpSocket *opponent = list.getPlayerSocket(opponentName);

    CDataBase db;

    db.connectDataBase();

    int numberAttack, numberOpponent;

    if(attackTroup == "1")
        numberAttack = db.getNumberSoldiers(playerName);
    else if (attackTroup == "2")
    {
        numberAttack = db.getNumberCav(playerName);
        numberAttack *=2;
    }

    if(opponentTroup == "1")
        numberOpponent = db.getNumberSoldiers(opponentName);
    else if(opponentTroup == "2")
        numberOpponent = db.getNumberCav(opponentName);
    else if(opponentTroup == "3")
        numberOpponent = db.getNumberMeds(opponentName);

    numberOpponent -= numberAttack;
    if(numberOpponent < 0)
        numberOpponent = 0;
     */

}










