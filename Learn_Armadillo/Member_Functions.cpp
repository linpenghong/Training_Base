#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat X(4, 5);

    cout << "X has " << X.n_rows << " rows" << endl;
    cout << "X has " << X.n_cols << " columns" << endl;

    mat A = randu<mat>(5, 10);
    mat B = randu<mat>(5, 10);
    mat C = randu<mat>(10, 5);

    cout << "A = " << endl << A << endl;
    cout << "B = " << endl << B << endl;
    cout << "C = " << endl << C << endl;

    mat P = A + B; cout << "P = " << endl << P << endl;
    mat Q = A - B; cout << "Q = " << endl << Q << endl;
    mat R = -B; cout << "R = " << endl << R << endl;

    // element wise division
    mat S = A / 123; cout << "S = " << endl << S << endl;

    // element wise multiplication
    mat T = A % B; cout << "T = " << endl << T << endl;

    // matrix multiplication
    mat U = A * C; cout << "U = " << endl << U << endl;

    umat Z = (A >= B);
    cout << "Z = " << endl << Z << endl;

    return 0;
}
