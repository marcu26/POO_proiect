#ifndef CLOG_H
#define CLOG_H

#include "cdatabase.h"
#include <QString>

class CLog
{
private:
    CDataBase db;

    static CLog *instance;

private:

    CLog();
    CLog(const CLog &obj) = delete;
    CLog(const CLog &&obj) = delete;

public:

    void destroy();
    static CLog &getInstance();

    void writeErrors(QString error);
    void PlayerLogIn(QString message);
    void PlayerLogOut(QString message);
    void PlayerRegister(QString message);
    void afisLog();
    //void PlayerLose(QString message);
};

#endif // CLOG_H
