#include <iostream>

#include <Eigen/Dense>

#include "Typedef.h"

using namespace std;

int main()
{
    umat A = umat::Identity(3, 3);

    cout << A << endl;

    A.resize(4, 4);

    cout << A << endl;

    return 0;
}
