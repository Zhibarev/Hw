TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib

SOURCES += main.cpp \
    tree.cpp \
    treenode.cpp

HEADERS += \
    treenode.h \
    tree.h \
    treetest.h
