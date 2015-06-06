#include <iostream>

#include "tbb/parallel_for.h"
#include "tbb/blocked_range.h"

using namespace tbb;

struct Average
{
    float* input;
    float* output;

    void operator()(const blocked_range<int>& range) const
    {
        for (int i = range.begin(); i < range.end(); i++)
            output[i] = (input[i - 1]
                       + input[i]
                       + input[i + 1]) * (1 / 3.0f);
    }
};

void parallelAverage(float* output, float* input, size_t n)
{
    Average avg;
    avg.input = input;
    avg.output = output;

    parallel_for(blocked_range<int>(0, n), avg, auto_partitioner());
}

int main(int argc, char* argv[])
{
    float input[100];
    for (int i = 0; i < 100; i++)
        input[i] = i * i;

    float output[100];

    parallelAverage(output, input, 100);
    
    for (int i = 0; i < 100; i++)
        std::cout << output[i] << std::endl;

    return 0;
}
