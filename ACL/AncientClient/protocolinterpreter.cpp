#include "protocolinterpreter.h"
#include "Singleton.h"

ProtocolInterpreter::ProtocolInterpreter()
{

}

void ProtocolInterpreter::callFunction(QString answ)
{
    if(answ=="2 0")
    {
        Singleton::getInstance().g.getSW().allIsWrong();
    }

    if(answ=="2 1")
    {
        Singleton::getInstance().g.getSW().allIsGood();
    }

    if(answ=="1 0")
    {
        Singleton::getInstance().g.getLW().allIsWrong();
    }

    if(answ=="1 1")
    {
        Singleton::getInstance().g.getLW().allIsGood();
    }

    if(answ[0]=='6')
    {
        QStringList l = answ.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

        Singleton::getInstance().getCl().getResurse().initResurse(l);

        Singleton::getInstance().showAW();
    }

    if(answ[0]=='4')
    {
        Singleton::getInstance().g.getAW().setPlayers(answ);
    }

    if(answ[0]=='5' and answ[2]!='0')
    {
        Singleton::getInstance().g.getAW().maProvoci(answ);
    }

    if(answ[0]=='9' && answ[2]=='0')
    {
        Singleton::getInstance().g.getAW().aRefuzat();
    }

    if(answ[0]=='9' && answ[2]=='1')
      {
          Singleton::getInstance().getCl().sendInfoToServer("a "+Singleton::getInstance().getDusman());
          Singleton::getInstance().showATW();
          Singleton::getInstance().hideAW();
          Singleton::getInstance().g.getATW().setTurn(1);
          Singleton::getInstance().g.getATW().setTuraBox("background-color:rgb(0,85,0)");
      }

    if(answ[0]=='a')
    {
        Singleton::getInstance().g.getATW().setTextDusman(answ); //setez datele despre dusman
    }

    if(answ[0]=='8')  //io am gata pauza
    {
        Singleton::getInstance().g.getATW().punePauza();
    }

    if(answ[0]=='e') // ala o gatat pauza
    {
        Singleton::getInstance().g.getATW().endPause2();
    }

    if(answ[0]=='d') //Am Atacat
    {
        Singleton::getInstance().g.getATW().setTextDusman(answ);
    }

    if(answ[0]=='c') //amFostAtacat
    {
        Singleton::getInstance().g.getATW().setMyText(answ);
        Singleton::getInstance().g.getATW().setTurn(1);
        Singleton::getInstance().g.getATW().setTuraBox("background-color:rgb(0,85,0)");
    }

    if(answ[0]=='f') // o folosit ala medicii
    {
        Singleton::getInstance().g.getATW().setTextDusman(answ);
        Singleton::getInstance().g.getATW().setTurn(1);
        Singleton::getInstance().g.getATW().setTuraBox("background-color:rgb(0,85,0)");
    }

    if(answ[0]=='g') //folosesc medicii
    {
         Singleton::getInstance().g.getATW().setMyText(answ);
    }

    if(answ[0]=='w')
    {
        Singleton::getInstance().g.getATW().hide();
        Singleton::getInstance().getCl().getResurse().addGalbeni(1000);
        Singleton::getInstance().g.getAW().setShowText("Felicitari, ati castigat duleul!");
        Singleton::getInstance().g.getAW().show();
        Singleton::getInstance().getCl().sendInfoToServer(Singleton::getInstance().getCl().getResurse().getResourcesString());
         Singleton::getInstance().getCl().clearSocket();
        Singleton::getInstance().getCl().sendInfoToServer("s");
    }

    if(answ[0]=='l')
    {
        Singleton::getInstance().g.getATW().hide();
        Singleton::getInstance().g.getAW().setShowText("Ati pierdut, mult succes data viitoare!");
        Singleton::getInstance().g.getAW().show();
        Singleton::getInstance().getCl().clearSocket();
        Singleton::getInstance().getCl().sendInfoToServer("s");
    }



    if (answ[0]=='s')
    {
        qDebug()<<answ;

        QStringList l = answ.split(QRegularExpression("\\W+"), Qt::SkipEmptyParts);

        Singleton::getInstance().setWins(l[1].toInt());
        Singleton::getInstance().setLoses(l[2].toInt());
        Singleton::getInstance().g.getAW().updateWL();
    }

}
