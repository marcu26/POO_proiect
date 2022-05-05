#ifndef SINGLETONWO_H
#define SINGLETONWO_H
#include "mainwindow.h"
#include "CClient.h"
#include "windowsingin.h"
#include "windowlogin.h"
#include "windowadunare.h"
#include "windowattack.h"
#include "windowshop.h"
#include <QApplication>


class Singleton
{
private:
    static Singleton *instanta;
    Singleton();
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
    windowAttack atw;
    windowShop shw;
    QString dusman;


public:
    bool isAWvisible(){return aw.isV();};
    void showMW(){mw.show();};
    void hideMW(){mw.hide();};
    void showSW(){sw.show();};
    void showLW(){lw.show();};
    void showAW(){aw.setTexts(cl.resurse); aw.show();aw.showBuildings();};
    void showATW(){atw.show();}
    void showSHW(){shw.show();};
    bool hasSpaces(QString s);
    void setTexts(CResurse res){aw.setTexts(res);};
    void addandset(){cl.resurse.addGalbeni(cl.resurse.getWorkers());aw.setTexts(cl.resurse);};
    CClient cl;
    QString path;
    void connectToServer();
    void setBG();
    void setDusman(QString dusman){this->dusman=dusman;};
    QString getDusman(){return dusman;};
    void setPath(QString Path);

};

#endif // SINGLETONWO_H
