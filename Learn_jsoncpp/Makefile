CC=g++
CXXFLAGS=-I ./jsoncpp

all : test_read.exe test_write.exe

test_read.exe : test_read.o jsoncpp.o
	${CC} ${CXXFLAGS} $^ -o $@ 

test_write.exe : test_write.o jsoncpp.o
	${CC} ${CXXFLAGS} $^ -o $@ 

test_read.o : test_read.cpp
	${CC} ${CXXFLAGS} -c $^ -o $@

jsoncpp.o : jsoncpp/jsoncpp.cpp
	${CC} ${CXXFLAGS} -c $^ -o $@

clean :
	rm *.o *.exe
