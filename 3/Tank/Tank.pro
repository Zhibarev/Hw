#-------------------------------------------------
#
# Project created by QtCreator
#
#-------------------------------------------------

QT       += core gui network
CONFIG   += c++11


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tank
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        gamewindow.cpp \
    Shot/shot.cpp \
    Shot/simpleshot.cpp \
    Tank/tank.cpp \
    Tank/simpletank.cpp \
    Landscape/landscape.cpp \
    Game/game.cpp \
    Shot/explosion.cpp \
    Shot/heavyshot.cpp \
    Game/localgame.cpp \
    LocalNet/client.cpp \
    LocalNet/server.cpp

HEADERS  += gamewindow.h \
    Shot/shot.h \
    Shot/simpleshot.h \
    Tank/tank.h \
    Tank/simpletank.h \
    Landscape/landscape.h \
    Game/game.h \
    Shot/explosion.h \
    Shot/heavyshot.h \
    Game/localgame.h \
    LocalNet/client.h \
    LocalNet/server.h

FORMS    += gamewindow.ui
