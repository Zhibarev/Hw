#-------------------------------------------------
#
# Project created by QtCreator 2016-06-01T15:55:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3
TEMPLATE = app
CONFIG += c++11
QT += testlib

SOURCES += main.cpp\
        mainwindow.cpp \
    rules.cpp

HEADERS  += mainwindow.h \
    rules.h \
    rulestest.h

FORMS    += mainwindow.ui
