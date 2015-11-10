#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double f(double x)
{
    return x * x;
}

int main(int argc, char* argv[])
{
    int thread_count = strtol(argv[1], NULL, 10);

    double a, b;
    int n;
    printf("Enter a, b and n\n");
    scanf("%lf %lf %d", &a, &b, &n);

    double h = (b - a) / n;

    double approx = 0;
# pragma omp parallel for num_threads(thread_count) reduction(+: approx)
    for (int i = 0; i < n; i++)
        approx += f(a + i * h) * h;

    printf("With n = %d trapezoids, our estimate\n", n);
    printf("of the integral from %f to %f = %.14e\n",
           a, b, approx);

    return 0;
}
