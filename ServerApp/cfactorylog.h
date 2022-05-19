#ifndef CFACTORYLOG_H
#define CFACTORYLOG_H
#include "ilog.h"

enum Type {ERROR, REGISTER, LOG_IN, LOG_OUT};


class CFactoryLog
{
public:
    static ILog *getLog(Type id);

};

#endif // CFACTORYLOG_H
