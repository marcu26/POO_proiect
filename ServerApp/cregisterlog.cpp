#include "cregisterlog.h"
#include "cdatabase.h"

void CRegisterLog::writeMessage(QString username)
{
    CDataBase &db = CDataBase::getInstance();

    db.writeInLog("REGISTER","S-a inregistrat un nou player");
}
