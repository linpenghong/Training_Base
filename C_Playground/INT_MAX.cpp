#include <cmath>

#include <iostream>
#include <climits>

using namespace std;

#define MPI_MAX_BUF 2000000000

int main()
{
    cout << "391 x 780 x 780 = " << 381 * 760 * 760 << endl;
    cout << "2 ^ 31 = " << pow(2, 31) << endl;
    cout << "INT_MAX = " << INT_MAX << endl;
    cout << "INT_MAX = " << (double)INT_MAX / (1e9) << "Gb" << endl;

    size_t count = 220065600;
    int dataTypeSize = 16;
    int nBlock = (count - 1) / (MPI_MAX_BUF / dataTypeSize) + 1;
    cout << "nBlock = " << nBlock << endl;

    long long ptr = 0;
    //ptr += MPI_MAX_BUF * 5;
    for (int i = 0; i < 5; i++)
    {
        ptr += MPI_MAX_BUF;
        cout << ptr << endl;
    }

    return 0;
}
