CXX = g++
CXXFLAGS = -O0 -std=c++11 -lgsl

SRCS = $(wildcard *.cpp)  
EXES = $(patsubst %cpp, %exe, $(SRCS))  

inline.exe : inline.cpp inline.h
	${CXX} ${CXXFLAGS} $< -o $@

clean :
	rm -rf *.exe
