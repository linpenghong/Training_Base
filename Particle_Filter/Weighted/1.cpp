#include <iostream>

#include <armadillo>

#include <gsl/gsl_math.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

#define N 10000
#define K 50

const static gsl_rng_type* RANDT = gsl_rng_default;
static gsl_rng* RANDR = gsl_rng_alloc(RANDT);

using namespace std;
using namespace arma;

class Particle
{
    private:

        int _n;

        mat _p;
        vec _w;

    public:

        Particle(const int n)
        {
            init(N);
        };

        void init(const int n)
        {
            _n = n;

            _p.resize(_n, 2);
            _w.resize(_n);

            for (int i = 0; i < _n; i++)
            {
                _p(i, 0) = gsl_ran_flat(RANDR, -100, 100);
                _p(i, 1) = gsl_ran_flat(RANDR, -100, 100);
                _w(i) = 1.0 / N;
            }
        };

        int n() const
        {
            return _n;
        }

        void coord(double& x,
                   double& y,
                   const int i) const
        {
            x = _p(i, 0);
            y = _p(i, 1);
        }

        double x() const
        {
            return dot(_w, _p.col(0).t());
        }

        double y() const
        {
            return dot(_w, _p.col(1).t());
        }

        void mulW(const double w,
                  const int i)
        {
            _w(i) *= w;
        };

        void normW()
        {
            _w /= sum(_w);
        }

        mat22 sigma()
        {
            double m[2] = {mean(_p.col(0)),
                           mean(_p.col(1))};

            mat22 Q;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                {
                    double q = 0;
                    for (int k = 0; k < _n; k++)
                        q += _w(k)
                           * (_p(k, i) - m[i])
                           * (_p(k, j) - m[j]);
                    Q(i, j) = q / (1 - dot(_w, _w));
                }
            return Q;
        }

        void perturb()
        {
            mat22 Q = sigma();
            // mat Q = cov(_p);
            mat22 L = chol(Q, "lower");
            for (int i = 0; i < _n; i++)
                _p.row(i) += (L * randn<vec>(2)).t() / 3;
        };

        void resample()
        {
            vec cdf = cumsum(_w);

            double u0 = gsl_ran_flat(RANDR, 0, 1.0 / _n);

            mat p(_n, 2);

            int i = 0;
            for (int j = 0; j < _n; j++)
            {
                double uj = u0 + j * 1.0 / _n;

                while (uj > cdf[i])
                    i++;

                p.row(j) = _p.row(i);
                _w(j) = 1.0 / _n;
            }

            _p = p;

            perturb();
        };

        double neff() const
        {
            return 1.0 / gsl_pow_2(norm(_w, 2));
        };
};

void display(const Particle& particle)
{
    double x, y;
    for (int i = 0; i < particle.n(); i++)
    {
        particle.coord(x, y, i);
        printf("%f %f\n", x, y);
    }
};

double f(const double x,
         const double y)
{
    /***
    return sin(x) * sin(y / 10);
    ***/
    return gsl_ran_bivariate_gaussian_pdf(x - 50, y - 50, 1, 2, 0.5);
}

int main()
{
    Particle particle(N);

    for (int i = 0; i < K; i++)
    {
        /***
        printf("True Value: \nx = %12f, y = %12f\n",
               50,
               50);
        printf("Estimate:   \nx = %12f, y = %12f\n",
               particle.x(),
               particle.y()); 
        printf("Error:      \nx = %12f, y = %12f\n",
               abs(particle.x() - 50),
               abs(particle.y() - 50));
        ***/
        // cout << particle.sigma() << endl;
        printf("%f, %f\n",
               abs(particle.x() - 50),
               abs(particle.y() - 50));

        double x, y;
        for (int j = 0; j < particle.n(); j++)
        {
            particle.coord(x, y, j);
            particle.mulW(f(x, y), j);
        }
        particle.normW();

        // cout << particle.neff() << endl;

        if (particle.neff() < N / 3)
            particle.resample();
        else
            particle.perturb();
    }

    // display(particle);

    return 0;
}
