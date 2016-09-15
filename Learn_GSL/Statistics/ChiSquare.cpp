#include <iostream>
#include <cmath>
#include <vector>

#include <gsl/gsl_statistics.h>
#include <gsl/gsl_cdf.h>

using namespace std;

int main()
{
    cout << gsl_cdf_chisq_Qinv(0.01, 2) << endl;
    cout << gsl_cdf_chisq_Qinv(0.1, 2) << endl;
    cout << gsl_cdf_chisq_Qinv(0.2, 2) << endl;
    cout << gsl_cdf_chisq_Qinv(0.5, 2) << endl;

    return 0;
}
