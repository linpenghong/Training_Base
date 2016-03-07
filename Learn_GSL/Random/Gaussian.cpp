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

void angle(double& phi,
           double& theta,
           const vec3& src)
{
    theta = acos(src(2));
    phi = acos(src(0) / sin(theta));
    (src(1) > 0) ? : (phi = 2 * M_PI - phi);
};

// #define GSL_RAN_UGAUSSIAN
#define GSL_RAN_DIR_3D
// define GSL_RAN_BIVARIATE_GAUSSIAN

int main()
{
#ifdef GSL_RAN_UGAUSSIAN
    for (int i = 0; i < N; i++)
        cout << gsl_ran_ugaussian(RANDR) << endl; // draw standard Gaussian distribution
#endif

#ifdef GSL_RAN_DIR_3D
    vec3 dir;
    double phi, theta;
    for (int i = 0; i < N; i++)
    {
        gsl_ran_dir_3d(RANDR, &dir(0), &dir(1), &dir(2));
        cout << dir(0) << " " << dir(1) << " " << dir(2) << endl;
        /***
        angle(phi, theta, dir);
        cout << phi << " " << theta << endl;
        ***/
    }
#endif

#ifdef GSL_RAN_BIVARIATE_GAUSSIAN
    double x, y;
    for (int i = 0; i < N; i++)
    {
        gsl_ran_bivariate_gaussian(RANDR, 1, 1, 0.5, &x, &y);
        cout << x << " " << y << endl;
    }
#endif
}
