CXX = g++
CXXFLAGS = -O2 -I ./Eigen3 -std=c++11 -Wno-deprecated-declarations

SRCS = $(wildcard *.cpp)  
EXES = $(patsubst %cpp, %exe, $(SRCS))  

all : Polar_Chart.png ACG.exe

Polar_Chart.png : Polar_Chart.py
	python $^

ACG.exe : Random.o ACG.o
	${CXX} $^ -lgsl -o $@

Random.o : Random.cpp Random.h
	${CXX} ${CXXFLAGS} -c $< -o $@

ACG.o : ACG.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

clean :
	rm -rf *.png
	rm -rf *.exe
	rm -rf *.o
