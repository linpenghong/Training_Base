#include <cstdio>

#include <mpi.h>

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    bool flag;

    MPI_Status status;

    if (rank != 0)
        MPI_Recv(&flag, 1, MPI_C_BOOL, rank - 1, 0, MPI_COMM_WORLD, &status);

    printf("rank = %d, size = %d\n", rank, size);

    FILE* file = (rank == 0) ? fopen("info.txt", "w") : fopen("info.txt", "a");

    fprintf(file, "rank = %d, size = %d\n", rank, size);

    fclose(file);

    if (rank != size - 1)
        MPI_Send(&flag, 1, MPI_C_BOOL, rank + 1, 0, MPI_COMM_WORLD);

    MPI_Finalize();

    return 0;
}
