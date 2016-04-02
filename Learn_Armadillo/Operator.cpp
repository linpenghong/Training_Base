#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    vec A = ones<vec>(5);
    cout << A << endl;

    cout << 1 + A << endl;

    cout << A / (1 + A) << endl;

    mat B = ones<mat>(5, 5);
    mat C;
    C.copy_size(B);

    C.col(0) = B.col(0) / (1 + B.col(0));

    cout << C << endl;

    return 0;
}
