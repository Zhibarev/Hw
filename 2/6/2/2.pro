TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib

SOURCES += main.cpp \
    linkedlist.cpp \
    uniquelist.cpp

HEADERS += \
    list.h \
    linkedlist.h \
    testuniquielist.h \
    uniquelist.h \
    uniquieexeptions.h
