#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    MatrixXf m(2, 2);

    m << 1, 2, 3, 4;

    MatrixXf::Index maxRow, maxCol;
    float max = m.maxCoeff(&maxRow, &maxCol);

    cout << "Max: " << max << ", at: " << maxRow << "," << maxCol << endl;
}
