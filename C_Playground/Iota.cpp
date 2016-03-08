#include <iostream>
#include <numeric>

#define N 10

using namespace std;

int main()
{
    int A[N];
    iota(A, A + N, 100);

    for (int& i:A) cout << i << ' ';
    cout << endl;

    return 0;
}
