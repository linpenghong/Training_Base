CC = g++
CFLAGS = -lsqlite3 -std=c++11

all : main

main : main.o Experiment.o Sqlite3Error.o
	${CC} ${CFLAGS} -o $@ $^

%.o : %.cpp
	${CC} ${CFLAGS} -o $@ -c $^

clean :
	rm *.o *.exe
