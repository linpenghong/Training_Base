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

    return 0;
}
