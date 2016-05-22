#include <iostream>
#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    mat33 A;
    vec3 b;

    A << 1, 2, 3,
         4, 5, 6,
         7, 8, 10;

    b << 3, 3, 4;

    cout << "Here is the matrix A:\n" << A << endl;
    cout << "Here is the vector b:\n" << b << endl;

    vec3 x = A.colPivHouseholderQr().solve(b);

    cout << "The solution is:\n" << x << endl;

    return 0;
}
