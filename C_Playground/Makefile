CC = g++

SRCS = $(wildcard *.cpp)  
EXES = $(patsubst %cpp, %exe, $(SRCS))  

all : ${EXES}

%.exe : %.cpp
	$(CC) $< -o $@

clean :
	rm -rf *.exe
