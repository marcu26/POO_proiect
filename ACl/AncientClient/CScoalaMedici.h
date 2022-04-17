#pragma once
#include "ACladire.h"
#include "CResurse.h"

class CScoalaMedici : public ACladire
{
public:
	CScoalaMedici(std::string nume) :ACladire(nume) {}

	void instruiesteMedici(CResurse& res);
};

