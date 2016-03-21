TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    linkedstack.cpp \
    arraystack.cpp \
    stackcalculator.cpp

HEADERS += \
    stack.h \
    linkedstack.h \
    arraystack.h \
    stackcalculator.h
