QT -= gui
QT += core
QT += network #am adaugat modulul pentru clasele destinate internetului
QT += sql

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        CClient.cpp \
        CClientList.cpp \
        SHA256.cpp \
        absclient.cpp \
        cdatabase.cpp \
        cerrorlog.cpp \
        cexception.cpp \
        cfactoryclient.cpp \
        cfactorylog.cpp \
        clegatura.cpp \
        cloginlog.cpp \
        clogoutlog.cpp \
        cprotocol.cpp \
        cregisterlog.cpp \
        cserver.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CClient.h \
    CClientList.h \
    SHA256.h \
    absclient.h \
    cdatabase.h \
    cerrorlog.h \
    cexception.h \
    cfactoryclient.h \
    cfactorylog.h \
    clegatura.h \
    cloginlog.h \
    clogoutlog.h \
    cprotocol.h \
    cregisterlog.h \
    cserver.h \
    iclient.h \
    iexception.h \
    ilog.h
