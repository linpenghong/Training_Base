#include <cstdio>
#include <mutex>

#include "Typedef.h"
#include "Complex.h"

using namespace std;

#define N 500

static Complex cpx[N];
static mutex mtx[N];

void atomic_add(const Complex x,
                const int i)
{
    mtx[i].lock();
    cpx[i] += x;
    mtx[i].unlock();
}

int main()
{
    for (int i = 0; i < N; i++)
        cpx[i] = COMPLEX(0, 0);

    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < N * 100; i++)
        atomic_add(COMPLEX(1, 1), i % N);

    printf("Real = %12f, Imag = %12f\n",
           REAL(cpx[0]),
           IMAG(cpx[0]));

    return 0;
}
