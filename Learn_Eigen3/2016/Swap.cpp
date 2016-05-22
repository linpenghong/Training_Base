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

    cout << "Swapping the first column with the last column" << endl;

    m.col(0).swap(m.rightCols<1>());
    cout << m << endl << endl;

    return 0;
}
