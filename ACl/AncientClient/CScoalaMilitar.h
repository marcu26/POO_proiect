#pragma once
#include "ACladire.h"
#include "CResurse.h"

class CScoalaMilitar :public ACladire
{
public:
	CScoalaMilitar() :ACladire("ScoalaMilitari") {}

	void instruiesteSoldat(CResurse& res);
	void instruiesteCavaler(CResurse& res);
};

