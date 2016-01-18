#include <armadillo>
#include <cstdio>
#include <iostream>

#include <mpi.h>

using namespace std;
using namespace arma;

int main(int argc, char* argv[])
{
    int m = 10;
    int n = 10;
    int r = 10;

    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int p;
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    mat global_A(m, n);
    mat B(n, r);
    mat global_C(m, r);

    mat local_A(m / p, n);
    mat local_C(m / p, r);

    if (rank == 0)
    {
        global_A.randu();
        cout << global_A << endl;
        B.randu();
        cout << B << endl;
    }

    MPI_Scatter(global_A.memptr(),
                (m / p) * n,
                MPI_DOUBLE,
                local_A.memptr(),
                (m / p) * n,
                MPI_DOUBLE,
                0,
                MPI_COMM_WORLD); 

    MPI_Bcast(B.memptr(),
              n * r,
              MPI_DOUBLE,
              0,
              MPI_COMM_WORLD);

    local_C = local_A * B;

    MPI_Gather(local_C.memptr(),
               (m / p) * r,
               MPI_DOUBLE,
               global_C.memptr(),
               (m / p) * r,
               MPI_DOUBLE,
               0,
               MPI_COMM_WORLD);

    if (rank == 0)
        cout << global_C << endl;

    MPI_Finalize();

    return 0;
}
