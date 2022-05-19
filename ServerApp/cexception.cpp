#include "cexception.h"
#include <QDebug>
#include "cfactorylog.h"

CException::CException(const QString &m, const int &number)
    :message{m}, error_number{number}
{
    qDebug() << number<<": "<<message;

    CFactoryLog::getLog(ERROR)->writeMessage(message);
}
