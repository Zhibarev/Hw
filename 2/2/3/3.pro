TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib

SOURCES += main.cpp \
    listcomparator.cpp \
    linkedlist.cpp \
    sortedset.cpp

HEADERS += \
    listcomparator.h \
    linkedlist.h \
    list.h \
    sortedset.h \
    sortedsettest.h
