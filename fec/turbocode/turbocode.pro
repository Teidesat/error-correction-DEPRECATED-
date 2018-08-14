TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    rscencoder.cpp \
    rscdecoder.cpp \
    block.cpp \
    utils.cpp

HEADERS += \
    rscencoder.h \
    rscdecoder.h \
    block.h \
    utils.h
