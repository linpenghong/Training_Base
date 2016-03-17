#include <cstdio>
#include <bingham.h>

#define N 100000

int main()
{
    bingham_t B;
    double v1[4] = {0, 1, 0, 0};
    double v2[4] = {0, 0, 1, 0};
    double v3[4] = {0, 0, 0, 1};
    bingham_new_S3(&B, v1, v2, v3, -2, -1, 0);
    // bingham_new_uniform(&B, 4);

    // sample
    double** X = new_matrix2(N, 4);
    bingham_sample(X, &B, N);
    /***
    for (int i = 0; i < N; i++)
        printf("%f %f %f %f\n",
               X[i][0],
               X[i][1],
               X[i][2],
               X[i][3]);
               ***/

    bingham_free(&B);

    // fit
    bingham_fit(&B, X, N, 4);

    printf("k1 = %f\n", B.Z[0]);
    printf("k2 = %f\n", B.Z[1]);
    printf("k3 = %f\n", B.Z[2]);

    free_matrix2(X);

    bingham_free(&B);

    return 0;
}
