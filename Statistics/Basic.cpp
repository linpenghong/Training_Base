#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
    mat A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << A << endl;

    cout << mean(A) << endl; // mean of each column
    cout << stddev(A) << endl; // standard deviation of each column

    return 0;
}
