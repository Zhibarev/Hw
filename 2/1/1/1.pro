TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib

SOURCES += main.cpp \
    linkedlist.cpp \
    doublelinkedlist.cpp

HEADERS += \
    linkedlist.h \
    doublelinkedlist.h \
    list.h \
    testlinkedlist.h \
    testdoublelinkedlist.h
