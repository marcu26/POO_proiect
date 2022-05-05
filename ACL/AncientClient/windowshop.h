#ifndef WINDOWSHOP_H
#define WINDOWSHOP_H

#include <QDialog>

namespace Ui {
class windowShop;
}

class windowShop : public QDialog
{
    Q_OBJECT

public:
    explicit windowShop(QWidget *parent = nullptr);
    ~windowShop();

private slots:
    void on_Close_clicked();

    void on_Provoaca_2_clicked();

    void on_AutoMili_clicked();

    void on_Muncitori_clicked();

private:
    Ui::windowShop *ui;
};

#endif // WINDOWSHOP_H
