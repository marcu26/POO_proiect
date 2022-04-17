#ifndef SINGLETONWO_H
#define SINGLETONWO_H
#include "mainwindow.h"
#include "connectw.h"
#include "CClient.h"
#include "singinwindow.h"


class Singleton
{
private:
    static Singleton *instanta;
    Singleton(){};
    ~Singleton(){};


public:
    static Singleton& getInstance();
    static void destroyInstance();

private:
    MainWindow mw;
    ConnectW cw;
    SingInWindow sw;
public:
    void showMW(){mw.show();};
    void hideMW(){mw.hide();};
    void showCW(){cw.show();};
    void hideCW(){cw.hide();};
    void showSW(){sw.show();};
    bool hasSpaces(QString s);
    CClient cl;






};

#endif // SINGLETONWO_H
