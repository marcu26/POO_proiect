#include "cdatabase.h"
#include "SHA256.h"
#include <QDateTime>

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

void CDataBase::writeInLog(QString message)
{
    QSqlQuery query;
    QString insertValue = "INSERT INTO Journal (TimeStamp, Message) "
                "VALUES ('"+QDateTime::currentDateTime().toString()+"'"+",'"+message+"'"+")";

    query.exec(insertValue);
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
    QString updateQuery = "UPDATE Resurse SET Muncitori = " + l.value(1) + ",Galbeni =" + l.value(2) + ",AutorizatieMilitara=" + l.value(3) + ",AutorizatieMedicala=" + l.value(4) + ",Cavalerie=" + l.value(5) + ",Soldati=" + l.value(6) + ",Medici=" + l.value(7) + "WHERE PlayerID = " + id;
    QSqlQuery query;
    query.exec(updateQuery);
}
