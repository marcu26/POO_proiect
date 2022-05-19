#include "cdatabase.h"
#include "SHA256.h"
#include <QDateTime>

CDataBase *CDataBase::instance = nullptr;
CDataBase::CDataBase()
{

}

void CDataBase::connectDataBase()
{
    QString servername="localhost";
    QString dbname="POO";
    db = QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions();
    QString dsn=QString("DRIVER={SQL Server Native Client 11.0};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername,dbname);
    db.setDatabaseName(dsn);
    if(db.open())
        qDebug()<<"Open completed\n";
    else
    {
        qDebug()<<"OPEN FAILED\n"<<db.lastError().text();
        exit(0);
    }
    readCredentials();
}

void CDataBase::readCredentials()
{
     QSqlQuery query ;
     query.exec("SELECT * FROM Credentials");

     while(query.next())
        {
           QString str = query.value(1).toString()+query.value(2).toString();
           QStringList l = str.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

           QPair<QString, QString> pair;
           pair.first = l.value(0);
           pair.second = l.value(1);

           credentials.push_back(pair);

        }
}

QString CDataBase::getPlayerID(QString username)
{
    QSqlQuery query ;
    query.exec("SELECT * FROM Credentials");

    while(query.next())
       {
        QString id = query.value(0).toString();
        QString sqlName = query.value(1).toString();
        QStringList l =  sqlName.split(" ");

        if (username == l.value(0))
            return id;

       }
    return "";
}

bool CDataBase::verifyCredentials(const QString &username, const QString &pass)
{
    credentials.clear();
    readCredentials();              //facem update la lista 

    std::string hash_pass = sha256(pass.toStdString());
    for(auto &it:credentials)
    {
        if(it.first == username && it.second== QString::fromStdString(hash_pass))
                return true;

    }
    return false;
}

bool CDataBase::usernameExist(const QString &username)
{
    credentials.clear();
    readCredentials();              //facem update la lista 

    for(auto &it:credentials)
    {
        if(it.first == username)
            return true;
    }
    return false;
}


int CDataBase::addUser(const QString &username, const QString &pass)
{

    if(usernameExist(username))
        return -1;

    std::string hash_pass = sha256(pass.toStdString());
    QSqlQuery query;
    QString insertValue = "INSERT INTO Credentials (Username, Password) "
                "VALUES ('"+username+"'"+","+"'"+QString::fromStdString(hash_pass)+"');";

    query.exec(insertValue);
    QString id = getPlayerID(username);

    if(id== "")
        return -1;

    insertValue = ("INSERT INTO Resurse (PlayerID, Muncitori, Galbeni, AutorizatieMilitara, AutorizatieMedicala, Cavalerie, Soldati, Medici) "
                 "VALUES (?,?,?,?,?,?,?,?)");
    query.prepare(insertValue);
    query.bindValue(0,id.toInt());
    query.bindValue(1,5);
    query.bindValue(2,300);
    query.bindValue(3,0);
    query.bindValue(4,0);
    query.bindValue(5,0);
    query.bindValue(6,0);
    query.bindValue(7,0);
    query.exec();

    insertValue = "INSERT INTO Statistici (PlayerID, Castiguri, Infrangeri)"
            "VALUES ('"+id+"',0,0)";

    query.exec(insertValue);

    credentials.clear();
    readCredentials();              //facem update la lista 

    return 1;
}

QStringList CDataBase::identifyResources(QString idPlayer)
{
    QSqlQuery query;
    query.exec("SELECT * FROM Resurse");

    while (query.next())
    {   
        QString id = query.value(1).toString();
        QString str = query.value(2).toString() + " " + query.value(3).toString() + " " + query.value(4).toString() + " " + query.value(5).toString() + " " + query.value(6).toString() + " " + query.value(7).toString() + " " + query.value(8).toString();
        QStringList l = str.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

        if (id == idPlayer)
        {
            return l;
        }
    }
   QStringList l;
   l.push_back("");

   return l;
}

void CDataBase::writeInLog(QString type,QString message)
{
    QSqlQuery query;
    QString insertValue = "INSERT INTO Journal (TimeStamp,Type ,Message) "
                "VALUES ('"+QDateTime::currentDateTime().toString()+"'"+",'"+type+"'"+",'"+message+"'"+")";

    query.exec(insertValue);
}

QString CDataBase::getStats(QString username)
{
    QString id = getPlayerID(username);

    QSqlQuery query;
    QString s = "SELECT Castiguri, Infrangeri from"
           " Statistici inner join Credentials "
           " on Statistici.PlayerID = Credentials.ID "
         "   where Credentials.ID = "+id;
    query.exec(s);
    query.next();

    QString stats = query.value(0).toString()+" "+query.value(1).toString();
    return stats;
}

CDataBase& CDataBase::getInstance()
{
    if(instance == nullptr)
    {
        instance = new CDataBase();
    }
    return *instance;
}

void CDataBase::destroy()
{
    if(this->instance !=nullptr)
       {
         delete this->instance;
         this->instance = nullptr;
       }
}

QString CDataBase::getResources(const QString& username)
{
    QString id = getPlayerID(username);
    QStringList l = identifyResources(id);

    QString res = "";

    for (auto& it : l)
    {
        res += it;
        res += " ";
    }

    return res;
}

void CDataBase::updateResources(QStringList l, QString username)
{
    QString id = getPlayerID(username);
    QString updateQuery = "UPDATE Resurse SET Muncitori = " + l.value(1) + ",Galbeni =" + l.value(2) + ",AutorizatieMilitara=" + l.value(3) + ",AutorizatieMedicala=" + l.value(4) + ",Cavalerie=" + l.value(5) + ",Soldati=" + l.value(6) + ",Medici=" + l.value(7) + "WHERE PlayerID = '" + id+"'";
    QSqlQuery query;
    query.exec(updateQuery);
}

void CDataBase::updateTroups(QStringList l, QString name)
{
    QString id = getPlayerID(name);
    QString updateQuery = "UPDATE Resurse SET Muncitori = " + l.value(0) + ",Cavalerie=" + l.value(1) + ",Soldati=" + l.value(2) + ",Medici=" + l.value(3) + "WHERE PlayerID = '" + id+"'";
    QSqlQuery query;
    query.exec(updateQuery);
}

CDataBase::~CDataBase()
{
   destroy();
}


QString CDataBase::getOpponentArmy(QString opponentName)
{
    QString q = "SELECT RESURSE.Soldati, RESURSE.Cavalerie, RESURSE.Medici FROM Resurse INNER JOIN Credentials ON Resurse.PlayerID = Credentials.ID WHERE Credentials.Username = '"+opponentName+"'";
    QSqlQuery query;
    query.exec(q);
    QString res;

    while (query.next())
    {
      res = query.value(0).toString()+" "+query.value(1).toString()+" "+query.value(2).toString();
      qDebug() <<res;
    }
    return res;
}

int CDataBase::getNumberSoldiers(QString name)
{
    QString q = "SELECT Arena.Soldati FROM Arena INNER JOIN Credentials ON Arena.ID = Credentials.ID WHERE Credentials.Username = '"+name+"'";

    QSqlQuery query;
    query.exec(q);
    QString res;

    while (query.next())
        res = query.value(0).toString();

    return res.toInt();

}

int CDataBase::getNumberCav(QString name)
{
    QString q = "SELECT Arena.Cavalerie FROM Arena INNER JOIN Credentials ON Arena.ID = Credentials.ID WHERE Credentials.Username = '"+name+"'";

    QSqlQuery query;
    query.exec(q);
    QString res;

    while (query.next())
        res = query.value(0).toString();

    return res.toInt();

}

int CDataBase::getNumberMeds(QString name)
{
    QString q = "SELECT Arena.Medici FROM Arena INNER JOIN Credentials ON Arena.ID = Credentials.ID WHERE Credentials.Username = '"+name+"'";

    QSqlQuery query;
    query.exec(q);
    QString res;

    while (query.next())
        res = query.value(0).toString();

    return res.toInt();

}

int CDataBase::getNumberInitialSoldiers(QString name)
{
    QString q = "SELECT Resurse.Soldati FROM Resurse INNER JOIN Credentials ON Resurse.PlayerID = Credentials.ID WHERE Credentials.Username = '"+name+"'";

    QSqlQuery query;
    query.exec(q);
    QString res;

    while (query.next())
        res = query.value(0).toString();

    return res.toInt();
}

int CDataBase::getNumberInitialCav(QString name)
{
    QString q = "SELECT Resurse.Cavalerie FROM Resurse INNER JOIN Credentials ON Resurse.PlayerID = Credentials.ID WHERE Credentials.Username = '"+name+"'";

    QSqlQuery query;
    query.exec(q);
    QString res;

    while (query.next())
        res = query.value(0).toString();

    return res.toInt();
}

int CDataBase::getNumberInitialMeds(QString name)
{
    QString q = "SELECT Resurse.Medici FROM Resurse INNER JOIN Credentials ON Resurse.PlayerID = Credentials.ID WHERE Credentials.Username = '"+name+"'";

    QSqlQuery query;
    query.exec(q);
    QString res;

    while (query.next())
        res = query.value(0).toString();

    return res.toInt();
}

void CDataBase::addFighters(QString player_1, QString player_2)
{
     QString id_1 = getPlayerID(player_1);
     QString id_2 = getPlayerID(player_2);

     QStringList l_1 = identifyResources(id_1);
     QStringList l_2 = identifyResources(id_2);

     QString q_1 = "INSERT INTO Arena (ID, Username, Cavalerie, Soldati, Medici) "
                "VALUES ('"+id_1+"', '"+player_1+"', '"+l_1.value(4)+"', '"+l_1.value(5)+"', '"+l_1.value(6)+"')";

     QString q_2 = "INSERT INTO Arena (ID, Username, Cavalerie, Soldati, Medici) "
                "VALUES ('"+id_2+"', '"+player_2+"', '"+l_2.value(4)+"', '"+l_2.value(5)+"', '"+l_2.value(6)+"')";

     QSqlQuery query;

     qDebug() <<q_1;
     qDebug () << q_2;

     query.exec(q_1);
     query.exec(q_2);
}

void CDataBase::updateArenaPlayer(QString playerName, int Soldati, int Cavalerie, int Medici)
{
    QString id = getPlayerID(playerName);
    QString q = "UPDATE Arena SET Soldati='"+QString::number(Soldati)+"', Cavalerie='"+QString::number(Cavalerie)+"', Medici='"+QString::number(Medici)+"' WHERE ID='"+id+"'";
    qDebug()<<q;
    QSqlQuery query;
    query.exec(q);
}

void CDataBase::deletePLayerFromArena(QString name)
{
    QString id = getPlayerID(name);

   if(id!="")
   {
        QString q = "DELETE FROM Arena WHERE ID='"+id+"'";
        QSqlQuery query;
        query.exec(q);
   }
}

void CDataBase::updateWin(QString name)
{
    QString id = getPlayerID(name);

    QString q = "UPDATE Statistici SET Castiguri = Castiguri+1 WHERE PlayerID = '"+id+"'";

    QSqlQuery query;
    query.exec(q);

    qDebug() <<q;
}

void CDataBase::updateLose(QString name)
{
    QString id = getPlayerID(name);

    QString q = "UPDATE Statistici SET Infrangeri = Infrangeri+1 WHERE PlayerID = '"+id+"'";

    QSqlQuery query;
    query.exec(q);

    qDebug() <<q;
}
