CC = g++
TARGETS = basic grid coarseFine

all : ${TARGETS}

grid : grid.cpp chealpix.c
	${CC} $^ -o $@

basic : basic.cpp chealpix.c
	${CC} $^ -o $@

coarseFine : coarseFine.cpp chealpix.c
	${CC} $^ -o $@

clean :
	rm -rf ${TARGETS}
