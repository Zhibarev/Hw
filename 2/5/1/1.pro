TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib

SOURCES += main.cpp \
    operator.cpp \
    operand.cpp \
    tree.cpp

HEADERS += \
    treenode.h \
    operator.h \
    operand.h \
    tree.h \
    treetest.h
