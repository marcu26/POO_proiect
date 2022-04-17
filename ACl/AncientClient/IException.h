#pragma once
#include <string>
class IException
{
public:
    virtual std::string getMsg()=0;
};

