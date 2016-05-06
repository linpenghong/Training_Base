#include <iostream>
#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    mat22 m;
    m << 1, 2,
         3, 4;

    cout << "Summation of All Elements in m:\n"
         << m.sum()
         << endl;

    cout << "Production of All Elements in m:\n"
         << m.prod()
         << endl;

    cout << "Mean of All Elements in m:\n"
         << m.mean()
         << endl;

    vec4 v(1, 2, 3, 4);

    int i;
    double val;

    val = v.minCoeff(&i);
    cout << "The Minimum Element is "
         << val
         << " at position "
         << i
         << endl;

    val = v.maxCoeff(&i);
    cout << "The Maximum Element is "
         << val
         << " at position "
         << i
         << endl;

    return 0;
}
