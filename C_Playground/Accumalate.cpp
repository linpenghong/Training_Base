#include <iostream>
#include <functional>
#include <numeric>

#define N 5

using namespace std;

int main()
{
    double A[N] = {1, 2, 3, 4, 5};
    double B[N];

    cout << accumulate(A, A + N, 0, plus<double>()) << endl;
    cout << accumulate(A, A + N, 0, [](double x, double y){return x + y;}) << endl;

    return 0;
}
