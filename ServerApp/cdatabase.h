#ifndef CDATABASE_H
#define CDATABASE_H

#include <QtSql>
#include <QVector>
#include <QPair>

class CDataBase
{
private:
    friend class CLog;

    QSqlDatabase db;
    QVector<QPair<QString, QString>> credentials;

private:
     bool usernameExist(const QString &username);
     QString getPlayerID(QString username);
     QStringList identifyResources(QString idPlayer);

     void writeInLog(QString message);
public:
     CDataBase();
    void connectDataBase();

    void readCredentials();
    bool verifyCredentials(const QString &username, const QString &pass);
    int addUser(const QString &username, const QString &pass);
    QString getResources(const QString &username);
    void updateResources(QStringList l, QString username);
    QString getOpponentArmy(QString opponentName);
    int getNumberSoldiers(QString name);
    int getNumberCav(QString name);
    int getNumberMeds(QString name);
};

#endif // CDATABASE_H
