#ifndef WINDOWSINGIN_H
#define WINDOWSINGIN_H

#include <QDialog>

namespace Ui {
class WindowSingIn;
}

class WindowSingIn : public QDialog
{
    Q_OBJECT

public:
    explicit WindowSingIn(QWidget *parent = nullptr);
    ~WindowSingIn();

private slots:
    void on_BackB_clicked();

    void on_finnishB_clicked();

private:
    Ui::WindowSingIn *ui;
public:
    void allIsGood();
    void allIsWrong();
    void changeStyleSheet();
};

#endif // WINDOWSINGIN_H
