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
    worker.setNumber(l.value(1).toInt());
    galbeni=l.value(2).toInt();
    qDebug()<<galbeni;
    aMili=l.value(3).toInt();
    aMedic=l.value(4).toInt();
    cav.setNumber(l.value(5).toInt());
    sold.setNumber(l.value(6).toInt());
    med.setNumber(l.value(7).toInt());
}

QString CResurse::getResourcesString()
{
    QString str = "7 ";
    str+=QString::number(worker.getNumber())+" "+QString::number(galbeni)+" "+QString::number(aMili)+
            " "+QString::number(aMedic)+" "+QString::number(cav.getNumber())+" "+QString::number(sold.getNumber())+" "+QString::number(med.getNumber());

    return str;
}
