#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double f(double x)
{
    return x * x;
}

double Local_trap(double a,
                  double b,
                  int n)
{
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    double h = (b - a) / n;
    int local_n = n / thread_count;
    double local_a = a + local_n * h * my_rank;

    double my_result = 0;
    for (int i = 0; i < local_n; i++)
    {
        double x = local_a + h * i;
        my_result += f(x) * h;
    }

    return my_result;
}

int main(int argc, char* argv[])
{
    int thread_count = strtol(argv[1], NULL, 10);

    double a, b;
    int n;
    printf("Enter a, b and n\n");
    scanf("%lf %lf %d", &a, &b, &n);

    double global_result = 0;
# pragma omp parallel num_threads(thread_count) reduction(+: global_result)
    global_result += Local_trap(a, b, n);

    printf("With n = %d trapezoids, our estimate\n", n);
    printf("of the integral from %f to %f = %.14e\n",
           a, b, global_result);

    return 0;
}
