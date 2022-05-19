#include "cerrorlog.h"
#include "cdatabase.h"


void CErrorLog::writeMessage(QString message)
{
    CDataBase &db = CDataBase::getInstance();

    db.writeInLog("ERROR",message);
}
