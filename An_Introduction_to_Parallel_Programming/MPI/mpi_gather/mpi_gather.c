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

void Print_vector(double local_b[],
                  int local_n,
                  int n,
                  char title[],
                  int my_rank,
                  MPI_Comm comm)
{
    double* b = NULL;

    if (my_rank == 0)
    {
        b = malloc(n * sizeof(double));

        MPI_Gather(local_b,
                   local_n,
                   MPI_DOUBLE,
                   b,
                   local_n,
                   MPI_DOUBLE,
                   0,
                   comm);

        for (int i = 0; i < n; i++)
            printf("%lf ", b[i]);
        printf("\n");

        free(b);
    }
    else
    {
        MPI_Gather(local_b,
                   local_n,
                   MPI_DOUBLE,
                   b,
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

    int local_n = 2;
    int n = 8;

    double local_a[local_n];

    Read_vector(local_a, local_n, n, "My_Vector", my_rank, MPI_COMM_WORLD);

    /***
    for (int i = 0; i < local_n; i++)
        printf("%f ", local_a[i]);
    printf("\n");
    ***/

    Print_vector(local_a, local_n, n, "My_Vector", my_rank, MPI_COMM_WORLD);

    MPI_Finalize();

    return 0;
}
