#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat A = eye<mat>(5, 5);
    cout << A << endl;

    vec v = linspace<vec>(10, 20, 5);
    cout << v << endl;

    mat B = ones<mat>(5, 6);
    cout << B << endl;

    return 0;
}
