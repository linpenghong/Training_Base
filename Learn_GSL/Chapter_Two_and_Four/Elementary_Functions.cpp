#include <cstdio>

#include <gsl/gsl_math.h>

int main()
{
    int a = 3;
    int b = 4;
    int c = 4;

    printf("gsl_hyport : %f\n", gsl_hypot(a, b));
    printf("gsl_hyport3 : %f\n", gsl_hypot3(a, b, c));

    return 0;
}
