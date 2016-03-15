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
    mat A(N, 3);

    mat Q = {{1, 0.5, 0}, {0.5, 4, 0.5}, {0, 0.5, 9}};
    cout << Q << endl;

    mat L = chol(Q, "lower");
    for (int i = 0; i < N; i++)
        A.row(i) = (L * randn<vec>(3)).t();

    Q = cov(A);
    cout << Q << endl;
}
