#include "CScoalaMilitar.h"

void CScoalaMilitar::instruiesteSoldat(CResurse& res)
{
	res.sold.modifyNumber(1);
}

void CScoalaMilitar::instruiesteCavaler(CResurse& res)
{
	res.cav.modifyNumber(1);
}
