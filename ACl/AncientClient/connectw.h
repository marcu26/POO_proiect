#ifndef CONNECTW_H
#define CONNECTW_H

#include <QDialog>

namespace Ui {
class ConnectW;
}

class ConnectW : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectW(QWidget *parent = nullptr);
    ~ConnectW();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::ConnectW *ui;
};

#endif // CONNECTW_H
