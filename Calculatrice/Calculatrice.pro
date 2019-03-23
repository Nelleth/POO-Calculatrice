TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    src/display.cpp \
    src/functions.cpp \
    test/functionstest.cpp \
    src/main.cpp

HEADERS += \
    inc/display.hpp \
    inc/functions.hpp
