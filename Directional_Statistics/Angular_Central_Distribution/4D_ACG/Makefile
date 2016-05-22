CXX = g++
CXXFLAGS = -O2 -I ../Eigen3 -std=c++11 -Wno-deprecated-declarations

SRCS = $(wildcard *.cpp)  
EXES = $(patsubst %cpp, %exe, $(SRCS))  

all : 4D_ACG.exe

4D_ACG.exe : Random.o 4D_ACG.o
	${CXX} $^ -lgsl -o $@

Random.o : Random.cpp Random.h
	${CXX} ${CXXFLAGS} -c $< -o $@

4D_ACG.o : 4D_ACG.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

clean :
	rm -rf *.png
	rm -rf *.exe
	rm -rf *.txt
	rm -rf *.o
