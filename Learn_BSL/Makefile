CXX = g++
CXXFLAGS = -O2 -std=c++11 -lbingham -larmadillo

SRCS = $(wildcard *.cpp)  
EXES = $(patsubst %cpp, %exe, $(SRCS))  

all : ${EXES}

%.exe : %.cpp
	${CXX} ${CXXFLAGS} $< -o $@

clean :
	rm -rf *.exe
