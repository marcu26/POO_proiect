#include "cexception.h"
#include <QDebug>
#include "clog.h"

CException::CException(const QString &m, const int &number)
    :message{m}, error_number{number}
{
    qDebug() << number<<": "<<message;

    CLog::getInstance().writeErrors(message);
}
