#include <iostream>
#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    mat22 a;
    a << 1, 2,
         3, 4;

    mat22 b;
    b << 2, 3,
         1, 4;

    cout << "a + b =\n" << a + b << endl;
    cout << "a - b =\n" << a - b << endl;

    a += b;
    cout << "a += b, a =\n" << a << endl;

    a -= b;
    cout << "a -= b, a =\n" << a << endl;

    return 0;
}
