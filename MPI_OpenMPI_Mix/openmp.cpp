#include <cstdio>

#include <omp.h>

int main(int argc, char* argv[])
{
    int rank = 0;
    int size = 1;

    #pragma omp parallel default(shared) private(rank, size)
    {
        #if defined (_OPENMP)
        rank = omp_get_thread_num();
        size = omp_get_num_threads();
        #endif
        printf("Hello from thread %d out of %d\n", rank, size);
    }
    
    return 0;
}
