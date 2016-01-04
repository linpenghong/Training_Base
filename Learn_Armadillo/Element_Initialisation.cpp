#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    vec v = {1, 2, 3};
    cout << v << endl;

    mat A = {{1, 3, 5}, {2, 4, 6}}; // row by row
    cout << A << endl;

    return 0;
}
