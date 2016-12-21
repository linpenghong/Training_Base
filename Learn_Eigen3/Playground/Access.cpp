#include <iostream>

#include <Eigen/Dense>

#include "Typedef.h"

using namespace std;

int main()
{
    vec3 a = {1, 1, 1};

    cout << a(-1) << endl;

    return 0;
}
