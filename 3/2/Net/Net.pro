TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += testlib

SOURCES += main.cpp \
    Computer/computer.cpp \
    Net/localnet.cpp

HEADERS += \
    Computer/computer.h \
    Computer/os.h \
    Computer/linux.h \
    Computer/windows.h \
    Computer/weakos.h \
    Net/localnet.h \
    Test/computertest.h \
    Test/nettest.h \
