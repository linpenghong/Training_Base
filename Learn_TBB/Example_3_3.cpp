#include <iostream>

#include "tbb/blocked_range.h"

using namespace tbb;

void foo(float x);

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

int main(int argc, char* argv[])
{
    return 0;
}
