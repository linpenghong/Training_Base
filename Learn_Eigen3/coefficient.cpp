#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    Matrix3f m = Matrix3f::Random();

    // return a value of mininum coefficient of this matrix, meanwhile return
    // the location of it
    ptrdiff_t i, j;
    float minOfM = m.minCoeff(&i, &j);
    cout << "Here is the matrix m:\n" << m << endl;
    cout << "Its minimum coefficient (" << minOfM << ") is at position ("
         << i << "," << j << ")\n\n";
}
