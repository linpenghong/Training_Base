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

    cout << "Top Left Corner:\n"
         << m.topLeftCorner<2, 2>()
         << endl;

    cout << "Bottom Left Corner:\n"
         << m.bottomLeftCorner<2, 2>()
         << endl;

    cout << "Top Right Corner:\n"
         << m.topRightCorner<2, 2>()
         << endl;

    cout << "Bottom Right Corner:\n"
         << m.bottomRightCorner<2, 2>()
         << endl;

    cout << "Top Rows:\n"
         << m.topRows<2>()
         << endl;

    cout << "Bottom Rows:\n"
         << m.bottomRows<2>()
         << endl;

    cout << "Left Columns:\n"
         << m.leftCols<2>()
         << endl;

    cout << "Right Columns:\n"
         << m.rightCols<2>()
         << endl;

    return 0;
}
