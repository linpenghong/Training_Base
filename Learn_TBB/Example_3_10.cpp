#include <iostream>

#include "tbb/parallel_reduce.h"
#include "tbb/blocked_range.h"

using namespace tbb;

class Sum
{
    public:

        float* my_a;

    public:

        float sum;

        void operator()(const blocked_range<size_t>& r)
        {
            float* a = my_a;
            for (size_t i = r.begin(); i < r.end(); i++)
                sum += a[i];
        }

        Sum(Sum& x, split) : my_a(x.my_a), sum(0) {}

        void join(const Sum& y)
        {
            sum += y.sum;
        }

        Sum(float a[]) : my_a(a), sum(0) {}
};

float parallelSum(float a[], size_t n)
{
    Sum s(a);

    parallel_reduce(blocked_range<size_t>(0, n, 10), s);

    return s.sum;
};

int main(int argc, char* argv[])
{
    float input[100];
    for (int i = 0; i < 100; i++)
        input[i] = i;

    std::cout << parallelSum(input, 100) << std::endl;

    return 0;
}
