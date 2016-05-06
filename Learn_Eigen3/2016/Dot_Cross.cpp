#include <iostream>
#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    vec3 v(1, 2, 3);
    vec3 w(0, 1, 2);

    cout << "Dot Product: \n" << v.dot(w) << endl;
    cout << "Cross Product: \n" << v.cross(w) << endl;

    return 0;
}
