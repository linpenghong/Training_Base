CC = g++
MPI_CC = mpicxx

#CXXFLAGS = -O3 -lgomp
CXXFLAGS = -O2 -fopenmp

all : openmp.exe MPI_openmp.exe

openmp.exe : openmp.cpp
	$(CC) $(CXXFLAGS) -o $@ $<

MPI_openmp.exe : MPI_openmp.cpp
	${MPI_CC} ${CXXFLAGS} -o $@ $<

clean :
	rm -f *.exe
