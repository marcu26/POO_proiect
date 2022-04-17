#pragma once
#include "ACaracter.h"
class CCavalerie : public ACaracter
{
public:
	CCavalerie() {};
	CCavalerie(int number) : ACaracter(number) {};
	void doAction(ICaracter* caracter);
};

