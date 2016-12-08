#include <iostream>

#define EIGEN_NO_DEBUG

#include <Eigen/Dense>

#include "Typedef.h"

using namespace std;

int main()
{
    vec a = vec::Constant(1, 1);

    cout << a << endl;

    cout << a.size() << endl;

    return 0;
}
