#include <iostream>

#include <Eigen/Dense>

#include "Typedef.h"

using namespace std;

int main()
{
    vec3 a = vec3::Random();

    cout << a << endl;

    a.array() = a.array() * a.array();

    cout << a << endl;

    return 0;
}
