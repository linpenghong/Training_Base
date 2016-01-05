#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat A = randu<mat>(5, 5);
    mat B = randu<mat>(6, 7);

    cout << A.is_square() << endl;
    cout << B.is_square() << endl;

    return 0;
}
