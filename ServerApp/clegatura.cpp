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
     players += list.getPlayerListWithoutUser(socketDescriptor);            //mi-i arata doar pe cei care nu sunt intr-un duel

    socket->flush();
    socket->write(players.toUtf8());
}

void CLegatura::sendMessageToOpponent(QTcpSocket *socket,QString playerName ,QString opponentName)
{
     CClientList &list = CClientList::getInstance();

     list.eraseInactivePointer();
     QTcpSocket* opponent = list.getPlayerSocket(opponentName);
     if(opponent == nullptr || list.getPlayerInArena(opponentName) == 1)
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
          //socket->write("8 Oponentul s-a deconectat!");
      }
      else
      {
          opponent->flush();
          opponent->write("8");
      }

}

void CLegatura::endPauseForOpponent(QString opponentName)
{
    CClientList &list = CClientList::getInstance();

    list.eraseInactivePointer();
    QTcpSocket* opponent = list.getPlayerSocket(opponentName);

    opponent->flush();
    opponent->write("e");
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
        if(raspuns == "1")
        {
            //adauag oponentii in arena
            CDataBase db;
            db.connectDataBase();
            db.addFighters(challenger, playerName);
            list.setOnInArena(challenger);
        }
    }
}

void CLegatura::modifyTroupNumber(int numberAttack, int &troup)
{
    troup -= numberAttack;
    if(troup<0)
        troup = 0;
}

void CLegatura::ifZero(int &ivalue, float fvalue)
{
    if(fvalue>0 && fvalue <1)
        ivalue = 1;
}

void CLegatura::updateLostResources(QString name)
{
    CDataBase db;
    db.connectDataBase();

    QStringList l = db.identifyResources(db.getPlayerID(name));

    qDebug() << l.value(0)<< " "<< l.value(5)<<" "<<l.value(4)<<" "<<l.value(6);

    float mun = l.value(0).toFloat();
    float sold = l.value(5).toFloat();
    float cav = l.value(4).toFloat();
    float med = l.value(6).toFloat();


    mun -= (mun*0.1);
    sold -= (sold*0.1);
    cav -= (cav*0.1);
    med -= (med*0.1);

    int imun = mun;
    int isold = sold;
    int icav = cav;
    int imed = med;

 //   qDebug() <<isold;

    ifZero(imun, mun);
    ifZero(isold, sold);
    ifZero(icav, cav);
    ifZero(imed, med);

    //qDebug() << imun<< " "<< isold<<" "<<icav<<" "<<imed;

   // qDebug() <<isold;

    QStringList l2;

    l2.push_back(QString::number(imun));
    l2.push_back(QString::number(icav));
    l2.push_back(QString::number(isold));
    l2.push_back(QString::number(imed));

   /* l.value(0) = QString::number(imun);
    l.value(5) = QString::number(isold);
    l.value(4) = QString::number(icav);
    l.value(6) = QString::number(imed);
    */

   // qDebug() << l2.value(0)<< " "<< l2.value(5)<<" "<<l2.value(4)<<" "<<l.value(6);

    db.updateTroups(l2,name);
    db.updateLose(name);
}

void CLegatura::sendAttackMoveResult(QTcpSocket *player, QString playerName,QString opponentName, QString attackTroup, QString opponentTroup)
{
    CClientList &list = CClientList::getInstance();

    list.eraseInactivePointer();
    QTcpSocket *opponent = list.getPlayerSocket(opponentName);

    CDataBase db;

    db.connectDataBase();

    int numberAttack;

    if(attackTroup == "1")
        numberAttack = db.getNumberSoldiers(playerName);
    else if (attackTroup == "2")
    {
        numberAttack = db.getNumberCav(playerName);
        numberAttack *=2;
    }

    int op_troup[4];

    op_troup[0] = db.getNumberSoldiers(opponentName);
    op_troup[1] = db.getNumberCav(opponentName);
    op_troup[2] = db.getNumberMeds(opponentName);

    if(opponentTroup == "1")
    {
       modifyTroupNumber(numberAttack, op_troup[0]);
    }
    if(opponentTroup == "2")
    {
        modifyTroupNumber(numberAttack, op_troup[1]);
    }
    if(opponentTroup == "3")
    {
        modifyTroupNumber(numberAttack, op_troup[2]);
    }

    db.updateArenaPlayer(opponentName, op_troup[0], op_troup[1], op_troup[2]);

    if(op_troup[0] == 0 && op_troup[1]==0 && op_troup[2]==0)
    {
        db.deletePLayerFromArena(playerName);
        db.deletePLayerFromArena(opponentName);

        opponent->write("l");

        player->write("w");

        updateLostResources(opponentName);
        db.updateWin(playerName);

        db.connectDataBase();
        QString resources = "6 ";
        resources += db.getResources(opponentName);
        qDebug() <<resources;

        opponent->flush();
        opponent->write(resources.toUtf8());

        list.setOffInArena(playerName);
        list.setOffInArena(opponentName);
    }
    else
    {
        QString answ_op = "c "+QString::number(op_troup[0])+" "+QString::number(op_troup[1])+" "+QString::number(op_troup[2]);      //()
        qDebug() <<answ_op;
        QString answ_at = "d "+QString::number(op_troup[0])+" "+QString::number(op_troup[1])+" "+QString::number(op_troup[2]);
        qDebug() <<answ_at;

        opponent->write(answ_op.toUtf8());
        player->write(answ_at.toUtf8());
    }
}

void CLegatura::healTroup(int numberMed, int &troup, int initTroup)
{
    troup += numberMed;
    if(troup>initTroup)
        troup = initTroup;
}

void CLegatura::sendHealResults(QString playerName, QString healedTroup, QString opponentName)
{
    CClientList &list = CClientList::getInstance();
    list.eraseInactivePointer();

    CDataBase db;

    int numberMed = db.getNumberMeds(playerName);
    int v[4];

    v[0] = db.getNumberSoldiers(playerName);
    v[1] = db.getNumberCav(playerName);
    v[2] = db.getNumberMeds(playerName);

    if(healedTroup == "1")
    {
        int initSold = db.getNumberInitialSoldiers(playerName);
        qDebug() <<initSold;
        healTroup(numberMed, v[0], initSold);
    }
    if(healedTroup == "2")
    {
        int initCav = db.getNumberInitialCav(playerName);
        qDebug() << initCav;
        healTroup(numberMed, v[1], initCav);
    }
   /* if(healedTroup == "3")
    {
        int initMed = db.getNumberInitialMeds(playerName);      //
        qDebug() << initMed;
        healTroup(numberMed, v[2], initMed);
    }*/

    QTcpSocket *player = list.getPlayerSocket(playerName);
    QTcpSocket *opponent = list.getPlayerSocket(opponentName);

    db.updateArenaPlayer(playerName, v[0], v[1], v[2]);

    QString answ_op = "f "+QString::number(v[0])+" "+QString::number(v[1])+" "+QString::number(v[2]);
    QString answ_play = "g "+QString::number(v[0])+" "+QString::number(v[1])+" "+QString::number(v[2]);

    opponent->write(answ_op.toUtf8());
    player->write(answ_play.toUtf8());
}

void CLegatura::loseMasaVerde(QString playerName, QString opponentName)
{
    qDebug() <<"Lose Masa Verde";
    CClientList &list = CClientList::getInstance();
    list.eraseInactivePointer();

    CDataBase db;

    db.connectDataBase();

    db.deletePLayerFromArena(playerName);
    db.deletePLayerFromArena(opponentName);

    QTcpSocket *player = list.getPlayerSocket(playerName);
    QTcpSocket *opponent = list.getPlayerSocket(opponentName);

    opponent->write("w");
    db.updateWin(opponentName);

    player->write("l");
    updateLostResources(playerName);
    db.updateLose(playerName);

    db.connectDataBase();
    QString resources = "6 ";
    resources += db.getResources(playerName);

    player->flush();
    player->write(resources.toUtf8());

    list.setOffInArena(playerName);
    list.setOffInArena(opponentName);
}












