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

	friend class CScoalaMilitar;
	friend class CScoalaMedici;
    friend class windowAdunare;
public:
	CResurse();

    int getWorkers(){return worker.getNumber();};
	int getGalbeni() { return galbeni; }
	void addGalbeni(const int& number) { galbeni += number; }
	void subGalbeni(const int& number) { galbeni -= number; }
	void addMuncitor();
    void initResurse(QStringList& l);
    QString getResourcesString();
	
	~CResurse() {}
};

