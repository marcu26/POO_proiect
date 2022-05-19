#ifndef ILOG_H
#define ILOG_H

#include <QString>

class ILog
{
public:
    virtual void writeMessage(QString message) = 0;
};

#endif // ILOG_H
