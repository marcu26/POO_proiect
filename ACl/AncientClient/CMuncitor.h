#pragma once
#include "ACaracter.h"
class CMuncitor:public ACaracter
{
public:
	CMuncitor() {}
	CMuncitor(int number) :ACaracter(number) {};
    void doAction(ICaracter* caracter) override{caracter->modifyNumber(0);};
};

