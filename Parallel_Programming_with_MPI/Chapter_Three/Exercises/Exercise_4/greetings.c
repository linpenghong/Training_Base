#include <stdio.h>
#include <string.h>

#include "mpi.h"

int main(int argc, char* argv[])
{
    int my_rank; /* rank of process */
    int p; /* number of process */
    int src;
    int dst;
    char message[100];
    MPI_Status status;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    if (my_rank != p - 1)
    {
        sprintf(message, "Greetings from process %d!", my_rank);
        dst = p - 1;
        MPI_Send(message,
                 strlen(message) + 1,
                 MPI_CHAR,
                 dst,
                 0,
                 MPI_COMM_WORLD);
    }
    else
    {
        for (src = 0; src < p - 1; src++)
        {
            MPI_Recv(message,
                     100,
                     MPI_CHAR,
                     src,
                     MPI_ANY_TAG,
                     MPI_COMM_WORLD,
                     &status);
            printf("%s\n", message);
        }
    }

    MPI_Finalize();

    return 0;
}
