SOURCES += \
    filterQt.cpp \
    mainwindow.cpp\
    Array.cpp

HEADERS += \
    mainwindow.h\
    Array.h\
    Serializable.h\
    Image.h\
    Vec3.h\
    Filter.h\
    GrayFilter.h\
    BlurFilter.h\
    DiffFilter.h

QMAKE_CXXFLAGS += -std=c++11 -g -O2 -ggdb3 -Wall -Wextra -pedantic
