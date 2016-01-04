#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat A(5, 10, fill::zeros);
    cout << A << endl;

    mat B; B.zeros(4, 4);
    cout << B << endl;

    mat C; C.zeros(size(B));
    cout << C << endl;

    // ones is similiar to zeros

    return 0;
}
