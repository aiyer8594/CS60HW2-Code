TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp \
    rectangle.cpp \
    point.cpp \
    NamedSquare.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    rectangle.h \
    point.h \
    NamedSquare.h
