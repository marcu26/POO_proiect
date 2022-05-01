#ifndef WINDOWADUNARE_H
#define WINDOWADUNARE_H
#include "CResurse.h"

#include <QDialog>

namespace Ui {
class windowAdunare;
}

class windowAdunare : public QDialog
{
    Q_OBJECT

public:
    explicit windowAdunare(QWidget *parent = nullptr);
    ~windowAdunare();
    void setTexts(CResurse res);
    static void addAndSet();

private slots:
    void on_LogInB_clicked();

private:
    Ui::windowAdunare *ui;
public:
    bool isV();
};

#endif // WINDOWADUNARE_H
