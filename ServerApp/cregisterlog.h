#ifndef CREGISTERLOG_H
#define CREGISTERLOG_H

#include "ilog.h"

class CRegisterLog : public ILog
{
public:
    virtual void writeMessage(QString message) override;

    virtual ~CRegisterLog() {};
};

#endif // CREGISTERLOG_H
