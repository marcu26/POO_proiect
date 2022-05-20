#include "cfactoryprot.h"
#include "csingleprot.h"
#include "cmultiprot.h"

IProtocol *CFactoryProt::getProt(ProtType type)
{
    if(type == Single)
        return new CSingleProt();
    else if (type == Interaction)
        return new CMultiProt();
}
