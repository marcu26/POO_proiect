#include "CResurse.h"

CResurse::CResurse()
{
	//citeste de pe server resursele disponibile
}

void CResurse::addAutorizatie(const std::string& autor)
{
	int exist = 0;
	for (auto& it : autorizatii)
		if (it == autor)
			exist = 1;
	if (exist == 0)
		autorizatii.push_back(autor);
}

void CResurse::addMuncitor()
{
	worker.modifyNumber(1);
}
