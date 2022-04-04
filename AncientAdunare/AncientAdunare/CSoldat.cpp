#include "CSoldat.h"

void CSoldat::doAction(ICaracter* caracter)
{
	caracter->modifyNumber(-this->getNumber());
}
