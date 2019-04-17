#
# Makefile
#

CXX = g++ -c
LD = g++
FLAGS = -std=c++11 -lpthread

%.o: %.cc
		$(CXX) -o $*.o $< $(FLAGS)

all: MinGetterTest

MinGetterTest: mingetter_test.o \
		MinGetter1.o \
		MinGetter2.o \
		MinGetter3.o \
		MinGetterBase.o \
		/usr/local/lib/libgtest.a
		$(LD) -o MinGetterTest $^ $(FLAGS)

clean:
		find . -name "*.o" -exec rm '{}' \;
		rm MinGetterTest
