#include <iostream>
#include <functional>
#include <numeric>

#define N 5

using namespace std;

int main()
{
    double A[N] = {1, 2, 3, 4, 5};
    double B[N] = {6, 7, 8, 9, 10};

    cout << inner_product(A, A + N, B, 0) << endl;

    // inner_product(A, A + N, B, init, op1, op2)
    // op1 -> "+" of inner product
    // op2 -> "*" of inner product
    cout << inner_product(A,
                          A + N,
                          B,
                          0,
                          [](const double x, const double y)
                          { return x + y; },
                          [](const double x, const double y)
                          { return x * y; }) << endl;

    cout << inner_product(A,
                          A + N,
                          B,
                          0,
                          [](const double x, const double y)
                          { return x - y; },
                          [](const double x, const double y)
                          { return x + y; }) << endl;
    // 0 - (1 + 6) - (2 + 7) - (3 + 8) - (4 + 9) -(5 + 10) = -55

    return 0;
}
