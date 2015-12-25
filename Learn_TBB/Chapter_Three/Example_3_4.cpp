#include <iostream>

#include "tbb/blocked_range.h"
#include "tbb/parallel_for.h"

#define SIZE 50

using namespace tbb;

void foo(float x);
void parallelApplyFoo(float a[], size_t n);

class ApplyFoo
{
    private:

        float* const my_a;

    public:

        void operator()(const blocked_range<size_t>& r) const
        {
            float* a = my_a;
            for (size_t i = r.begin(); i < r.end(); i++)
                foo(a[i]);
        }

        ApplyFoo(float a[]) : my_a(a) {}
};

void foo(float x)
{
    std::cout << x << std::endl;
}

void parallelApplyFoo(float a[], size_t n)
{
    parallel_for(blocked_range<size_t>(0, n, SIZE), ApplyFoo(a));
}

int main(int argc, char* argv[])
{
    float a[100];
    for (int i = 0; i < 100; i++)
        a[i] = i;

    parallelApplyFoo(a, 100);
}
