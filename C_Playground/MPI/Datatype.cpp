#include <cstdio>

#include <mpi.h>

using namespace std;

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    printf("sizeof(MPI_INT) : %d\n", sizeof(MPI_INT));
    printf("sizeof(MPI_FLOAT) : %d\n", sizeof(MPI_FLOAT));
    printf("sizeof(MPI_DOUBLE) : %d\n", sizeof(MPI_DOUBLE));

    int size;

    MPI_Type_size(MPI_INT, &size);
    printf("MPI_INT : %d\n", size);

    MPI_Type_size(MPI_FLOAT, &size);
    printf("MPI_FLOAT : %d\n", size);

    MPI_Type_size(MPI_DOUBLE, &size);
    printf("MPI_DOUBLE : %d\n", size);

    MPI_Type_size(MPI_DOUBLE_COMPLEX, &size);
    printf("MPI_DOUBLE_COMPLEX : %d\n", size);

    MPI_Type_size(MPI_C_DOUBLE_COMPLEX, &size);
    printf("MPI_C_DOUBLE_COMPLEX : %d\n", size);

    MPI_Finalize();

    return 0;
}
