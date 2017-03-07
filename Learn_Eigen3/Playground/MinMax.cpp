#include <iostream>

#include <Eigen/Dense>

#include "Typedef.h"

using namespace std;

int main()
{
    mat33 a = mat33::Random();

    cout << a << endl;

    cout << a.colwise().minCoeff() << endl;

    cout << a.rowwise().minCoeff() << endl;

    return 0;
}
