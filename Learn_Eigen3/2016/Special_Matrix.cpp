#include <iostream>
#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    mat33 m = mat33::Zero();
    cout << m << endl << endl;

    m = mat33::Constant(1);
    cout << m << endl << endl;

    m = mat33::Identity();
    cout << m << endl << endl;

    mat44 n;
    n.topLeftCorner<2, 2>().setZero();
    n.topRightCorner<2, 2>().setIdentity();
    n.bottomLeftCorner<2, 2>().setIdentity();
    n.bottomRightCorner<2, 2>().setZero();
    cout << n << endl << endl;
    
    return 0;
}
