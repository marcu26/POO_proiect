#ifndef GRESOURCES_H
#define GRESOURCES_H

#include "mainwindow.h"
#include "windowsingin.h"
#include "windowlogin.h"
#include "windowadunare.h"
#include "windowattack.h"
#include "windowshop.h"


class GResources
{
private:

    MainWindow mw;
    WindowSingIn sw;
    WindowLogIn lw;
    windowAdunare aw;
    windowAttack atw;
    windowShop shw;

public:
    GResources();
    windowAttack &getATW(){return atw;};
    WindowSingIn &getSW(){return sw;};
    WindowLogIn &getLW(){return lw;};
    windowAdunare &getAW(){return aw;};
    windowShop &getSHW(){return shw;};
    MainWindow &getMW(){return mw;};



};

#endif // GRESOURCES_H
