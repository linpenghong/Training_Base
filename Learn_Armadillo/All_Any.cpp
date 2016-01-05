#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat X = randu<mat>(5, 5);
    cout << X << endl;

    // each column
    cout << all(X > 0.5) << endl;

    // each column
    cout << any(X > 0.5) << endl;

    return 0;
}
