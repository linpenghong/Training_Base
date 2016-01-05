#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat A = randu<mat>(4, 5);

    cout << A.in_range(0, 0) << endl;
    cout << A.in_range(3, 4) << endl;
    cout << A.in_range(4, 5) << endl;

    return 0;
}
