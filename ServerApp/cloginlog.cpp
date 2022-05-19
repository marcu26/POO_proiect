#include "cloginlog.h"
#include "cdatabase.h"

void CLoginLog::writeMessage(QString name)
{
    CDataBase &db = CDataBase::getInstance();

    db.writeInLog("LOG_IN","S-a logat: "+name);
}
