#include <iostream>
#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    vec3 u(1, 2, 3);

    cout << "Squared Norm = " << u.squaredNorm() << endl;
    cout << "Norm = " << u.norm() << endl;
    cout << "2-norm = " << u.lpNorm<2>() << endl;
    cout << "1-norm = " << u.lpNorm<1>() << endl;
    cout << "Infinity-norm = " << u.lpNorm<Infinity>() << endl;

    return 0;
}
