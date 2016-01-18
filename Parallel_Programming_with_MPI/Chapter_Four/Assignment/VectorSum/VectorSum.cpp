#include <armadillo>
#include <cstdio>
#include <iostream>

#include <mpi.h>

using namespace std;
using namespace arma;

int main(int argc, char* argv[])
{
    int size = 10;

    MPI_Init(&argc, &argv);

    vec my_vec = randu<vec>(size);

    vec sum_vec(size);

    for (int i = 0; i < size; i++)
        MPI_Reduce(my_vec.memptr() + i,
                   sum_vec.memptr() + i,
                   1,
                   MPI_DOUBLE,
                   MPI_SUM,
                   0,
                   MPI_COMM_WORLD);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
        cout << sum_vec << endl;

    MPI_Finalize();

    return 0;
}
