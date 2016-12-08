#include <iostream>

#define EIGEN_NO_DEBUG

#include <Eigen/Dense>

#include "Typedef.h"

using namespace std;

int main()
{
    vec3 a = {1, 1, 1};

    for (int i = 0; i < 100000; i++)
        cout << a[i] << endl;

    return 0;
}
