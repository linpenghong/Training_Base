#include <iostream>
#include <cstdlib>

#include <omp.h>

using namespace std;

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);

    cout << "Num of Threads: " << omp_get_num_threads() << endl;

    #pragma omp parallel
    {
        printf("Hello, World!, ThreadID = %d\n", omp_get_thread_num());
    }

    return 0;
}
