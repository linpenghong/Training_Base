#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat A(5, 5, fill::randu);
    cout << A << endl;

    mat22 B("1 0; 0 1");
    cout << B << endl;

    mat33 C(fill::eye);
    cout << C << endl;

    mat33 D = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << D << endl;

    mat E(4, 5);

    return 0;
}
