#ifndef CBASH_H
#define CBASH_H

#include <QByteArray>

class CBash
{
public:
    CBash();

    int parseRequest(QByteArray data);
};

#endif // CBASH_H
