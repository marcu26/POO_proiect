#pragma once
#include "ACaracter.h"
class CSoldat : public ACaracter
{
public:
	CSoldat() {};
	CSoldat(int number) : ACaracter(number) {};
	void doAction(ICaracter* caracter);
};

