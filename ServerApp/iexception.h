#ifndef IEXCEPTION_H
#define IEXCEPTION_H
#include <QString>

class IException
{
public:
    virtual QString getErrorMessage() = 0;
    virtual int getErrorNumber() = 0;
};

#endif // IEXCEPTION_H
