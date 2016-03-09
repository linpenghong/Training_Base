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

    return 0;
}
