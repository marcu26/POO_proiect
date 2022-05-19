#include "CResurse.h"
#include <QString>
#include <QStringList>
#include <QtDebug>

CResurse::CResurse()
{
	//citeste de pe server resursele disponibile
}


void CResurse::addMuncitor()
{
	worker.modifyNumber(1);
}

void CResurse::initResurse(QStringList& l)
{
    worker=l.value(1).toInt();
    galbeni=l.value(2).toInt();
    aMili=l.value(3).toInt();
    aMedic=l.value(4).toInt();

    cav=l.value(5).toInt();
    sold=l.value(6).toInt();
    med=l.value(7).toInt();
}

QString CResurse::getResourcesString()
{
    QString str = "7 ";
    str+=QString::number(worker.getNumber())+" "+QString::number(galbeni)+" "+QString::number(aMili)+
            " "+QString::number(aMedic)+" "+QString::number(cav.getNumber())+" "+QString::number(sold.getNumber())+" "+QString::number(med.getNumber());

    return str;
}

void CResurse::subLose()
{

}
