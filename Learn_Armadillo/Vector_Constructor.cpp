#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    vec3 A("1 2 3");
    cout << A << endl;

    vec B = zeros<vec>(10);
    cout << B << endl;

    rowvec3 C("1 2 3");
    cout << C << endl;

    return 0;
}
