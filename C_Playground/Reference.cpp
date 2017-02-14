#include <iostream>
#include <numeric>
#include <vector>

#define N 10

using namespace std;

int main()
{
    vector<int> a = {1, 2, 3};

    for (int i = 0; i < 3; i++)
        cout << a[i] << " ";
    cout << endl;

    int& b = a[0];

    b = 4;

    for (int i = 0; i < 3; i++)
        cout << a[i] << " ";
    cout << endl;

    vector<int*> c;

    return 0;
}
