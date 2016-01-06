#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat A = randu<mat>(4, 5);
    cout << A << endl;

    A.resize(7, 6);
    cout << A << endl;

    return 0;
}
