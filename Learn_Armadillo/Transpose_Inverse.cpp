#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    cout << "****** transpose ******" << endl;

    mat A = randu<mat>(4, 5);
    cout << A << endl;

    mat B = A.t();
    cout << B << endl;

    cout << "****** inverse ******" << endl;

    mat C = randu<mat>(4, 4);
    cout << C << endl;
    mat X = C.i();
    cout << X << endl;

    return 0;
}
