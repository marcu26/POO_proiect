
#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QString>


class Client:public QObject
{
public:
    Client(QString ip,int port);
    ~Client();

public slots:
    void onReadyRead();

private slots:
    void on_pushButton_clicked();

private:
    QTcpSocket socket;
};
