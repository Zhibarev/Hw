#-------------------------------------------------
#
# Project created by QtCreator 2016-06-02T14:53:20
#
#-------------------------------------------------

QT       += core gui network widgets
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        server.cpp

HEADERS  += server.h

FORMS    += server.ui
