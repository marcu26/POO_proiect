#ifndef CLOGOUTLOG_H
#define CLOGOUTLOG_H

#include "ilog.h"

class CLogoutLog : public ILog
{
public:
    virtual void writeMessage(QString name) override;

     virtual ~CLogoutLog() {};
};

#endif // CLOGOUTLOG_H
