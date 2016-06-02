TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib

SOURCES += main.cpp \
    hashtable.cpp \
    hashfaq6.cpp \
    hashrot13.cpp \
    hashsimple.cpp

HEADERS += \
    hashtable.h \
    hashfunction.h \
    hashtest.h \
    hashfaq6.h \
    hashrot13.h \
    hashsimple.h \
    hashfunctiontest.h \
    hashexceptions.h
