#include <iostream>
#include <cmath>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_statistics.h>
#include <gsl/gsl_cblas.h>

#define N 100000

const static gsl_rng_type* RANDT = gsl_rng_default;
static gsl_rng* RANDR = gsl_rng_alloc(RANDT);

using namespace std;

// #define GSL_STATS_MEAN

// #define GSL_STATS_VARIANCE

// #define GSL_STATS_SD

// #define GSL_STATS

#define STATS_GAUSSIAN_2D

double wCor(const double* x,
            const double* y,
            const double* w,
            const double meanX,
            const double meanY,
            const size_t n)
{
    double sum = 0;
    for (size_t i = 0; i < N; i++)
        sum += w[i] * (x[i] - meanX) * (y[i] - meanY);
    return sum / cblas_dasum(n, w, 1);
};

void statsGaussian2D(double& meanX,
                     double& meanY,
                     double& sdX,
                     double& sdY,
                     double& rho,
                     const double* x,
                     const double* y,
                     const double* w,
                     const size_t n)
{
    meanX = gsl_stats_wmean(w, 1, x, 1, n);
    meanY = gsl_stats_wmean(w, 1, y, 1, n);

    sdX = gsl_stats_wsd_m(w, 1, x, 1, n, meanX);
    sdY = gsl_stats_wsd_m(w, 1, y, 1, n, meanY);
    
    /***
    cout << wCor(x, y, w, meanX, meanY, n) << endl;
    cout << wCor(x, x, w, meanX, meanX, n) << endl;
    cout << wCor(y, y, w, meanY, meanY, n) << endl;
    ***/
    rho = wCor(x, y, w, meanX, meanY, n)
        / sqrt(wCor(x, x, w, meanX, meanX, n))
        / sqrt(wCor(y, y, w, meanY, meanY, n));
};

int main()
{
    double x[N];

    for (int i = 0; i < N; i++)
        x[i] = gsl_ran_ugaussian(RANDR) + 1;

#ifdef GSL_STATS_MEAN
    cout << gsl_stats_mean(x, 1, N) << endl;
#endif

#ifdef GSL_STATS_VARIANCE
    cout << gsl_stats_variance(x, 1, N) << endl; // this function returns the SQUARE of the standard deviation
#endif

#ifdef GSL_STATS_SD
    cout << gsl_stats_sd(x, 1, N) << endl; // this function returns the standard deviation
#endif

    double X[N];
    double Y[N];

    for (int i = 0; i < N; i++)
        gsl_ran_bivariate_gaussian(RANDR, 1, 2, 0.5, &X[i], &Y[i]);

#ifdef GSL_STATS
    cout << "Standard Deviation of X = "
         << gsl_stats_sd_m(X, 1, N, 0)
         << endl;
    cout << "Standard Deviation of Y = "
         << gsl_stats_sd_m(Y, 1, N, 0)
         << endl;
    cout << "Correlation between X and Y = "
         << gsl_stats_correlation(X, 1, Y, 1, N)
         << endl;
#endif

#ifdef STATS_GAUSSIAN_2D
    double meanX, meanY, sdX, sdY, rho;
    statsGaussian2D(meanX, meanY, sdX, sdY, rho, X, Y, x, N); // using x as w
    cout << "meanX = " << meanX << endl;
    cout << "meanY = " << meanY << endl;
    cout << "sdX = " << sdX << endl;
    cout << "sdY = " << sdY << endl;
    cout << "rho = " << rho << endl;
#endif
}
