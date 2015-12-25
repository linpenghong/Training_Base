#include <iostream>
#include <cfloat>

#include "tbb/parallel_reduce.h"
#include "tbb/blocked_range.h"

using namespace tbb;

class Sum
{
    public:

        const float* my_a;

    public:

        float sum;

        void operator()(const blocked_range<size_t>& r)
        {
            const float* a = my_a;
            for (size_t i = r.begin(); i < r.end(); i++)
                sum += a[i];
        }

        Sum(Sum& x, split) : my_a(x.my_a), sum(0) {}

        void join(const Sum& y)
        {
            sum += y.sum;
        }

        Sum(const float a[]) : my_a(a), sum(0) {}
};

class Min
{
    public:

        const float* my_a;

    public:

        float min;
        long indexOfMin;

        void operator()(const blocked_range<size_t>& r)
        {
            const float* a = my_a;

            for (size_t i = r.begin(); i < r.end(); i++)
            {
                float value = a[i];
                if (value < min)
                {
                    min = value;
                    indexOfMin = i;
                }
            }
        }

        Min(const Min& x, split)
            : my_a(x.my_a),
              min(FLT_MAX),
              indexOfMin(-1) {}

        void join(const Min& y)
        {
            if (y.min < min)
            {
                min = y.min;
                indexOfMin = y.indexOfMin;
            }
        }

        Min(const float a[])
            : my_a(a),
              min(FLT_MAX),
              indexOfMin(-1) {}
};

float parallelSum(const float a[], size_t n)
{
    Sum s(a);

    parallel_reduce(blocked_range<size_t>(0, n, 10), s);

    return s.sum;
};

long parallelMinIndex(const float a[], size_t n)
{
    Min m(a);

    parallel_reduce(blocked_range<size_t>(0, n, 10), m);

    return m.indexOfMin;
}

int main(int argc, char* argv[])
{
    float input[100];
    for (int i = 0; i < 100; i++)
        input[i] = i;

    std::cout << parallelSum(input, 100) << std::endl;
    std::cout << parallelMinIndex(input, 100) << std::endl;

    return 0;
}
