#include <iostream>
#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    vec2 a(5, 6);
    vec3 b(5, 6, 7);
    vec4 c(5, 6, 7, 8);

    cout << "a = \n" << a << endl;
    cout << "b = \n" << b << endl;
    cout << "c = \n" << c << endl;

    return 0;
}
