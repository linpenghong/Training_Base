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
    FILE* pSrc = fopen("src.txt", "wb");

    mat A(N, 2);
    for (int i = 0; i < N; i++)
    {
        gsl_ran_bivariate_gaussian(RANDR, 1, 2, 0.5, &A(i, 0), &A(i, 1));
        fprintf(pSrc, "%12f %12f\n", A(i, 0), A(i, 1));
    }

    fclose(pSrc);

    mat Q = cov(A);
    cout << "Covariance Matrix:"
         << endl
         << Q
         << endl;

    mat L = chol(Q, "lower");
    cout << "Cholesky Decomposition of Covariance Matrix:"
         << endl
         << L
         << endl;

    FILE* pDst = fopen("dst.txt", "wb");

    for (int i = 0; i < N; i++)
    {
        vec y = L * randn<vec>(2);
        fprintf(pDst, "%12f %12f\n", y(0), y(1));
    }

    fclose(pDst);
}
