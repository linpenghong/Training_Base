CC = g++

#CFLAG0 = -O3 -lgomp
CFLAG0 = -O3 -fopenmp

all : HelloWorld.exe Reduction.exe

HelloWorld.exe : HelloWorld.cpp
	$(CC) $(CFLAG0) -o $@ $<

Reduction.exe : Reduction.cpp
	$(CC) $(CFLAG0) -o $@ $<

clean :
	rm -f *.exe
