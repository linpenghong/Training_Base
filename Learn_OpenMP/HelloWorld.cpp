#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    #pragma omp parallel num_threads(4)
    {
        printf("Hello, World!, ThreadID = %d\n", omp_get_thread_num());
    }

    return 0;
}
