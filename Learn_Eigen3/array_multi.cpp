#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    Array22f a, b;
    a << 1, 2, 3, 4;
    b << 5, 6, 7, 8;

    // array multiply is "coefficient-wise dot"
    cout << "a * b = " << endl
         << a * b << endl;
}
