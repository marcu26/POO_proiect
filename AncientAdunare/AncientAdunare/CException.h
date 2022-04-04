#pragma once
#include <string>
#include "IException.h"
class CException :
    public IException
{
    std::string msg;
public:
    std::string getMsg() { return msg; };
};

