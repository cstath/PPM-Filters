#-------------------------------------------------
#
# Project created by QtCreator 2016-08-08T14:34:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = filterQt
TEMPLATE = app


SOURCES += main.cpp\
        ../filter/Array.cpp \
        ../filter/BlurFilter.cpp \
        ../filter/DiffFilter.cpp \
        ../filter/Filter.cpp \
        ../filter/GrayFilter.cpp \
        ../filter/MedianFilter.cpp \
        ../filter/ColorFilter.cpp \
        ../filter/Image.cpp \
        mainwindow.cpp \
    colorfilterdialog.cpp

HEADERS  +=\
        ../filter/Array.h \
        ../filter/BlurFilter.h \
        ../filter/DiffFilter.h \
        ../filter/Filter.h \
        ../filter/GrayFilter.h \
        ../filter/MedianFilter.h \
        ../filter/ColorFilter.h \
        ../filter/Image.h \
        ../filter/Serializable.h \
        ../filter/Vec3.h \
        mainwindow.h \
    colorfilterdialog.h

INCLUDEPATH += "../filter/"

DESTDIR = ../bin/

QMAKE_CXXFLAGS += -std=c++11 -ggdb3 -Wall -Wextra -pedantic -fopenmp

LIBS += -fopenmp

FORMS    += mainwindow.ui \
    colorfilterdialog.ui
