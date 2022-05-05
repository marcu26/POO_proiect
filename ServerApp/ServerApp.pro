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
        cdatabase.cpp \
        cexception.cpp \
        clegatura.cpp \
        clog.cpp \
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
    cdatabase.h \
    cexception.h \
    clegatura.h \
    clog.h \
    cserver.h \
    iexception.h
