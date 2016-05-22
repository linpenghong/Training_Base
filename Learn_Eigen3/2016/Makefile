CXX = g++
CXXFLAGS = -O2 -I ./Eigen3 -std=c++11 -Wno-deprecated-declarations

SRCS = $(wildcard *.cpp)  
EXES = $(patsubst %cpp, %exe, $(SRCS))  

all : ${EXES}

%.exe : %.cpp
	${CXX} ${CXXFLAGS} $< -o $@

clean :
	rm -rf *.exe
