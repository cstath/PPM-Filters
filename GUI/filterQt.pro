SOURCES += \
    filterQt.cpp \
    mainwindow.cpp\
    ../filter/Array.cpp \
    ../filter/BlurFilter.cpp \
    ../filter/DiffFilter.cpp \
    ../filter/Filter.cpp \
    ../filter/GrayFilter.cpp \
    ../filter/Image.cpp

HEADERS += \
    mainwindow.h\
    ../filter/Array.h \
    ../filter/BlurFilter.h \
    ../filter/DiffFilter.h \
    ../filter/Filter.h \
    ../filter/GrayFilter.h \
    ../filter/Image.h \
    ../filter/Serializable.h \
    ../filter/Vec3.h

QMAKE_CXXFLAGS += -std=c++11 -g -ggdb3 -Wall -Wextra -pedantic

INCLUDEPATH += "../filter/"

DESTDIR = ../bin/
