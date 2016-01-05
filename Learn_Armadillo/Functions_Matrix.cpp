#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    // absolute value of each element
    cout << "****** abs ******" << endl;

    mat A = randu<mat>(5, 5);
    cout << A << endl;

    mat B = abs(A);
    cout << B << endl;

    // accumulation of each element
    cout << "****** accu ******" << endl;
    cout << accu(A) << endl;

    return 0;
}
