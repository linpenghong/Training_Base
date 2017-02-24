#include <iostream>
#include <cmath>

#include <gsl/gsl_statistics.h>

using namespace std;

int main()
{
    double a[5] = {1, 2, 3, 4, 5};

    cout << gsl_stats_sd(a, 1, 5) << endl;

    for (int i = 0; i < 5; i++)
        a[i] /= 2;

    cout << gsl_stats_sd(a, 1, 5) << endl;

    return 0;
}
