QT       += core gui
QT       += network
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ACaracter.cpp \
    CCavalerie.cpp \
    CClient.cpp \
    CException.cpp \
    CMedic.cpp \
    CMuncitor.cpp \
    CResurse.cpp \
    CSoldat.cpp \
    ICaracter.cpp \
    IException.cpp \
    Singleton.cpp \
    exceptieconectare.cpp \
    gresources.cpp \
    main.cpp \
    mainwindow.cpp \
    protocolinterpreter.cpp \
    windowadunare.cpp \
    windowattack.cpp \
    windowlogin.cpp \
    windowshop.cpp \
    windowsingin.cpp

HEADERS += \
    ACaracter.h \
    CCavalerie.h \
    CClient.h \
    CException.h \
    CMedic.h \
    CMuncitor.h \
    CResurse.h \
    CSoldat.h \
    ICaracter.h \
    IException.h \
    Singleton.h \
    exceptieconectare.h \
    gresources.h \
    mainwindow.h \
    protocolinterpreter.h \
    windowadunare.h \
    windowattack.h \
    windowlogin.h \
    windowshop.h \
    windowsingin.h

FORMS += \
    mainwindow.ui \
    windowadunare.ui \
    windowattack.ui \
    windowlogin.ui \
    windowshop.ui \
    windowsingin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    AncientClient.pro.user \
    Media/poza.png \
    Media/poza1.jpg
