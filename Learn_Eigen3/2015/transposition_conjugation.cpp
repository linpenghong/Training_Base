#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main()
{
    // MatrixXcf --> the arbitray size matrix of which elements are complex
    // float
    MatrixXcf a = MatrixXcf::Random(2, 2);
    cout << "Here is the matrix a\n" << a << endl;

    cout << "Here is the matrix a^T\n" << a.transpose() << endl;
    cout << "Here is the conjugate of a\n" << a.conjugate() << endl;
    cout << "Here is the matrix a^*\n" << a.adjoint() << endl;

    a.transposeInPlace(); // transpose a without allocating extra memory space
    cout << "after in place transpose:\n" << a << endl;
}
