#include <cstdio>
#include <cmath>

#include <mpi.h>

#define BUF_SIZE 10

int main(int argc, char* argv[])
{
    int rank, size;

    int buf[BUF_SIZE];

    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        for (int i = 0; i < BUF_SIZE; i++)
            buf[i] = -1;

        MPI_Recv(buf, BUF_SIZE, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);

        for (int i = 0; i < 10; i++)
            printf("Buffer[%d] = %d\n", i, buf[i]);
    }
    
    if (rank == 1)
    {
        for (int i = 0; i < BUF_SIZE; i++)
            buf[i] = i;

        // Ready Send -> MPI_Revc has prepared. If not, an error will occur.
        MPI_Rsend(buf, BUF_SIZE, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}
