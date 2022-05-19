#ifndef SINGLETONWO_H
#define SINGLETONWO_H
#include "CClient.h"
#include <QApplication>
#include "gresources.h"


class Singleton
{
private:
    static Singleton *instanta;
    Singleton();
    ~Singleton(){};



public:
    static Singleton& getInstance();
    static void destroyInstance();

private:
    CClient cl;
    QString path;
    QString dusman;
    int w,l;

public:
    GResources g;

        //functie care verifica daca suntem in modul adunare pentru incrementarea banilor

    bool isAWvisible(){return g.getAW().isV();};

        //functii de afisare a ferestrelor

    void showMW(){g.getMW().show();};
    void hideMW(){g.getMW().hide();};
    void showSW(){g.getSW().show();};
    void showLW(){g.getLW().show();};
    void showAW(){g.getAW().setTexts(cl.getResurse()); g.getAW().show();g.getAW().showBuildings();g.getAW().setPlayer();cl.sendInfoToServer("s");cl.clearSocket();};
    void showATW(){g.getATW().show();g.getATW().setTexts();g.getATW().setPlayer();};
    void showSHW(){g.getSHW().show();};
    void hideAW(){g.getAW().hide();};

    //functie care verifica daca un string are spatii pentru parole si conturi

    bool hasSpaces(QString s);

    //schimba textul in modul adunare

    void setTexts(CResurse res){g.getAW().setTexts(res);};

    //adauga galbeni si schimba textu in modul adunare
    void addandset(){cl.getResurse().addGalbeni(cl.getResurse().getWorkers());g.getAW().setTexts(cl.getResurse());};


    CClient &getCl(){return cl;};
    void setPath(QString path){this->path=path;};
    QString getPath(){return path;};
    void connectToServer();

    //seteaza stylesheet pentru windowuri
    void setBG();

    //ia dusmanul pe care il provoci sau care te provoaca
    void setDusman(QString dus){dusman=dus;};
    QString getDusman(){return dusman;};

    //seteaza username-ul clientului
    void setUname(QString s){this->cl.setUName(s);};

    //wins and loses

    void setLoses(int l){this->l=l;};
    void setWins(int w){this->w=w;};
    int getLoses(){return l;};
    int getWins(){return w;};

    //

};

#endif // SINGLETONWO_H
