TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bubblesort.cpp \
    insertsort.cpp \
    selectionsort.cpp \
    quicksort.cpp \
    heapsort.cpp

HEADERS += \
    sort.h \
    bubblesort.h \
    insertsort.h \
    selectionsort.h \
    quicksort.h \
    heapsort.h
