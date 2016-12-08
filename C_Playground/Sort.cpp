#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    vector<double> a = {1, 2, 3, 4, 5};

    sort(&a[0], &a[0] + a.size(), [](const double x, const double y){ return x > y; });

    for (size_t i = 0; i < a.size(); i++)
        cout << a[i] << endl;
}
