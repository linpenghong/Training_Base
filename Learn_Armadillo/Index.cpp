#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    vec A(5, fill::ones);
    cout << A << endl;

    // cout << A(-1) << endl;

    cout << A.size() << endl;

    return 0;
}
