CXX = g++
CXXFLAGS = -O2 -std=c++11 -isystem ./include

SRCS = $(wildcard *.cpp)  
EXES = $(patsubst %cpp, %exe, $(SRCS))  

all : ${EXES}

%.exe : %.cpp libgtest.a
	${CXX} ${CXXFLAGS} $< libgtest.a -o $@

libgtest.a:
	g++ -isystem ./include -c ./src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o

clean :
	rm -rf *.exe *.a
