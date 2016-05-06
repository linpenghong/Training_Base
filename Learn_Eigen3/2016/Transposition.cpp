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
    cout << "a =\n" << a << endl;

    mat22 b = a.transpose();
    cout << "b =\n" << b << endl;

    // use transposeInPlace instead of transpose for avoiding "aliasing issue"
    a.transposeInPlace();
    cout << "a =\n" << a << endl;

    return 0;
}
