QT       += core gui network
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatclientform.cpp \
    chatserverform.cpp \
    clientmanagerform.cpp \
    logthread.cpp \
    main.cpp \
    client.cpp \
    mainwindow.cpp \
    product.cpp \
    productmanagerform.cpp \
    shop.cpp \
    shopmanagerform.cpp

HEADERS += \
    chatclientform.h \
    chatserverform.h \
    client.h \
    clientmanagerform.h \
    logthread.h \
    mainwindow.h \
    product.h \
    productmanagerform.h \
    shop.h \
    shopmanagerform.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    chatserverform.ui \
    clientmanagerform.ui \
    mainwindow.ui \
    productmanagerform.ui \
    shopmanagerform.ui
