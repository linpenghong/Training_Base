#include <iostream>
#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    mat44 m;
    m << 1, 2, 3, 4,
         5, 6, 7, 8,
         9, 10, 11, 12,
         13, 14, 15, 16;
    cout << m << endl << endl;

    // 2x2 submatrix starting at (1, 1)
    // fix-sized
    cout << m.block<2, 2>(1, 1) << endl << endl;

    for (int i = 1; i <= 3; i++)
    {
        // ixi submatrix starting at (0, 0)
        cout << m.block(0, 0, i, i) << endl << endl;
    }

    mat22 n;
    n << 0, 0,
         0, 0;

    m.block<2, 2>(0, 0) = n;
    cout << m << endl << endl;

    n = m.block<2, 2>(2, 2);
    cout << n << endl << endl;

    return 0;
}
