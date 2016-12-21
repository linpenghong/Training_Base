#include <iostream>
#include <cstdlib>

#include <omp.h>

using namespace std;

int main(int argc, char* argv[])
{
    omp_set_num_threads(4);

    cout << "Num of Threads: " << omp_get_max_threads() << endl;

    double a[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                    11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    double maxV = 0;

    #pragma omp parallel for reduction(max:maxV)
    for (int i = 0; i < 20; i++)
    {
        maxV = (maxV > a[i]) ? maxV : a[i];
    }

    cout << "max = " << maxV << endl;

    return 0;
}
