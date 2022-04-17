#include "cdatabase.h"

CDataBase::CDataBase()
{

}

void CDataBase::connectDataBase(const QString &socketDescriptor)
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

bool CDataBase::verifyCredentials(const QString &username, const QString &pass)
{
    credentials.clear();
    readCredentials();              //facem update la lista 

    for(auto &it:credentials)
    {
        if(it.first == username && it.second== pass)
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

    QSqlQuery query;
    QString insertValue = "INSERT INTO Credentials (Username, Password) "
                "VALUES ('"+username+"'"+","+"'"+pass+"');";

    query.exec(insertValue);

    credentials.clear();
    readCredentials();              //facem update la lista 

    return 1;
}
