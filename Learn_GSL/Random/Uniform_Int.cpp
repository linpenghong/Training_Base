#include <cmath>
#include <iostream>

#include <armadillo>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_cblas.h>

#define N 10000
#define K 10

const static gsl_rng_type* RANDT = gsl_rng_default;
static gsl_rng* RANDR = gsl_rng_alloc(RANDT);

using namespace std;
using namespace arma;

int main()
{
    int X[K];
    memset(X, 0, sizeof(int) * K);
    int Y[K];
    memset(Y, 0, sizeof(int) * K);

    /***
    for (int i = 0; i < N; i++)
        cout << gsl_rng_uniform_int(RANDR, K) << endl;
    ***/

    for (int i = 0; i < N; i++)
    {
        X[gsl_rng_uniform_int(RANDR, K)] += 1;
        Y[gsl_rng_uniform_int(RANDR, K)] += 1;
    }

    double W[K * K];

    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            W[K * j + i] = X[i] * Y[j];

    double sum = cblas_dasum(K * K, W, 1);

    // cout << sum << endl;

    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            cout << i
                 << " "
                 << j
                 << " "
                 << W[K * j + i] / sum
                 << endl;
}
