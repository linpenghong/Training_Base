#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    vec A = randu<vec>(20);
    cout << A << endl;

    uvec B = find(A > 0.2, 1);
    cout << B(0) << endl;

    cout << uvec(find(A > 0.2, 1))(0) << endl;

    return 0;
}
