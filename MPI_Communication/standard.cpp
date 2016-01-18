#include <cstdio>
#include <cmath>

#include <mpi.h>

#define BUF_SIZE 10

int main(int argc, char* argv[])
{
    int rank, size;

    int sb[BUF_SIZE];
    int rb[BUF_SIZE];

    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    for (int i = 0; i < BUF_SIZE; i++)
        sb[i] = rank + i;

    if (rank != 0)
        MPI_Send(sb, BUF_SIZE, MPI_INT, 0, 0, MPI_COMM_WORLD);
    else
        for (int i = 1; i < size; i++)
            MPI_Recv(rb, BUF_SIZE, MPI_INT, i, 0, MPI_COMM_WORLD, &status);

    MPI_Finalize();

    return 0;
}
