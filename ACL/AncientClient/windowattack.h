#ifndef WINDOWATTACK_H
#define WINDOWATTACK_H

#include <QDialog>

namespace Ui {
class windowAttack;
}

class windowAttack : public QDialog
{
    Q_OBJECT

public:
    explicit windowAttack(QWidget *parent = nullptr);
    ~windowAttack();
    void changeStyleSheet();

private:
    Ui::windowAttack *ui;
};

#endif // WINDOWATTACK_H