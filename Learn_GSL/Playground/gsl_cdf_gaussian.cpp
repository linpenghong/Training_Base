#include <iostream>
#include <cmath>

#include <gsl/gsl_statistics.h>
#include <gsl/gsl_cdf.h>

using namespace std;

int main()
{
    cout << gsl_cdf_gaussian_Qinv(0.1, 1) << endl;

    cout << gsl_cdf_gaussian_Qinv(0.01, 1) << endl;

    cout << gsl_cdf_gaussian_Qinv(0.05, 1) << endl;

    cout << gsl_cdf_gaussian_Qinv(0.025, 1) << endl;

    return 0;
}
