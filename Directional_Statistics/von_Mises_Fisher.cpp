#include <iostream>

#include <armadillo>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_sf_gamma.h>

#define N 10000

const static gsl_rng_type* RANDT = gsl_rng_default;
static gsl_rng* RANDR = gsl_rng_alloc(RANDT);

using namespace std;
using namespace arma;

mat33 S3_SO3(const vec4 u)
{
    mat33 A = {{0, -u(3), u(2)},
               {u(3), 0, -u(1)},
               {-u(2), u(1), 0}};
    return mat33(fill::eye) + 2 * u(0) * A + 2 * A * A;
};

double vonMisesFischer(const vec4 x,
                       const vec4 mu,
                       const double k)
{
    // return gsl_sf_bessel_I1(k);
    return k / 2 / gsl_sf_gamma(2) / gsl_sf_bessel_I1(k) * exp(k * dot(x, mu));
}
// p = 4 -> S3

void angle(double& phi,
           double& theta,
           double& psi,
           const mat33& src)
{
    theta = acos(src(2, 2));
    psi = acos(src(2, 1) / sin(theta));
    (src(2, 0) / sin(theta) > 0) ? : (psi = 2 * M_PI - psi);
    phi = acos(-src(1, 2) / sin(theta));
    (src(0, 2) / sin(theta) > 0) ? : (phi = 2 * M_PI - phi);
}

int main()
{
    vec4 mu = {1, 0, 0, 0};
    vec3 r0 = {1, 0, 0};

    /***
    cout << S3_SO3(vec4({1, 0, 0, 0})) << endl;
    cout << S3_SO3(vec4({0, 1, 0, 0})) << endl;
    cout << S3_SO3(vec4({0, 0, 1, 0})) << endl;
    cout << S3_SO3(vec4({0, 0, 0, 1})) << endl;
    ***/

    double kappa = 1;

    double x[4];

    double phi, theta, psi;

    for (int i = 0; i < N; i++)
    {
        gsl_ran_dir_nd(RANDR, 4, x);
        angle(phi, theta, psi, S3_SO3(vec4(x)));
        // printf("%f\n", norm(r));
        /***
        printf("%f %f %f %f\n",
               r(0),
               r(1),
               r(2),
               vonMisesFischer(vec4(x), mu, kappa));
               ***/
        printf("%f %f %f\n",
               phi,
               theta,
               vonMisesFischer(vec4(x), mu, kappa));
    }
}
