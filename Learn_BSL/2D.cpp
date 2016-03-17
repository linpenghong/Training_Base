#include <cstdio>
#include <bingham.h>
#include <armadillo>

#define N 100000

using namespace std;
using namespace arma;

void angle(double& phi,
           double& theta,
           const vec3& src)
{
    theta = acos(src(2));
    phi = acos(src(0) / sin(theta));
    (src(1) / sin(theta) > 0) ? : (phi = 2 * M_PI - phi);
};

int main(int argc, char* argv[])
{
    bingham_t B;

    double k1 = atoi(argv[1]);
    double k2 = atoi(argv[2]);

    double v1[3] = {0, 1, 0};
    double v2[3] = {0, 0, 1};
    bingham_new_S2(&B, v1, v2, k1, k2);
    // bingham_new_uniform(&B, 3);

    // sample
    double** X = new_matrix2(N, 3);
    bingham_sample(X, &B, N);
    double phi, theta;
    for (int i = 0; i < N; i++)
    {
        angle(phi, theta, vec3({X[i][0],
                                X[i][1],
                                X[i][2]}));
        printf("%f %f\n", phi, theta);
    }

    free_matrix2(X);

    bingham_free(&B);

    return 0;
}
