#include <iostream>
#include <fstream>
#include <gsl/gsl_math.h>

#include "Typedef.h"
#include "Random.h"

using namespace std;

#define N 10000

mat44 inferenceACG(const mat44& m,
                   const mat& quaternion)
{
    mat44 result = mat44::Zero();

    double nf = 0;

    for (int i = 0; i < N; i++)
    {
        vec4 v = quaternion.row(i).transpose();

        // tensor product
        mat44 tensor;
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                tensor(j, k) = quaternion(i, j) * quaternion(i, k);

        double u = v.transpose() * m.inverse() * v;
        
        result += tensor / u;
        
        nf += 1.0 / u;
    }

    result *= 4.0 / nf;

    // make it selfadjoint
    for (int i = 1; i < result.rows(); i++)
        for (int j = 0; j < i; j++)
            result(i, j) = result(j, i);

    return result;
}

mat44 inferenceACG(const mat& quaternion)
{
    mat44 A;
    mat44 B = mat44::Identity();

    do
    {
        A = B;
        B = inferenceACG(A, quaternion);
    } while ((abs((A - B).array())).sum() > 0.001);

    return A;
}

void sample(mat& quaternion,
            const char filename[],
            const mat44& m)
{
    cout << "Performs a LLT decompostion on" << endl;
    LLT<mat44> llt(m);
    mat44 L = llt.matrixL();

    cout << "L matrix of:\n" << L << endl;

    ofstream file;

    file.open(filename);

    auto engine = get_random_engine();
    for (int i = 0; i < N; i++)
    {
        vec4 v;
        for (int j = 0; j < 4; j++)
            v[j] = gsl_ran_gaussian(engine, 1);

        v = L * v;
        v /= v.norm();

        quaternion.row(i) = v.transpose();

        file << quaternion(i, 0) << " "
             << quaternion(i, 1) << " "
             << quaternion(i, 2) << " "
             << quaternion(i, 3) << endl;
    }

    file.close();
}

int main()
{
    cout << "Sigma" << endl;

    mat44 sigma = mat44::Identity();

    sigma << 125, 0, 0, 0,
             0, 1, 0, 0,
             0, 0, 1, 0,
             0, 0, 0, 1;

    /***
    double s0 = 1;
    double s1 = 3;
    double pho = -0.7;
    ***/

    /***
    double s0 = sqrt(2);
    double s1 = sqrt(2);
    double pho = sqrt(3) / 2;
    ***/

    /***
    sigma << s0 * s0, s0 * s1 * pho,
             s0 * s1 * pho, s1 * s1;
             ***/
    cout << sigma << endl << endl;

    mat quaternion(N, 4);

    cout << "Sampling" << endl;
    sample(quaternion, "4D_ACG.txt", sigma);

    cout << "Inference Sigma" << endl;
    mat44 A = inferenceACG(quaternion);
    cout << A << endl << endl;

    cout << "Resampling" << endl;
    sample(quaternion, "4D_ACG_Re.txt", A);

    cout << "Eigenvalues and Eigenvector" << endl;
    SelfAdjointEigenSolver<mat44> eigensolver(A);
    cout << "Eigenvalues:\n" << eigensolver.eigenvalues() << endl;
    mat44 P = eigensolver.eigenvectors();
    cout << "Columns are eigenvectors:\n" << P << endl;

    cout << "Swaping eigenveto matirx" << endl;
    P.col(0).swap(P.rightCols<1>());

    cout << "Diagonalization" << endl;
    mat44 U = P.transpose() * A * P;
    cout << U << endl;

    cout << "Generating Estimated Perturbation Matrix" << endl;
    U = mat44::Zero();
    U(0, 0) = 1; // TODO
    for (int i = 1; i < 4; i++)
        U(i, i) = 0; // TODO

    cout << "Sampling Perturbation" << endl;
    sample(quaternion, "2D_ACG_Perturb.txt", U);

    return 0;
}
