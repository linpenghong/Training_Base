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

    vec3 v(1, 2, 3);

    cout << "a * 2.5 =\n" << a * 2.5 << endl;

    cout << "0.1 * v =\n" << 0.1 * v << endl;

    v *= 2;
    cout << "v *= 2, v =\n" << v << endl;

    return 0;
}
