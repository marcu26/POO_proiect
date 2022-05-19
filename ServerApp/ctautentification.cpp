#include "ctautentification.h"
#include "CClientList.h"
#include "cdatabase.h"
#include "clegatura.h"

CTAutentification::CTAutentification()
{

}

void CTAutentification::resolveTask(qintptr socketDescriptor)
{
    CClientList &list = CClientList::getInstance();
    IClient *client = list[socketDescriptor];

    CDataBase &database = CDataBase::getInstance();

    database.connectDataBase();
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    qDebug() <<l.value(1)<<" --- "<<l.value(2)<<"\n";

    if(database.verifyCredentials(l.value(1), l.value(2))==true && CLegatura::verfyConection(l.value(1))==0)
       {
        clientl.value(1);
        CLog::getInstance().PlayerLogIn("S-a autentificat utilizatorul: "+this->username);
        socket->flush();
        socket->write("1 1");                   //REUSIT
        transmitResource();
        inArena = 0;
        }
    else
    {
        CLog::getInstance().PlayerLogIn("Un utilizator a incercat sa se autentifice, dar nu credentialele nu au fost corecte");
        socket->flush();
        socket->write("1 0");                   //ESUAT
    }
}
