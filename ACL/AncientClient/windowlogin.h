#ifndef WINDOWLOGIN_H
#define WINDOWLOGIN_H

#include <QDialog>

namespace Ui {
class WindowLogIn;
}

class WindowLogIn : public QDialog
{
    Q_OBJECT

public:
    explicit WindowLogIn(QWidget *parent = nullptr);
    ~WindowLogIn();

private slots:
    void on_BackB_clicked();

    void on_finnishB_clicked();

private:
    Ui::WindowLogIn *ui;

public:
    void allIsGood();
    void allIsWrong();
    void changeStyleSheet();
};

#endif // WINDOWLOGIN_H
