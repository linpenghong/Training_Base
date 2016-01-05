#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat X = randu<mat>(5, 5);

    mat::iterator a = X.begin();
    mat::iterator b = X.end();

    for (mat::iterator i = a; i != b; ++i)
        cout << *i << endl;

    mat::col_iterator c = X.begin_col(1);
    mat::col_iterator d = X.end_col(3);

    for (mat::col_iterator i = c; i !=d; i++)
    {
        cout << *i << endl;
        (*i) = 123;
    }
    cout << X << endl;

    return 0;
}
