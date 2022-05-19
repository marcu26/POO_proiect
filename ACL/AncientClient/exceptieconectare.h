#ifndef EXCEPTIECONECTARE_H
#define EXCEPTIECONECTARE_H

#include "IException.h"


class ExceptieConectare : public IException
{
private:
    QString msg;
public:
    ExceptieConectare();
    ExceptieConectare(QString msg){this->msg=msg;};

    QString getMsg() override{return msg;};
};

#endif // EXCEPTIECONECTARE_H
