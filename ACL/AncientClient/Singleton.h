#ifndef SINGLETONWO_H
#define SINGLETONWO_H
#include "mainwindow.h"
#include "CClient.h"
#include "windowsingin.h"
#include "windowlogin.h"
#include "windowadunare.h"
#include <QElapsedTimer>

class Singleton
{
private:
    static Singleton *instanta;
    Singleton(){timer.start();};
    ~Singleton(){};

friend class CClient;

public:
    static Singleton& getInstance();
    static void destroyInstance();

private:
    MainWindow mw;
    WindowSingIn sw;
    WindowLogIn lw;
    windowAdunare aw;

public:
    bool isAWvisible(){return aw.isV();};
    void showMW(){mw.show();};
    void hideMW(){mw.hide();};
    void showSW(){sw.show();};
    void showLW(){lw.show();};
    void showAW(){aw.setTexts(cl.resurse); aw.show();};
    bool hasSpaces(QString s);
    void setTexts(CResurse res){aw.setTexts(res);};
    void addandset(){cl.resurse.addGalbeni(cl.resurse.getWorkers());aw.setTexts(cl.resurse);};
    CClient cl;
    QElapsedTimer timer;

};

#endif // SINGLETONWO_H
