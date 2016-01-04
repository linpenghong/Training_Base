#include <cstdio>

#include <gsl/gsl_math.h>

int main()
{
    double a = 3;
    printf("gsl_pow_2 : %lf\n", gsl_pow_2(a));
    printf("gsl_pow_3 : %lf\n", gsl_pow_3(a));
    
    return 0;
}
