CC = g++
CFLAGS = -lsqlite3

all : main

main : main.o Experiment.o Sqlite3Error.o
	${CC} ${CFLAGS} -o $@ $^

%.o : %.cpp
	${CC} -o $@ -c $^
