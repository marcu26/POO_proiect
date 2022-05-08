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
    QString dusman="dms";
    CClient cl;
    QString path;


public:

    CClient &getCl(){return cl;};
    QString getPath(){return path;};




    bool isAWvisible(){return aw.isV();}; // verifica daca fereastra de adunare e vizibila pentru a mari banii clientului conectat

    void showMW(){mw.show();};
    void hideMW(){mw.hide();};
    void showSW(){sw.show();};
    void showLW(){lw.show();};
    void showAW(){aw.setTexts(cl.getResurse()); aw.show();aw.showBuildings();};
    void showATW(){atw.setTexts();atw.show();aw.hideThings();} //setTexts = arata resursele tale in windowattack
    void showSHW(){shw.show();};
    void hideAW(){aw.hide();};

    void setBG(); //seteaza stylesheet la ferestre

    void setPath(QString Path);

    bool hasSpaces(QString s); //verifica daca un string are spatii, util la username-uri si parole

    void setTexts(CResurse res){aw.setTexts(res);}; //seteaza resursele clientului din informatiile primite de la server

    void addandset(){cl.getResurse().addGalbeni(cl.getResurse().getWorkers());aw.setTexts(cl.getResurse());}; //aduna galbeni in fct de nr de munc o data la 2 secunde si face update la resurse

    void connectToServer();



    void setDusman(QString dusman){this->dusman=dusman;};
    QString getDusman(){return dusman;};


};

#endif // SINGLETONWO_H
