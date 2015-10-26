CC = g++
TARGETS = coarseFine basic

all : ${TARGETS}

coarseFine: coarseFine.cpp chealpix.c
	${CC} $^ -o $@

basic : basic.cpp chealpix.c
	${CC} $^ -o $@

clean :
	rm -rf ${TARGETS}
