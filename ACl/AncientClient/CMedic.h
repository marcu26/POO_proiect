#pragma once
#include "ACaracter.h"
class CMedic :
    public ACaracter
{
public:
	CMedic() {};
	CMedic(int number) : ACaracter(number) {};
	void doAction(ICaracter* caracter);

};

