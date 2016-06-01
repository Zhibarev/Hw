TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib

SOURCES += main.cpp

HEADERS += \
    AVLTree.h \
    treeexeptions.h \
    bag.h \
    bagtest.h
