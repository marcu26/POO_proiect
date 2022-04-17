#include "cclientthread.h"

CClientThread::CClientThread(qintptr ID, QObject *parent)
    :QThread(parent)
{
    this->socketDescriptor = ID;            //socketDescriptor = portul la care este conectat clientul
}

void CClientThread::run()
{
    //aici incepe threadul
    qDebug() <<"Thread Start\n";
    socket = new QTcpSocket();

    database.connectDataBase(QString::number(socketDescriptor));

    if(!this->socket->setSocketDescriptor(this->socketDescriptor))          //setez descriptorul socketului
    {
        qDebug () <<"Eroare la stabilirea conexiunii dintre server si client\n";
        return;
    }
    connect(socket, SIGNAL(readyRead()),this,SLOT(onReadyRead()), Qt::DirectConnection);
     connect(socket, SIGNAL(disconnected()),this,SLOT(onDisconnected()),Qt::DirectConnection);

    qDebug() <<"Client: "<<this->socketDescriptor<<"\n";

    exec();                                                             //se executa threadul pana la exit();
}

void CClientThread::onReadyRead()
{
    QByteArray data = socket->readAll();

    QString req(data);

    qDebug() <<socketDescriptor<<": "<<req<<"\n";

    database.connectDataBase(QString::number(socketDescriptor));        //va trebui mutata de aici aceasta instructiune deoarece unele requesturi nu vor avea nevoie de baza de date (posibil)
    if(req[0]=='1')
        autentification(req);
    else if(req[0]=='2')
        registerUser(req);
}

void CClientThread::felicita()
{
    socket->write("\n\n\n\n\n\n\n\nFelicitari!!!!!!!!!!!!!!!!!!");
}

void CClientThread::autentification(QString &req)
{
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    qDebug() <<l.value(1)<<" --- "<<l.value(2)<<"\n";
    if(database.verifyCredentials(l.value(1), l.value(2))==true)
        socket->write("Autentificare Reusita!");
    else
        socket->write("Autentificare ESUATA!");
}

void CClientThread::registerUser(QString &req)
{
    QStringList l = req.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);
    qDebug() <<l.value(1)<<" --- "<<l.value(2)<<"\n";

    if(database.addUser(l.value(1),l.value(2))==-1)
    {
        socket->write("Acest nume de utilizator este deja existent!");
        qDebug () <<"Username Luat\n";
    }
    else
        socket->write("Inregistrare efectuata cu succes!");
}

void CClientThread::onDisconnected()
{
    qDebug() <<"S-a deconectat: "<<this->socketDescriptor<<"\n";
    socket->deleteLater();
    exit(0);
}
