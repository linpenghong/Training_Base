#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    ArrayXf a = ArrayXf::Random(5);
    a *= 2;

    cout << "a =" << endl
         << a << endl;

    cout << "a.abs() =" << endl
         << a.abs() << endl;

    cout << "a.abs().sqrt() =" << endl
         << a.abs().sqrt() << endl;

    // a.min(b) --> the minimum one of the two corresponding coefficients
    cout << "a.min(a.abs().sqrt()) = " << endl
         << a.min(a.abs().sqrt()) << endl;
}
