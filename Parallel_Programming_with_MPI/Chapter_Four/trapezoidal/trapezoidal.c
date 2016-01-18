#include <stdio.h>

#include "mpi.h"

float f(float x)
{
    return x * x;
};

float Trap(float local_a,
           float local_b,
           int local_n,
           float h)
{
    float integral;
    float x;

    integral = (f(local_a) + f(local_b)) / 2;
    x = local_a;
    for (int i = 0; i <= local_n - 1; i++)
    {
        x += h;
        integral += f(x);
    }

    return integral * h;
};

int main(int argc, char* argv[])
{
    int my_rank;
    int p;
    float a = 0.0;
    float b = 1.0;
    int n = 1024;
    float h;
    float local_a;
    float local_b;
    int local_n;

    float integral;
    float total;

    int src;
    int dst = 0;
    int tag = 0;
    MPI_Status status;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    h = (b - a) / n;
    local_n = n / p;

    local_a = a + my_rank * local_n * h;
    local_b = local_a + local_n * h;
    integral = Trap(local_a, local_b, local_n, h);

    if (my_rank == 0)
    {
        total = integral;
        
        for (src = 1; src < p; src++)
        {
            MPI_Recv(&integral, 1, MPI_FLOAT, src, tag, MPI_COMM_WORLD, &status);
            total += integral;
        }
    }
    else
        MPI_Send(&integral, 1, MPI_FLOAT, dst, tag, MPI_COMM_WORLD);

    if (my_rank == 0)
    {
        printf("With n = %d trapezoidals, our estimate\n", n);
        printf("of the integral from %f to %f = %f\n", a, b, total);
    }

    MPI_Finalize();

    return 0;
}
