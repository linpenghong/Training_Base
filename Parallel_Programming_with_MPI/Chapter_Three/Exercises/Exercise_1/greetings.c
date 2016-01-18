#include <stdio.h>
#include <string.h>

#include "mpi.h"

int main(int argc, char* argv[])
{
    int my_rank; /* rank of process */
    int p; /* number of process */
    int src;
    int dst;
    int tag = 0;
    char message[100];
    MPI_Status status;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    if (my_rank != 0)
    {
        sprintf(message, "Greetings from process %d!", my_rank);
        dst = 0;
        MPI_Send(message,
                 strlen(message) + 1,
                 MPI_CHAR,
                 dst,
                 tag,
                 MPI_COMM_WORLD);
    }
    else
    {
        for (src = 1; src < p; src++)
        {
            MPI_Recv(message,
                     100,
                     MPI_CHAR,
                     src,
                     tag,
                     MPI_COMM_WORLD,
                     &status);
            printf("%s\n", message);
        }
    }

    MPI_Finalize();

    return 0;
}
