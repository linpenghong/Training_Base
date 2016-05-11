CXX = g++
CXXFLAGS = -O2 -I ./easylogging -std=c++11

SRCS = $(wildcard *.cpp)  
EXES = $(patsubst %cpp, %exe, $(SRCS))  

all : ${EXES}

%.exe : %.cpp
	${CXX} ${CXXFLAGS} $< -o $@

clean :
	rm -rf *.exe

cleanLog :
	rm -rf *.log
