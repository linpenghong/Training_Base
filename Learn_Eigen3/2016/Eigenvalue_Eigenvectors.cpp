#include <iostream>
#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    mat22 A;
    /***
    A << 1, 2,
         2, 3;
         ***/
    A << 1, 0,
         0, 1;

    cout << "Here is the Matrix A:\n" << A << endl;

    SelfAdjointEigenSolver<mat22> eigensolver(A);

    cout << "The eigenvalues of A are:\n"
         << eigensolver.eigenvalues()
         << endl;

    cout << "Here's a matrix whose columns are eigenvectors of A corresponding to these eigenvalues:\n"
         << eigensolver.eigenvectors()
         << endl;

    return 0;
}
