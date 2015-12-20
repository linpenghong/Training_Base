CC = g++
CFLAGS = -lgsl

Test : Test.o Relion_Bessel.o
	${CC} ${CFLAGS} -o $@ $^

Relion_Bessel.o : Relion_Bessel.cpp
	${CC} ${CFLAGS} -o $@ -c $^
