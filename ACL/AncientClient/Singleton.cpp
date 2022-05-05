#include "Singleton.h"
#include <fstream>

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

void Singleton::connectToServer()
{
    std::string paths=path.toStdString();

    std::ifstream f(paths+"/Config/server_config.txt");
    std::string s;
    int port;
    f >> s;
    f >> port;

    QString ip= QString::fromStdString(s);

    qDebug()<<ip;
    qDebug()<<port;

    cl.connect_client(ip,port);
}

Singleton::Singleton()
{
    path=qApp->applicationDirPath();
    path=path+"/../../AncientClient";
    qDebug()<<path;
}

void Singleton::setBG()
{
    lw.changeStyleSheet();
    sw.changeStyleSheet();
    aw.changeStyleSheet();
    atw.changeStyleSheet();
    mw.changeStyleSheet();

}
