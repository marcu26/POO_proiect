#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include "connectw.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onReadyRead();

private slots:
    void on_connectButton_clicked();

    void on_pushButton_clicked();

    void on_LogInB_clicked();

    void on_SingInB_clicked();

private:
    Ui::MainWindow *ui;
    ConnectW *cw;
    QTcpSocket socket;
};
#endif // MAINWINDOW_H
