TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    fileprinter.cpp

HEADERS += \
    printer.h \
    fileprinter.h \
    consoleprinter.h

DISTFILES += \
    test.txt
