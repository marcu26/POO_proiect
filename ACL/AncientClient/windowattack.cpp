#include "windowattack.h"
#include "ui_windowattack.h"
#include "Singleton.h"

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

void windowAttack::changeStyleSheet()
{
    QString func;
    func=".QWidget{background-image:url("+Singleton::getInstance().path+"/Media/poza3.png); background-position: center; }";
    this->ui->widget->setStyleSheet(func);
}
