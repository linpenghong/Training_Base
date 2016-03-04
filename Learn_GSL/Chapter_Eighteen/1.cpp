#include <cstdio>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

#define N 100000

const static gsl_rng_type* T = gsl_rng_default;
static gsl_rng* r = gsl_rng_alloc(T);

int main()
{
    /***
    printf("generator type: %s\n", gsl_rng_name(r));
    printf("seed = %s\n", gsl_rng_default_seed);
    ***/

    for (int i = 0; i < N; i++)
        printf("%f %f\n",
               gsl_ran_gaussian(r, 1),
               gsl_ran_gaussian(r, 1));

    return 0;
}
