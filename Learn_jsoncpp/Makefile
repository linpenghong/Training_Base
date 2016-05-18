CC=g++
CXXFLAGS=-I ./jsoncpp

test.exe : test.o jsoncpp.o
	${CC} ${CXXFLAGS} $^ -o $@ 

test.o : test.cpp
	${CC} ${CXXFLAGS} -c $^ -o $@

jsoncpp.o : jsoncpp/jsoncpp.cpp
	${CC} ${CXXFLAGS} -c $^ -o $@

clean :
	rm *.o *.exe
