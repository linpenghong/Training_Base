#include <iostream>
#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    mat22 m;
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = 10;

    cout << "m = \n" << m << endl;

    cout << "Number of Rows of m = "
         << m.rows()
         << endl;

    cout << "Number of Columns of m = "
         << m.cols()
         << endl;

    return 0;
}
