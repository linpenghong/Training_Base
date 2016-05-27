#include <iostream>
#include <fstream>
#include <gsl/gsl_math.h>

#include "Typedef.h"
#include "Random.h"

using namespace std;

#define N 5000
#define ALPHA 0.75

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
            const mat44& m,
            const vec4& pre)
{
    cout << "Performs a LLT decompostion on" << endl;
    LLT<mat44> llt(m);
    mat44 L = llt.matrixL();

    cout << "L matrix of:\n" << L << endl;

    ofstream file;

    file.open(filename);

    auto engine = get_random_engine();
    for (int i = 0; i < N * ALPHA; i++)
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

    for (int i = N * ALPHA; i < N; i++)
    {
        quaternion.row(i) = pre.transpose();
        file << quaternion(i, 0) << " "
             << quaternion(i, 1) << " "
             << quaternion(i, 2) << " "
             << quaternion(i, 3) << endl;
    }

    file.close();
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

void performPerturb(mat& dst,
                    const mat& src)
{
    for (int i = 0; i < N; i++)
    {
        double w = dst(i, 0) * src(i, 0)
                 - dst(i, 1) * src(i, 1)
                 - dst(i, 2) * src(i, 2)
                 - dst(i, 3) * src(i, 3);
        double x = dst(i, 0) * src(i, 1)
                 + dst(i, 1) * src(i, 0)
                 + dst(i, 2) * src(i, 3)
                 - dst(i, 3) * src(i, 2);
        double y = dst(i, 0) * src(i, 2)
                 - dst(i, 1) * src(i, 3)
                 + dst(i, 2) * src(i, 0)
                 + dst(i, 3) * src(i, 1);
        double z = dst(i, 0) * src(i, 3)
                 + dst(i, 1) * src(i, 2)
                 - dst(i, 2) * src(i, 1)
                 + dst(i, 3) * src(i, 0);

        dst(i, 0) = w;
        dst(i, 1) = x;
        dst(i, 2) = y;
        dst(i, 3) = z;
    }
}

int main()
{
    cout << "Sigma" << endl;

    mat44 sigma = mat44::Identity();

    sigma << 1, 0, 0, 0,
             0, 1, 0, 0,
             0, 0, 1, 0,
             0, 0, 0, 1;

    vec4 pre(sqrt(2) / 2, sqrt(2) / 2, 0, 0);

    cout << sigma << endl << endl;

    mat quaternion(N, 4);

    cout << "Sampling" << endl;
    sample(quaternion, "4D_ACG_Resample_Before_Perturb.txt", sigma, pre);

    cout << "Inference Sigma" << endl;
    mat44 A = inferenceACG(quaternion);
    cout << A << endl << endl;

    cout << "Eigenvalues and Eigenvector" << endl;
    SelfAdjointEigenSolver<mat44> eigensolver(A);
    cout << "Eigenvalues:\n" << eigensolver.eigenvalues() << endl;
    mat44 P = eigensolver.eigenvectors();
    cout << "Columns are eigenvectors:\n" << P << endl;

    /***
    cout << "Swaping eigenveto matirx" << endl;
    P.col(0).swap(P.rightCols<1>());

    cout << "Diagonalization" << endl;
    mat44 U = P.transpose() * A * P;
    cout << U << endl;
    ***/

    cout << "Generating Estimated Perturbation Matrix" << endl;
    mat44 U = mat44::Zero();
    U(0, 0) = 3 * eigensolver.eigenvalues().maxCoeff();
    for (int i = 1; i < 4; i++)
        U(i, i) = eigensolver.eigenvalues().minCoeff();
    cout << "Perturbation Matrix:\n" << U << endl;

    cout << "Sampling Perturbation" << endl;
    mat perturb(N, 4);
    sample(perturb, "4D_ACG_Resample_Perturb.txt", U);

    cout << "Performing Perturbation" << endl;
    performPerturb(quaternion, perturb);

    ofstream file;
    file.open("4D_ACG_Resample_After_Perturb.txt");

    for (int i = 0; i < N; i++)
        file << quaternion(i, 0) << " "
             << quaternion(i, 1) << " "
             << quaternion(i, 2) << " "
             << quaternion(i, 3) << endl;

    file.close();

    return 0;
}
