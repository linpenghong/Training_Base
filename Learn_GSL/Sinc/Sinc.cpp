#include <iostream>
#include <cmath>

#include <gsl/gsl_sf.h>
#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_math.h>

using namespace std;

int main()
{
    double x = 0.125;

    cout << gsl_pow_2(gsl_sf_sinc(x)) << endl;

    cout << gsl_pow_2(gsl_sf_bessel_j0(M_PI * x)) << endl;

    return 0;
}
