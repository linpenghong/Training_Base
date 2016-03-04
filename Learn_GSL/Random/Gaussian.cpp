#include <iostream>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

#define N 500

const static gsl_rng_type* RANDT = gsl_rng_default;
static gsl_rng* RANDR = gsl_rng_alloc(RANDT);

using namespace std;

// #define GSL_RAN_UGAUSSIAN
#define GSL_RAN_DIR_3D

int main()
{
#ifdef GSL_RAN_UGAUSSIAN
    for (int i = 0; i < N; i++)
        cout << gsl_ran_ugaussian(RANDR) << endl; // draw standard Gaussian distribution
#endif

#ifdef GSL_RAN_DIR_3D
    double x, y, z;
    for (int i = 0; i < N; i++)
    {
        gsl_ran_dir_3d(RANDR, &x, &y, &z);
        cout << x << " " << y << " " << z << endl;
    }
#endif
}
