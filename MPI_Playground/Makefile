MPI_CC = mpicxx

CXXFLAGS = -O3

all : Sequential_Write.exe

Sequential_Write.exe : Sequential_Write.cpp
	$(MPI_CC) $(CXXFLAGS) -o $@ $<

clean :
	rm -f *.exe
