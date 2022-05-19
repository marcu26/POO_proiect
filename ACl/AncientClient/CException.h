#pragma once
#include <string>
#include "IException.h"
class CException :
    public IException
{
    QString msg;
public:
     QString getMsg() override{ return msg; };
};

