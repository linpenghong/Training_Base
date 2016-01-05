#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    vec a = randu<vec>(10);
    vec b = sort(a);

    cout << a.is_sorted() << endl;
    cout << b.is_sorted() << endl;

    mat A = randu<mat>(10, 10);

    // check whether each column is sorted in descending order
    cout << A.is_sorted("descend") << endl;

    // check whether each row is sorted in ascending order
    cout << A.is_sorted("ascend", 1) << endl;

    return 0;
}
