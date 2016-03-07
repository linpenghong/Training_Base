#include <iostream>
#include <armadillo>

static const double a[] = {1, 2, 3};

using namespace std;
using namespace arma;

int main()
{
    vec3 A(a);

    cout << A << endl;

    return 0;
}
