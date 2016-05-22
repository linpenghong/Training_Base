#include <iostream>
#include <fstream>
#include <gsl/gsl_math.h>

#include "Typedef.h"
#include "Random.h"

using namespace std;

#define N 500

void inferenceACG(mat22& dst,
                  const mat22& src,
                  const double X[],
                  const double Y[])
{
    mat22 result = mat22::Zero();

    double nf = 0;

    for (int i = 0; i < N; i++)
    {
        mat22 m;
        m(0, 0) = X[i] * X[i];
        m(0, 1) = X[i] * Y[i];
        m(1, 0) = X[i] * Y[i];
        m(1, 1) = Y[i] * Y[i];

        vec2 v(X[i], Y[i]);
        double u = v.transpose() * src.inverse() * v;
        
        result += m / u;
        //result += m / (v.transpose() * src.inverse() * v);
        
        nf += 1.0 / u;
    }

    result *= 2.0 / nf;
    //result /= sqrt(result.determinant());

    // make it selfadjoint
    for (int i = 1; i < result.rows(); i++)
        for (int j = 0; j < i; j++)
            result(i, j) = result(j, i);

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

void sample(double X[],
            double Y[],
            const char filename[],
            const mat22& mat)
{
    cout << "Performs a LLT decompostion on" << endl;
    LLT<mat22> llt(mat);
    mat22 L = llt.matrixL();

    cout << "L matrix of:\n" << L << endl;

    ofstream file;

    file.open(filename);

    auto engine = get_random_engine();
    for (int i = 0; i < N; i++)
    {
        vec2 v;
        for (int j = 0; j < 2; j++)
            v[j] = gsl_ran_gaussian(engine, 1);

        v = L * v;
        v /= v.norm();

        X[i] = v[0];
        Y[i] = v[1];

        file << X[i] << " " << Y[i] << endl;
    }

    file.close();
}

int main()
{
    cout << "Sigma" << endl;

    mat22 sigma = mat22::Identity();

    double s0 = 1;
    double s1 = 3;
    double pho = -0.7;

    /***
    double s0 = sqrt(2);
    double s1 = sqrt(2);
    double pho = sqrt(3) / 2;
    ***/

    sigma << s0 * s0, s0 * s1 * pho,
             s0 * s1 * pho, s1 * s1;
    cout << sigma << endl << endl;

    double X[N];
    double Y[N];

    double x, y;
    double n;

    cout << "Sampling" << endl;
    sample(X, Y, "2D_ACG.txt", sigma);

    cout << "Inference Sigma" << endl;
    mat22 A;
    inferenceACG(A, X, Y);
    cout << A << endl << endl;

    cout << "Resampling" << endl;
    sample(X, Y, "2D_ACG_Re.txt", A);

    cout << "Eigenvalues and Eigenvector" << endl;
    SelfAdjointEigenSolver<mat22> eigensolver(A);
    cout << "Eigenvalues:\n" << eigensolver.eigenvalues() << endl;
    mat22 P = eigensolver.eigenvectors();
    cout << "Columns are eigenvectors:\n" << P << endl;

    cout << "Swaping eigenveto matirx" << endl;
    P.col(0).swap(P.rightCols<1>());

    cout << "Diagonalization" << endl;
    mat22 U = P.transpose() * A * P;
    cout << U << endl;

    cout << "Sampling Perturbation" << endl;
    /***
    U(0, 0) *= 5;
    ***/
    sample(X, Y, "2D_ACG_Perturb.txt", U);

    return 0;
}
