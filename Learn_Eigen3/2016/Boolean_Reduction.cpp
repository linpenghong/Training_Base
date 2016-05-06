#include <iostream>
#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    mat33 m;
    m << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;

    cout << (m.array() > 0).all() << endl;
    cout << (m.array() > 0).any() << endl;
    cout << (m.array() > 0).count() << endl;

    cout << (m.array() > 2).all() << endl;
    cout << (m.array() > 2).any() << endl;
    cout << (m.array() > 2).count() << endl;

    return 0;
}
