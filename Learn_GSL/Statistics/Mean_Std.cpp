#include <iostream>
#include <cmath>

#include <gsl/gsl_statistics.h>

#define M 95
#define N 5

using namespace std;

int main()
{
    double data[M + N];

    for (int i = 0; i < M; i++)
        data[i] = 0;

    for (int i = 0; i < N; i++)
        data[M + i] = 1;

    double mean = gsl_stats_mean(data, 1, M + N);
    double std = gsl_stats_sd_m(data, 1, M + N, mean);

    cout << "mean = " << mean << endl;
    cout << "std = " << std << endl;

    return 0;
}
