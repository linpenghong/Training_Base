#include <cstdio>
#include <cstdlib>

#include <immintrin.h>

int main()
{
    float* aligned_floats;
    
    posix_memalign((void**)&aligned_floats, 32, 64 * sizeof(float));

    for (int i = 0; i < 64; i++)
        aligned_floats[i] = i;

    __m256 vec = _mm256_load_ps(aligned_floats);

    float* f = (float*)&vec;

    printf("%f %f %f %f %f %f %f %f\n",
           f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);

    return 0;
}
