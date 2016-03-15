#include <iostream>
#include <cmath>

using namespace std;

int periodic(double& x,
             const double p)
{
    int n = floor(x / p);
    x -= n * p;
    return n;
};

int main()
{
    cout << fmod(-0.1, 2) << endl;
    cout << fmod(2.1, 2) << endl;

    double x = 1.5;
    cout << periodic(x, 1.2) << endl;
    cout << x << endl;

    x = -1.5;
    cout << periodic(x, 1.2) << endl;

    return 0;
}
