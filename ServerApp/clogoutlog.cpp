#include "clogoutlog.h"
#include "cdatabase.h"

void CLogoutLog::writeMessage(QString name)
{
    CDataBase &db = CDataBase::getInstance();

    db.writeInLog("LOG_OUT","S-a deconectat: "+name);
}
