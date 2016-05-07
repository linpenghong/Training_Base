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

    // The default storage order of Eigen3 is column-major.
    cout << "Memory Pointer of m is " << m.data() << endl;
    for (int i = 0; i < m.size(); i++)
        cout << *(m.data() + i) << " ";
    cout << endl << endl;

    for (int i = 0; i < m.cols(); i++)
    {
        cout << "Memory Pointer of " << i << "(th) Columns of m is "
             << m.col(i).data()
             << endl;
        for (int j = 0; j < m.rows(); j++)
            cout << *(m.col(i).data() + j) << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}
