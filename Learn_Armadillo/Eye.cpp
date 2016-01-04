#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat A(5, 5, fill::eye);
    cout << A << endl;

    mat B; B.eye(5, 5);
    cout << B << endl;

    mat C; C.eye(size(B));
    cout << C << endl;

    return 0;
}
