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

    static CDataBase *instance;

private:
     CDataBase();
     CDataBase(const CDataBase &obj) = delete;
     CDataBase(const CDataBase &&obj) = delete;

     bool usernameExist(const QString &username);
public:
    static CDataBase& getInstance();
    void destroy();

    void connectDataBase();

    void readCredentials();
    QString getPlayerID(QString username);
    QStringList identifyResources(QString idPlayer);
    bool verifyCredentials(const QString &username, const QString &pass);
    int addUser(const QString &username, const QString &pass);
    QString getResources(const QString &username);
    void updateResources(QStringList l, QString username);
    QString getOpponentArmy(QString opponentName);
    int getNumberSoldiers(QString name);
    int getNumberCav(QString name);
    int getNumberMeds(QString name);
    int getNumberInitialSoldiers(QString name);
    int getNumberInitialCav(QString name);
    int getNumberInitialMeds(QString name);
    void addFighters(QString player_1, QString player_2);
    void updateArenaPlayer(QString playerName, int Soldati, int Cavalerie, int Medici);
    void deletePLayerFromArena(QString name);
    void updateWin(QString name);
    void updateLose(QString name);
    void updateTroups(QStringList, QString name);
    void writeInLog(QString type,QString message);
    QString getStats(QString username);

    ~CDataBase();
};

#endif // CDATABASE_H
