#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat X = randu<mat>(5, 5);
    cout << X << endl;

    vec a = X.diag();
    cout << a << endl;
    vec b = X.diag(1);
    cout << b << endl;
    vec c = X.diag(-2);
    cout << c << endl;

    X.diag() = randu<vec>(5);
    cout << X << endl;
    X.diag() += 6;
    cout << X << endl;
    X.diag().ones();
    cout << X << endl;
    X.diag() = vec("1, 2, 3, 4, 5");
    cout << X << endl;

    return 0;
}
