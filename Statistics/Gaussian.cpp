#include <cmath>
#include <iostream>

#include <armadillo>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

#define N 100000

const static gsl_rng_type* RANDT = gsl_rng_default;
static gsl_rng* RANDR = gsl_rng_alloc(RANDT);

using namespace std;
using namespace arma;

int main()
{
    mat A(N, 2);
    for (int i = 0; i < N; i++)
        gsl_ran_bivariate_gaussian(RANDR, 1, 2, 0.5, &A(i, 0), &A(i, 1));

    cout << cov(A) << endl;
}
