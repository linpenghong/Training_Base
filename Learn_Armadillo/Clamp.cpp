#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat A = randu<mat>(5, 5);
    cout << A << endl;

    mat B = clamp(A, 0.2, 0.8);
    cout << B << endl;

    mat C = clamp(A, A.min(), 0.8);
    cout << C << endl;

    mat D = clamp(A, 0.2, A.max());
    cout << D << endl;

    return 0;
}
