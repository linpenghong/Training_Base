#include <iostream>
#include <functional>
#include <numeric>

#define N 5

using namespace std;

void display(const double A[])
{
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
};

int main()
{
    double A[N] = {1, 2, 3, 4, 5};
    double B[N];

    adjacent_difference(A, A + 5, B);
    display(B);

    adjacent_difference(A, A + 5, B, [](const double x, const double y)
                                     {
                                         return x + y;
                                     });
    display(B);

    return 0;
}
