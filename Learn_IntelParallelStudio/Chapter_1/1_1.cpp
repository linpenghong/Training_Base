#include <cstdio>
#include <ctime>
#include <cilk/cilk.h> // cilk language, for Intel Parallelism
#include <cstdlib>

#include "tbb/scalable_allocator.h"

#define MALLOC_SIZE 1
#define ARRAY_SIZE 10000000

char* array[ARRAY_SIZE];

int main(int argc, char* argv[])
{
    clock_t start, stop;

    // get the start time
    start = clock();

    // load balance scalable malloc between avaible workers
    cilk_for(int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = (char*)scalable_malloc(MALLOC_SIZE);
    }

    // free the blocks of memory
    cilk_for(int i = 0; i < ARRAY_SIZE; i++)
    {
        scalable_free(array[i]);
    }

    // get the stop time
    stop = clock();

    // display the time taken
    printf("The time was %f seconds\n", (double)(stop - start) / 1000.0);

    return 0;
}
