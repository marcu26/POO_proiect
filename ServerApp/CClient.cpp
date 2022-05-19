#include "CClient.h"
#include "clegatura.h"
#include "cexception.h"
#include "CFactoryLog.h"

CClient::CClient(qintptr ID, QObject *parent)
    :AbsClient(ID,parent)
{
    connect(socket, SIGNAL(readyRead()),this,SLOT(onReadyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()),this,SLOT(onDisconnected()),Qt::DirectConnection);

    qDebug() <<"Client: "<<this->socketDescriptor<<"\n";
    active = 1;
}

void CClient::onReadyRead()
{
        QByteArray data = socket->readAll();

        QString req(data);

        qDebug() <<socketDescriptor<<": "<<req<<"\n";

        if (req[0] == '1')
            autentification(req);               //cerere pt autentificare (1 username pass)

        else if (req[0] == '2')
            registerUser(req);                      //cerere pt inregistrare (2 username pass)

        else if (req[0] == '3')
            CLegatura::sendPlayersList(socket);   //trimite lista jucatorilor cu spatiu intre ei, inclusiv si userul care trimite requestul (3)

        else if (req[0] == '4')
            CLegatura::sendPlayersListWithoutUser(socket, socketDescriptor);  //trimite lista jucatorilor fara a se pune si pe el (4) //mi-i arata doar pe cei care nu sunt intr-un duel

        else if (req[0] == '5')
            duelRequest(req);               //trimite provocarea la duel (5 playerProvocat)

        else if (req[0] == '6')
            transmitResource();              //trimite jucatorului resursele aferente

        else if (req[0] == '7')
            saveResource(req);              //salvez updateurile resurselor primite de la client, le primesc astfefl (7 x y z ...);

        else if(req[0]=='8')
            setPauseForOpponent(req);       // (8 opponenName) (v-a trebui ca toma sa retina numele oponentului)

        else if (req[0] == 'e')
            endPauseForOpponent(req);       //(e opponentName)

        else if(req[0] == '9')
            recieveChallengedAnswer(req);  //(9 opponent raspuns) //raspuns = 0 sau 1

        else if (req[0] == 'a')
            sendOpponentArmy(req);         //(a opponentName)

        else if (req[0] == 'b')            //(b 1/2 opponentName 1/2)
            manageAttack(req);

        else if(req[0] == 'm')
            manageHeal(req);            //(m 1/2/3 opponentName)

        else if (req[0] == 'q')
            manageLoseMasaVerde(req);       //(q opponentName)

        else if (req[0] == 'k')
            deleteName();

        else if (req[0] == 's')
            transmitStats();

        else
        {
            throw new CException("Protocol nerecunoscut!",-7);
        }
}

void CClient::felicita()
{
    socket->flush();
    socket->write("\n\n\n\n\n\n\n\nFelicitari!!!!!!!!!!!!!!!!!!");
}

void CClient::autentification(QString &req)             //VERIFICARE DACA NU ESTE DEJA CONECTAT
{   
    database.connectDataBase();
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    qDebug() <<l.value(1)<<" --- "<<l.value(2)<<"\n";

    if(database.verifyCredentials(l.value(1), l.value(2))==true && CLegatura::verfyConection(l.value(1))==0)
       {
        this->username = l.value(1);
       // CLog::getInstance().PlayerLogIn("S-a autentificat utilizatorul: "+this->username);
        CFactoryLog::getLog(LOG_IN)->writeMessage(username);
        socket->flush();
        socket->write("1 1");                   //REUSIT
        transmitResource();
        inArena = 0;
        }
    else
    {
       // CLog::getInstance().PlayerLogIn("Un utilizator a incercat sa se autentifice, dar nu credentialele nu au fost corecte");
        CFactoryLog::getLog(ERROR)->writeMessage("Un utilizator a incercat sa se autentifice, dar nu credentialele nu au fost corecte");
        socket->flush();
        socket->write("1 0");                   //ESUAT
    }

}

void CClient::registerUser(QString &req)
{
    database.connectDataBase();
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    qDebug() <<l.value(1)<<" --- "<<l.value(2)<<"\n";

    if(database.addUser(l.value(1),l.value(2))==-1)
    {
        socket->flush();
        socket->write("2 0");                   //ESUAT
        qDebug () <<"Username Luat\n";
        CFactoryLog::getLog(ERROR)->writeMessage("Un Utilizator a incercat sa se inregistreze cu un username deja existent");
    }
    else
    {
        this->username = l.value(1);         // -- nu trebuie sa ii dau username-ul pt ca nu se mai poate autentifica dupa
        socket->flush();
        socket->write("2 1");                   //REUSIT
        transmitResource();
        CFactoryLog::getLog(REGISTER)->writeMessage("");
    }
}

void CClient::duelRequest(QString req)
{
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

    CLegatura::sendMessageToOpponent(this->socket,this->username, l.value(1));
}

void CClient::transmitResource()
{
    database.connectDataBase();
    QString resources = "6 ";
    resources += database.getResources(this->username);

    socket->flush();
    socket->write(resources.toUtf8());

}

void CClient::saveResource(QString req)
{
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    
    database.connectDataBase();

    database.updateResources(l, this->username);
}

void CClient::setPauseForOpponent(QString req)
{
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

    CLegatura::setPauseForOpponent(this->socket, l.value(1));
}

void CClient::recieveChallengedAnswer(QString answ)
{
    QStringList l = answ.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

    if(l.value(2) == "1")
        inArena = 1;

    CLegatura::sendAnswerToChallenger(l.value(1),this->username,l.value(2));
}

void CClient::sendOpponentArmy(QString req)
{
    database.connectDataBase();
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    QString res = database.getOpponentArmy(l.value(1));

    socket->flush();
    QString answ = "a "+res;
    qDebug()<<answ;
    socket->write(answ.toUtf8());
}

void CClient::manageAttack(QString req)
{
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    CLegatura::sendAttackMoveResult(this->socket, this->username, l.value(2), l.value(1), l.value(3));
}

void CClient::endPauseForOpponent(QString req)
{
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

    CLegatura::endPauseForOpponent(l.value(1));
}

void CClient::manageHeal(QString req)
{
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

    CLegatura::sendHealResults(this->username,l.value(3),l.value(2));
}

void CClient::manageLoseMasaVerde(QString req)
{
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

    CLegatura::loseMasaVerde(this->username, l.value(1));
}

void CClient::deleteName()
{
    this->username = "";
    //qDebug() <<"A AJUNS AICI";
}

void CClient::transmitStats()
{
    QString s = database.getStats(this->username);
    QString stats = "s "+s;
    qDebug()<<stats;
    socket->flush();
    socket->write(stats.toUtf8());
}

void CClient::onDisconnected()
{
    qDebug() <<"S-a deconectat: "<<this->socketDescriptor<<"\n";
    active = 0;
    CFactoryLog::getLog(LOG_OUT)->writeMessage(this->getUsername());
    socket->deleteLater();
    database.deletePLayerFromArena(this->username);
}
