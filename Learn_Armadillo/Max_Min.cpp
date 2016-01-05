#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    vec v = randu<vec>(10);

    cout << "min value is " << v.min() << endl;

    // uword is the shorthand of unsigned integer
    uword index;
    double min_val = v.min(index);
    cout << "index of min value is " << index << endl;

    mat A = randu<mat>(5, 5);

    uword row;
    uword col;

    double max_val = A.max(row, col);

    cout << "max value is at " << row << ", " << col << endl;

    return 0;
}
