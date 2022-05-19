#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "CMedic.h"
#include "CSoldat.h"
#include "CMuncitor.h"
#include "CCavalerie.h"
#include <QString>

class CResurse
{
private:

    int aMili=0;
    int aMedic=0;
	int galbeni;

	CMuncitor worker;
	CSoldat sold;
	CCavalerie cav;
	CMedic med;


public:
	CResurse();

    int getWorkers(){return worker.getNumber();};
	int getGalbeni() { return galbeni; }
	void addGalbeni(const int& number) { galbeni += number; }
	void subGalbeni(const int& number) { galbeni -= number; }
	void addMuncitor();
    void subLose();




    void initResurse(QStringList& l); //initializeaza resurse din informatii de la server, e o functie apelata pe informatii de la server
    QString getResourcesString(); //creaza un string cu dataele pentru a fi trimise la server (7 + date in ordine), 7 de la protocol

    int getMili(){return aMili;};
    int getMedic(){return aMedic;};
    void setMili(int n){aMili=n;};
    void setMedic(int n){aMedic=n;};

    CMuncitor& getWorker(){return worker;};
    CSoldat &getSold(){return sold;};
    CCavalerie &getCav(){return cav;};
    CMedic &getMed(){return med;};
    void setGalbeni(int nr){galbeni=nr;};

	~CResurse() {}
};

