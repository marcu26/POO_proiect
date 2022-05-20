#ifndef CFACTORYPROT_H
#define CFACTORYPROT_H
#include "iprotocol.h"

enum ProtType {Single, Interaction};

class CFactoryProt
{
public:
   static IProtocol *getProt(ProtType type);
};

#endif // CFACTORYPROT_H
