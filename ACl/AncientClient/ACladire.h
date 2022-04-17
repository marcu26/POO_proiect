#pragma once
#include "ICladire.h"

class ACladire :public ICladire
{
protected:
	std::string nume;
public:
	ACladire(std::string n) :nume(n) {}

	virtual std::string getType() override { return nume; }
};

