# ########################   Makefile.1   ############################
# $@ target, $< first dependency, $^ all dependencies, 
# $* "stem" of target filename e.g. %.f: %.F will five foo for foo.f
CC = g++

OBJS   = filter.o Array.o UnitTests.o
CFLAGS = -std=c++11 -g -O2 -ggdb3 -Wall -Wextra -pedantic
#LIBS   = -lunittest++
LIBS   = -lgtest -lgtest_main

all: filter filter_test

# basic executable targets
filter: $(OBJS)
	$(CC) $(CFLAGS) filter.o Array.o -o filter

filter.o: filter.cpp Image.h Array.h Vec3.h Filter.h GrayFilter.h BlurFilter.h DiffFilter.h
	$(CC) $(CFLAGS) -c filter.cpp

Array.o: Array.cpp Array.h Vec3.h Serializable.h
	$(CC) $(CFLAGS) -c Array.cpp

# Unit tests targets
filter_test: filter_test.o Array.o UnitTests.o
	$(CC) $(CFLAGS) filter_test.o Array.o UnitTests.o -o filter_test $(LIBS)

filter_test.o: filter_test.cpp UnitTests.cpp Image.h Array.h Vec3.h Filter.h
	$(CC) $(CFLAGS) -c filter_test.cpp $(LIBS)

UnitTests.o: UnitTests.cpp Array.h Image.h Vec3.h
	$(CC) $(CFLAGS) -c UnitTests.cpp $(LIBS)

# $(CC) $(CFLAGS) $^   -o $@ $(LIBS)

clean:
	/bin/rm -f *.o filter filter_test
