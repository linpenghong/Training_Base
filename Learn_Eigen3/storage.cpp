#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    Matrix<int, 3, 4, ColMajor> A;
    A << 8, 2, 2, 9,
         9, 1, 4, 4,
         3, 5, 4, 5;
    cout << "The Matrix A: " << endl;
    cout << A << endl << endl;
    
    cout << "The memory (column-major):" << endl;
    for (int i = 0; i < A.size(); i++)
        cout << *(A.data() + i) << " ";
    cout << endl << endl;

    Matrix<int, 3, 4, RowMajor> B = A;
    cout << "The memory (row-major):" << endl;
    for (int i = 0; i < B.size(); i++)
        cout << *(B.data() + i) << " ";
    cout << endl << endl;

    cout << "After changing the value of matrix directly:" << endl;
    for (int i = 0; i < B.size(); i++)
        *(B.data() + i) = i;
    for (int i = 0; i < B.size(); i++)
        cout << *(B.data() + i) << " ";
    cout << endl << endl;
}
