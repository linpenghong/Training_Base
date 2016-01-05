#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    cout << "****** insert ******" << endl;
    mat A = randu<mat>(5, 10);
    mat B = ones<mat>(5, 2);

    cout << A << endl;
    A.insert_cols(2, B);
    cout << A << endl;

    cout << "****** shed ******" << endl;
    mat C = randu<mat>(5, 5);
    cout << C << endl;
    C.shed_row(2);
    cout << C << endl;
    C.shed_cols(2, 4);
    cout << C << endl;

    cout << "****** swap ******" << endl;
    mat D = randu<mat>(5, 5);
    cout << D << endl;
    D.swap_rows(0, 4);
    cout << D << endl;

    return 0;
}
