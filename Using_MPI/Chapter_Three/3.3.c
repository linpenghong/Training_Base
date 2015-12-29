#include <math.h>
#include <stdio.h>

#include "mpi.h"

int main(int argc, char* argv[])
{
    int n;
    
    int rank;
    int size;

    int i;

    double my_pi;
    double pi;
    double h;
    double sum;
    double x;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    while (1)
    {
        // master process, enter the number of intervals
        if (rank == 0)
        {
            printf("Enter the number of interals: (0 quits) ");
            scanf("%d", &n);
        }

        double start_time = MPI_Wtime();

        // broadcast n to each process
        MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

        if (n == 0)
            break;
        else
        {
            h = 1.0 / n;
            sum = 0.0;
            for (i = rank + 1; i <= n; i += size)
            {
                x = h * (i - 0.5);
                sum += 4 / (1 + x * x);
            }
            my_pi = h * sum;

            MPI_Reduce(&my_pi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

            if (rank == 0)
            {
                double end_time = MPI_Wtime();
                printf("pi is approximately %.16f, Error is %.16f\n",
                       pi,
                       fabs(pi - M_PI));
                printf("Consumed Time: %lf seconds\n", end_time - start_time);
            }
        }
    }

    MPI_Finalize();

    return 0;
}
