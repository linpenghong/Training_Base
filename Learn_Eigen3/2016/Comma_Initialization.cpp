#include <iostream>
#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    mat33 m;
    m << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;

    cout << "m = \n" << m << endl;

    m.row(0) << 1, 2, 3;
    m.block<2, 2>(1, 0) << 4, 5, 7, 8;
    m.col(2).tail(2) << 6, 9;

    cout << "m = \n" << m << endl;

    return 0;
}
