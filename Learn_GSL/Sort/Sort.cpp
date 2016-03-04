#include <iostream>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_sort.h>

#define N 100000
#define K 10

const static gsl_rng_type* RANDT = gsl_rng_default;
static gsl_rng* RANDR = gsl_rng_alloc(RANDT);

using namespace std;

int main()
{
    double x[N];
    for (int i = 0; i < N; i++)
        x[i] = gsl_ran_ugaussian(RANDR);

    double y[K];
    gsl_sort_largest(y, K, x, 1, N);

    for (int i = 0; i < K; i++)
        cout << y[i] << endl;
}
