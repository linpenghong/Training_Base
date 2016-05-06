#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main()
{
    RowVectorXd vec1(3);
    vec1 << 1, 2, 3;
    std::cout << "vec1 = " << vec1 << std::endl;
}
