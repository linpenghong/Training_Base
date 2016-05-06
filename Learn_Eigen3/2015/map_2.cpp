#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    typedef Matrix<float, 1, Dynamic> MatrixType;
    typedef Map<MatrixType> MapType;
    typedef Map<const MatrixType> MapTypeConst;
    const int n_dims = 5;

    MatrixType m1(n_dims);
    MatrixType m2(m_dims);

    m1.setRandom();
    m2.setRandom();

    float* p = &m2(0);
    MapType m2map(p, m2.size());
    MapTypeConst m2mapconst(p, m2.size());
}
