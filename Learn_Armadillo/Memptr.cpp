#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat A = randu<mat>(5, 5);
    double* A_mem = A.memptr();
    cout << A_mem << endl;

    const mat B = randu<mat>(5, 5);
    const double* B_mem = B.memptr();
    cout << B_mem << endl;

    return 0;
}
