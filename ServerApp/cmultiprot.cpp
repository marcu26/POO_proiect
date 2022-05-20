#include "cmultiprot.h"
#include "clegatura.h"
#include "CClientList.h"

CMultiProt::CMultiProt()
{

}

void CMultiProt::executeProtocol(CDataBase &database, QString req, qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();
    IClient *client = list[socketDescriptor];

    if(req[0] == '3')
       CLegatura::sendPlayersList(client->getSocket());
    else if (req[0] == '4')
        CLegatura::sendPlayersList(client->getSocket(), socketDescriptor);
    else if(req[0] == '5')
        duelRequest(req, socketDescriptor);
    else if (req[0] == '8')
        setPauseForOpponent(req, socketDescriptor);
    else if (req[0] == 'e')
        endPauseForOpponent(req);
    else if (req[0] == '9')
        recieveChallengedAnswer(req, socketDescriptor);
    else if (req[0] == 'a')
        sendOpponentArmy(database, req, socketDescriptor);
    else if (req[0] == 'b')
        manageAttack(req, socketDescriptor);
    else if (req[0] == 'm')
        manageHeal(req, socketDescriptor);
    else if (req[0] == 'q')
        manageLoseMasaVerde(req, socketDescriptor);
}

void CMultiProt::duelRequest(QString req, qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();
    IClient *client = list[socketDescriptor];

    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

    CLegatura::sendMessageToOpponent(client->getSocket(),client->getUsername(), l.value(1));
}

void CMultiProt::setPauseForOpponent(QString req, qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();
    IClient *client = list[socketDescriptor];
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

    CLegatura::setPauseForOpponent(client->getSocket(), l.value(1));
}

void CMultiProt::endPauseForOpponent(QString req)
{
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

    CLegatura::endPauseForOpponent(l.value(1));
}

void CMultiProt::recieveChallengedAnswer(QString answ, qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();
    IClient *client = list[socketDescriptor];
    QStringList l = answ.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

        if(l.value(2) == "1")
            client->setInArena(1);

        CLegatura::sendAnswerToChallenger(l.value(1),client->getUsername(),l.value(2));
}

void CMultiProt::sendOpponentArmy(CDataBase& database, QString req, qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();
    IClient *client = list[socketDescriptor];

   database.connectDataBase();
   QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
   QString res = database.getOpponentArmy(l.value(1));

   client->getSocket()->flush();
   QString answ = "a "+res;
   qDebug()<<answ;
   client->getSocket()->write(answ.toUtf8());
}

void CMultiProt::manageAttack(QString req, qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();
    IClient *client = list[socketDescriptor];

    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    CLegatura::sendAttackMoveResult(client->getSocket(), client->getUsername(), l.value(2), l.value(1), l.value(3));
}

void CMultiProt::manageHeal(QString req, qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();
    IClient *client = list[socketDescriptor];

    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

    CLegatura::sendHealResults(client->getUsername(),l.value(3),l.value(2));
}

void CMultiProt::manageLoseMasaVerde(QString req, qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();
    IClient *client = list[socketDescriptor];

    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    qDebug() <<"MASA VERDEEEEEEEEEE";
    CLegatura::loseMasaVerde(client->getUsername(), l.value(1));
}
