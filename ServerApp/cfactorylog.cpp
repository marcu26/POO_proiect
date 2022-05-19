#include "cfactorylog.h"
#include "cerrorlog.h"
#include "cregisterlog.h"
#include "cloginlog.h"
#include "clogoutlog.h"

ILog *CFactoryLog::getLog(Type id)
{
    if(id == ERROR)
        return new CErrorLog();
    if(id == REGISTER)
        return new CRegisterLog();
    if (id == LOG_IN)
        return new CLoginLog();
    if(id == LOG_OUT)
        return new CLogoutLog();
}
