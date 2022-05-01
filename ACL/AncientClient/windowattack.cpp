#include "windowattack.h"
#include "ui_windowattack.h"

windowAttack::windowAttack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowAttack)
{
    ui->setupUi(this);
}

windowAttack::~windowAttack()
{
    delete ui;
}
