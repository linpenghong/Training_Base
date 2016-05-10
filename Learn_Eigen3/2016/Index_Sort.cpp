#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>

#include <Eigen/Dense>

#include "Typedef.h"

using namespace Eigen;
using namespace std;

uvec index_sort_ascend(const vec& v)
{
    uvec idx(v.size());

    for (unsigned int i = 0; i < idx.size(); i++)
        idx(i) = i;

    sort(idx.data(),
         idx.data() + idx.size(),
         [&v](unsigned int i, unsigned int j){ return v(i) < v(j); });

    return idx;
}

uvec index_sort_descend(const vec& v)
{
    uvec idx(v.size());

    for (unsigned int i = 0; i < idx.size(); i++)
        idx(i) = i;

    sort(idx.data(),
         idx.data() + idx.size(),
         [&v](unsigned int i, unsigned int j){ return v(i) > v(j); });

    return idx;
}

int main()
{
    vec v(10);
    v << 10, 9, 8, 7, 6, 5, 4, 3, 2, 1;

    cout << v << endl << endl;

    uvec idx = index_sort_ascend(v);
    cout << idx << endl << endl;

    idx = index_sort_descend(v);
    cout << idx << endl << endl;

    return 0;
}
