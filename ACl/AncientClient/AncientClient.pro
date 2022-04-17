QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ACaracter.cpp \
    ACladire.cpp \
    CCavalerie.cpp \
    CClient.cpp \
    CException.cpp \
    CMedic.cpp \
    CMuncitor.cpp \
    CResurse.cpp \
    CScoalaMedici.cpp \
    CScoalaMilitar.cpp \
    CShop.cpp \
    CSoldat.cpp \
    ICaracter.cpp \
    ICladire.cpp \
    IException.cpp \
    client.cpp \
    connectw.cpp \
    main.cpp \
    mainwindow.cpp \
    singinwindow.cpp \
    singletonwo.cpp

HEADERS += \
    ACaracter.h \
    ACladire.h \
    CCavalerie.h \
    CClient.h \
    CException.h \
    CMedic.h \
    CMuncitor.h \
    CResurse.h \
    CScoalaMedici.h \
    CScoalaMilitar.h \
    CShop.h \
    CSoldat.h \
    ICaracter.h \
    ICladire.h \
    IException.h \
    client.h \
    connectw.h \
    mainwindow.h \
    singinwindow.h \
    singletonwo.h

FORMS += \
    connectw.ui \
    mainwindow.ui \
    singinwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    AncientClient.pro.user
