#ifndef ITASK_H
#define ITASK_H

#include <QTcpSocket>

class ITask
{
public:
   virtual void resolveTask(qintptr socketDescriptor) = 0;
};

#endif // ITASK_H
