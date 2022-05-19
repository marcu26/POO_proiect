#ifndef CERRORLOG_H
#define CERRORLOG_H

#include "ilog.h"

class CErrorLog : public ILog
{
public:
   virtual void writeMessage(QString message) override;

    virtual ~CErrorLog() {};
};

#endif // CERRORLOG_H
