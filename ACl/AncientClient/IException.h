#pragma once
#include <string>
#include <QString>
class IException
{
public:
    virtual QString getMsg()=0;
};

