#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "CMedic.h"
#include "CSoldat.h"
#include "CMuncitor.h"
#include "CCavalerie.h"

class CResurse
{
private:
	std::vector<std::string> autorizatii;
	int galbeni;

	CMuncitor worker;
	CSoldat sold;
	CCavalerie cav;
	CMedic med;

	friend class CScoalaMilitar;
	friend class CScoalaMedici;
public:
	CResurse();

	int getGalbeni() { return galbeni; }
	std::vector<std::string> getAutorizatii() { return autorizatii; }
	void addGalbeni(const int& number) { galbeni += number; }
	void subGalbeni(const int& number) { galbeni -= number; }
	void addAutorizatie(const std::string& autor);
	void addMuncitor();
	
	~CResurse() {}
};

