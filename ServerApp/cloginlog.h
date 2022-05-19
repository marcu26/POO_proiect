#ifndef CLOGINLOG_H
#define CLOGINLOG_H

#include "ilog.h"

class CLoginLog : public ILog
{
public:
   virtual void writeMessage(QString name) override;

    virtual ~CLoginLog() {};
};

#endif // CLOGINLOG_H
