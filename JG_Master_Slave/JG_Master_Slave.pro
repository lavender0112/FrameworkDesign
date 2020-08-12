TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mainprocess.cpp \
    i2c.cpp \
    usb.cpp \
    base_rxtx.cpp \
    ringbuffer.cpp

HEADERS += \
    mainprocess.h \
    i2c.h \
    usb.h \
    base_rxtx.h \
    ringbuffer.h \
    base.h
