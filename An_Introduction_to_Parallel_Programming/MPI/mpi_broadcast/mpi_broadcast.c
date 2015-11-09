#include <stdio.h>
#include <mpi.h>

void Get_data(int my_rank,
              int comm_sz,
              double* a_p,
              double* b_p,
              int* n_p);

int main(void)
{
    int my_rank, comm_sz;

    MPI_Init(NULL, NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    double a, b;
    int n;

    Get_data(my_rank, comm_sz, &a, &b, &n);

    MPI_Finalize();

    return 0;
}

void Get_data(int my_rank,
              int comm_sz,
              double* a_p,
              double* b_p,
              int* n_p)
{
    if (my_rank == 0)
    {
        printf("Enter a, b and n\n");
        scanf("%lf %lf %d", a_p, b_p, n_p);
    }

    MPI_Bcast(a_p, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(b_p, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(n_p, 1, MPI_INT, 0, MPI_COMM_WORLD);
}
