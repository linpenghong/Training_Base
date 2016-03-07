#include <iostream>

#include <armadillo>

using namespace arma;
using namespace std;

int main()
{
    vec3 vec = {1, 2, 3};
    vec.tail(2);
    cout << norm(vec.tail(2)) << endl;

    return 0;
}
