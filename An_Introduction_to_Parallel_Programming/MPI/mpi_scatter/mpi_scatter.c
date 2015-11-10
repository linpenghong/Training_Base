#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void Read_vector(double local_a[],
                 int local_n,
                 int n,
                 char vec_name[],
                 int my_rank,
                 MPI_Comm comm)
{
    double* a = NULL;

    if (my_rank == 0)
    {
        a = malloc(n * sizeof(double));
        printf("Enter the vector %s\n", vec_name);

        for (int i = 0; i < n; i++)
            scanf("%lf", &a[i]);

        MPI_Scatter(a,
                    local_n,
                    MPI_DOUBLE,
                    local_a,
                    local_n,
                    MPI_DOUBLE,
                    0,
                    comm);

        free(a);
    }
    else
    {
        MPI_Scatter(a,
                    local_n,
                    MPI_DOUBLE,
                    local_a,
                    local_n,
                    MPI_DOUBLE,
                    0,
                    comm);
    }
}

int main(void)
{
    int my_rank, comm_sz;

    MPI_Init(NULL, NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    MPI_Finalize();

    return 0;
}
