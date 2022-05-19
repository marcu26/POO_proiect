#ifndef CTAUTENTIFICATION_H
#define CTAUTENTIFICATION_H

#include "itask.h"

class CTAutentification : public ITask
{
public:
    CTAutentification();

    virtual void resolveTask(qintptr socketDescriptor) override;
};

#endif // CTAUTENTIFICATION_H
