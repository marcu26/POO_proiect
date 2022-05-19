#ifndef WINDOWATTACK_H
#define WINDOWATTACK_H

#include <QDialog>
#include <QSoundEffect>

namespace Ui {
class windowAttack;
}

class windowAttack : public QDialog
{
    Q_OBJECT

private:
    QSoundEffect effect;
    QSoundEffect effect1;
    QSoundEffect effect2;
    QTimer *timer;
    QTimer *timer2;
    int trupa=0;
    int canPause=1;
    int isMyTurn=0;
    int soldD,medD,cavD;
    int soldC,medC,cavC;
    QString act;

public:
    explicit windowAttack(QWidget *parent = nullptr);
    ~windowAttack();
    void changeStyleSheet();
    void setTexts();
    void setTextDusman(QString s);
    void punePauza();
    void endPause2();
    void makePauseAvalabile();
    void endPause();
    void setTurn(int t){this->isMyTurn=t;};
    void setTuraBox(QString s);
    void setMyText(QString txt);
    void setPlayer();





private slots:
    void on_Exit_clicked();

    void on_Nu_clicked();

    void on_Da_clicked();

    void on_useSold_clicked();

    void on_useCav_clicked();

    void on_useMed_clicked();

    void on_Pause_clicked();

    void on_close_clicked();

    void on_Cancel_clicked();

    void on_SoldA_clicked();

    void on_CavA_clicked();

    void on_MedA_clicked();

private:
    Ui::windowAttack *ui;
};

#endif // WINDOWATTACK_H
