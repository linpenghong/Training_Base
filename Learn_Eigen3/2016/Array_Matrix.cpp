#include <iostream>
#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    mat22 m;
    m << 1, 2,
         3, 4;
    cout << "m =\n" << m << endl;

    mat22 n;
    n << 5, 6,
         7, 8;
    cout << "n =\n" << n << endl;

    cout << "Matrix m * n =\n" << m * n << endl;
    cout << "Array m * n=\n" << m.array() * n.array() << endl;
    cout << "Element Wise Product=\n" << m.cwiseProduct(n) << endl;

    return 0;
}
