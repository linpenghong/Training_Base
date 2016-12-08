#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

int main()
{
    vector<double> a = {1, 2, 3, 4, 5};

    vector<double> b(a.size());
    partial_sum(&a[0], &a[0] + a.size(), &b[0]);

    for (int i = 0; i < (int)a.size(); i++)
        cout << b[i] << endl;
}
