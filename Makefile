# ########################   Makefile.1   ############################
# $@ target, $< first dependency, $^ all dependencies, 
# $* "stem" of target filename e.g. %.f: %.F will five foo for foo.f
CC = g++

OBJS   = imageaverage.o Array.o UnitTests.o
CFLAGS = -std=c++11 -g -O2 -ggdb3 -Wall -Wextra -pedantic
#LIBS   = -lunittest++
LIBS   = -lgtest -lgtest_main

all: imageaverage imageaverage_test

# basic executable targets
imageaverage: $(OBJS)
	$(CC) $(CFLAGS) imageaverage.o Array.o -o imageaverage

imageaverage.o: imageaverage.cpp Image.h Array.h Vec3.h
	$(CC) $(CFLAGS) -c imageaverage.cpp

Array.o: Array.cpp Array.h Vec3.h Serializable.h
	$(CC) $(CFLAGS) -c Array.cpp

# Unit tests targets
imageaverage_test: imageaverage_test.o Array.o UnitTests.o
	$(CC) $(CFLAGS) imageaverage_test.o Array.o UnitTests.o -o imageaverage_test $(LIBS)

imageaverage_test.o: imageaverage_test.cpp UnitTests.cpp Image.h Array.h Vec3.h
	$(CC) $(CFLAGS) -c imageaverage_test.cpp $(LIBS)

UnitTests.o: UnitTests.cpp Array.h Image.h Vec3.h
	$(CC) $(CFLAGS) -c UnitTests.cpp $(LIBS)

# $(CC) $(CFLAGS) $^   -o $@ $(LIBS)

clean:
	/bin/rm -f *.o imageaverage imageaverage_test
