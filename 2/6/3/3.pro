TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib

SOURCES += main.cpp

HEADERS += \
    sharedpointer.h \
    pointertest.h \
    sharedpointerexeptions.h
