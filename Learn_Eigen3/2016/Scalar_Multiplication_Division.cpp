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

    return 0;
}
