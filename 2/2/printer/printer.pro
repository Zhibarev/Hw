TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib

SOURCES += main.cpp \
    fileprinter.cpp

HEADERS += \
    printer.h \
    fileprinter.h \
    consoleprinter.h \
    printertest.h

DISTFILES += \
    test.txt
