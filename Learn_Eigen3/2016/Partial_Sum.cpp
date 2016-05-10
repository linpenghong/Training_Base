#include <iostream>
#include <numeric>

#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

int main()
{
    vec4 u(1, 2, 3, 4);
    vec4 v;

    partial_sum(u.data(), u.data() + u.size(), v.data());
    
    cout << u << endl << endl;
    cout << v << endl << endl;

    return 0;
}
