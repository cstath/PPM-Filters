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
        ../filter/Image.cpp \
        mainwindow.cpp

HEADERS  += mainwindow.h\
        ../filter/Array.h \
        ../filter/BlurFilter.h \
        ../filter/DiffFilter.h \
        ../filter/Filter.h \
        ../filter/GrayFilter.h \
        ../filter/Image.h \
        ../filter/Serializable.h \
        ../filter/Vec3.h \

INCLUDEPATH += "../filter/"

DESTDIR = ../bin/

QMAKE_CXXFLAGS += -std=c++11 -ggdb3 -Wall -Wextra -pedantic

FORMS    += mainwindow.ui
