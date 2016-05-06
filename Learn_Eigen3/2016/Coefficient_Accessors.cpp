#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

/***
#define mat22 Matrix<double, 2, 2>
#define mat33 Matrix<double, 3, 3>
***/

typedef Matrix<double, 2, 2> mat22;
typedef Matrix<double, 3, 3> mat33;

/***
typedef Matrix2d mat22;
typedef Matrix3d mat33;
**/

int main()
{
    mat22 m;
    //MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = 10;

    cout << "m = \n" << m << endl;

    return 0;
}
