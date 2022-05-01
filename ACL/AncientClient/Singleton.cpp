#include "Singleton.h"


Singleton* Singleton::instanta = nullptr;

Singleton& Singleton::getInstance()
{
    if (Singleton::instanta == nullptr)
    {
        Singleton::instanta = new Singleton();

    }
    return *Singleton::instanta;
}

void Singleton::destroyInstance()
{
    if (Singleton::instanta != nullptr)
    {
        delete Singleton::instanta;
        Singleton::instanta = nullptr;

    }
}

bool Singleton::hasSpaces(QString s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            return 1;
        }
    }
    return 0;
}
