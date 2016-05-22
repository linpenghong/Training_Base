#! /bin/bash

export OMP_NUM_THREADS=$2

#mpirun -n $1 -x OMP_NUM_THREADS=4 ./MPI_openmp.exe
mpirun -n $1 ./MPI_openmp.exe
