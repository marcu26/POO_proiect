#ifndef CDATABASE_H
#define CDATABASE_H

#include <QtSql>
#include <QVector>
#include <QPair>

class CDataBase
{
private:
    QSqlDatabase db;
    QVector<QPair<QString, QString>> credentials;

private:
     bool usernameExist(const QString &username);

public:
     CDataBase();
    void connectDataBase(const QString &socketDescriptor);

    void readCredentials();
    bool verifyCredentials(const QString &username, const QString &pass);
    int addUser(const QString &username, const QString &pass);
};

#endif // CDATABASE_H
