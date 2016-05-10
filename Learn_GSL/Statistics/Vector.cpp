#include <iostream>
#include <cmath>
#include <vector>

#include <gsl/gsl_statistics.h>

#define N 10000

using namespace std;

int main()
{
    vector<double> v;

    for (int i = 0; i < N; i++)
        v.push_back(i);

    double mean = gsl_stats_mean(&v[0], 1, N);
    cout << "mean = " << mean << endl;

    double stddev = gsl_stats_sd_m(&v[0], 1, N, mean);
    cout << "stddev = " << stddev << endl;

    return 0;
}
