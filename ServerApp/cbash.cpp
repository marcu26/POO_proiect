#include "cbash.h"
#include <QString>
#include "cdatabase.h"

CBash::CBash()
{

}

int CBash::parseRequest(QByteArray data)
{
    QString req = QString(data);

    if(req[0] == '1')
    {

    }

}
