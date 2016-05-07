#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T23:00:35
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    stackcalculator.cpp

HEADERS  += mainwindow.h \
    linkedstack.h \
    stack.h \
    stackcalculator.h

FORMS    += mainwindow.ui
