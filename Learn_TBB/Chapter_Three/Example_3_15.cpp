#include <iostream>

#include "tbb/parallel_reduce.h"
#include "tbb/blocked_range.h"

using namespace tbb;

struct Sum
{
    float value;

    Sum() : value(0) {}

    Sum(Sum& s, split) : value(0) {}

    void operator()(const blocked_range<float*>& range) // using pointer
    {
        for (float* a = range.begin(); a < range.end(); a++)
            value += *a;
    }

    void join(Sum& rhs)
    {
        value += rhs.value;
    }
};

float parallelSum(float a[], size_t n)
{
    Sum sum;

    parallel_reduce(blocked_range<float*>(a, a + n), sum, auto_partitioner());

    return sum.value;
}

int main(int argc, char* argv[])
{
    float a[1000];
    for (int i = 0; i < 1000; i++)
        a[i] = i;

    std::cout << parallelSum(a, 1000) << std::endl;
}
