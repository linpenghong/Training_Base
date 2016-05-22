#include <iostream>
#include <fstream>
#include <gsl/gsl_math.h>

#include "Typedef.h"
#include "Random.h"

using namespace std;

#define N 10000

void inferenceACG(mat22& dst,
                  const mat22& src,
                  const double X[],
                  const double Y[])
{
    mat22 result = mat22::Zero();

    for (int i = 0; i < N; i++)
    {
        mat22 m;
        m(0, 0) = X[i] * X[i];
        m(0, 1) = X[i] * Y[i];
        m(1, 0) = X[i] * Y[i];
        m(1, 1) = Y[i] * Y[i];

        vec2 v(X[i], Y[i]);
        result += m / (v.transpose() * src.inverse() * v);
    }

    result /= sqrt(result.determinant());

    dst = result;
}

void inferenceACG(mat22& mat,
                  const double X[],
                  const double Y[])
{
    mat22 A;
    mat22 B = mat22::Identity();

    do
    {
        A = B;
        inferenceACG(B, A, X, Y);
    } while ((abs((A - B).array())).sum() > 0.001);

    mat = A;
}

int main()
{
    ofstream file;

    cout << "Sigma" << endl;

    mat22 sigma = mat22::Identity();

    double s0 = sqrt(2);
    double s1 = sqrt(2);
    double pho = sqrt(3) / 2;

    sigma << s0 * s0, s0 * s1 * pho,
             s0 * s1 * pho, s1 * s1;
    cout << sigma << endl << endl;

    double X[N];
    double Y[N];

    double x, y;
    double n;

    file.open("2D_ACG.txt");

    auto engine = get_random_engine();
    for (int i = 0; i < N; i++)
    {
        gsl_ran_bivariate_gaussian(engine, s0, s1, pho, &x, &y);
        n = gsl_hypot(x, y);
        X[i] = x / n;
        Y[i] = y / n;
        file << X[i] << " " << Y[i] << endl;
    }

    file.close();

    cout << "Inference Sigma" << endl;
    mat22 A;
    inferenceACG(A, X, Y);
    cout << A << endl << endl;

    return 0;
}
