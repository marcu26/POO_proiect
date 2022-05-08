#include "CCavalerie.h"

void CCavalerie::doAction(ICaracter* caracter)
{
    caracter->modifyNumber(2*(-this->getNumber()));
}
