#include "tbb/parallel_reduce.h"
#include "tbb/blocked_range.h"

using namespace tbb;

struct TrivialIntegerRange
{
    int lower;
    int upper;
    
    bool empty() const
    {
        return lower == upper;
    }

    bool is_divisible() const
    {
        return upper > lower + 1;
    }

    TrivialIntegerRange() {}

    TrivialIntegerRange(int l, int u)
    {
        lower = l;
        upper = u;
    }

    TrivialIntegerRange(TrivialIntegerRange& r, split)
    {
        int m = (r.lower + r.upper) / 2;
        lower = m;
        upper = r.upper;
        r.upper = m;
    }
};

int main(int argc, char* argv[])
{
    TrivialIntegerRange tir;
    tir.lower = 0;
    tir.upper = 100;

    return 0;
}
