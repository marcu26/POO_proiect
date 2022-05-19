#include "clog.h"

CLog *CLog::instance = nullptr;
CLog::CLog()
{

}

void CLog::destroy()
{
    if(this->instance != nullptr)
    {
        delete this->instance;
        this->instance = nullptr;
    }
}

CLog &CLog::getInstance()
{
    if(instance == nullptr)
    {
        instance = new CLog();
    }
    return *instance;
}

void CLog::writeErrors(QString error)
{
    db.connectDataBase();
    db.writeInLog(error);
}

void CLog::PlayerLogIn(QString message)
{
    db.connectDataBase();
    db.writeInLog(message);
}

void CLog::PlayerLogOut(QString message)
{
    db.connectDataBase();
    db.writeInLog(message);
}

void CLog::PlayerRegister(QString message)
{
    db.connectDataBase();
    db.writeInLog(message);
}

void CLog::afisLog()
{

}
