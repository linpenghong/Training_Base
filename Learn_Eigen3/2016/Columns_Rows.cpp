#include <iostream>
#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    mat44 m;
    m << 1, 2, 3, 4,
         5, 6, 7, 8,
         9, 10, 11, 12,
         13, 14, 15, 16;
    cout << m << endl << endl;

    cout << "2nd Row: " << m.row(1) << endl << endl;

    cout << "Adding 3 Times the 1st Column into the 3rd Column" << endl;
    m.col(2) += 3 * m.col(0);
    cout << m << endl << endl;

    return 0;
}
