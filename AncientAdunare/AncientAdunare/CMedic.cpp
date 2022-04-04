#include "CMedic.h"

void CMedic::doAction(ICaracter* caracter)
{
	caracter->modifyNumber(this->getNumber());
}
