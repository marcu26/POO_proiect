#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#include "iexception.h"

class CException : public IException
{
protected:
    QString message;
    int error_number;
public:
    CException(const QString& m, const int &number);

    virtual QString getErrorMessage() override  {return message;}
    virtual int getErrorNumber() override {return error_number;}
};

#endif // CEXCEPTION_H
