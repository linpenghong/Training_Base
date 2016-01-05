#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat A = zeros<mat>(5, 10);
    cout << A << endl;

    // submat(first_row, first_col, last_row, last_col)
    A.submat(0, 1, 2, 3) = randu<mat>(3, 3);
    cout << A << endl;

    A.zeros();
    A(span(0, 2), span(1, 3)) = randu<mat>(3, 3);
    cout << A << endl;

    A.zeros();
    // (first_row, first_col, size_of_submatrix)
    A(0, 1, size(3, 3)) = randu<mat>(3, 3);
    cout << A << endl;

    A.zeros();
    A.col(1) = randu<mat>(5, 1);
    cout << A << endl;

    A.zeros();
    A(span::all, 1) = randu<mat>(5, 1);
    cout << A << endl;

    mat X = randu<mat>(5, 5);
    vec q = X.elem(find(X > 0.5));
    cout << q << endl;

    vec a(10, fill::randu);
    a.tail(5) += 123;
    cout << a << endl;

    X.col(2).head(3) += 123;
    cout << X << endl;

    return 0;
}
