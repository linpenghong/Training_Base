#include <cstdio>

#include <gsl/gsl_sf_bessel.h>

#include "Relion_Bessel.h"

int main(void)
{
    double y;

    for (double x = 1; x < 20; x++)
    { 
        printf("x = %g\n", x);

        y = gsl_sf_bessel_J0(x);
        printf("J0(%g) = %.18e\n", x, y);

        y = gsl_sf_bessel_Y0(x);
        printf("Y0(%g) = %.18e\n", x, y);

        y = gsl_sf_bessel_I0(x);
        printf("Y0(%g) = %.18e\n", x, y);

        y = gsl_sf_bessel_K0(x);
        printf("K0(%g) = %.18e\n", x, y);

        y = gsl_sf_bessel_j0(x);
        printf("j0(%g) = %.18e\n", x, y);

        y = gsl_sf_bessel_y0(x);
        printf("y0(%g) = %.18e\n", x, y);

        y = bessj0(x);
        printf("bessj0(%g) = %.18e\n", x, y);
    }

    for (double x = 1; x < 20; x++)
    {
        y = gsl_sf_bessel_I0(x);
        printf("I0(%g) = %.18e\n", x, y);

        y = bessi0(x);
        printf("bessi0(%g) = %.18e\n", x, y);

        y = gsl_sf_bessel_I1(x);
        printf("I1(%g) = %.18e\n", x, y);

        y = bessi1(x);
        printf("bessi1(%g) = %.18e\n", x, y);

        y = gsl_sf_bessel_In(2, x);
        printf("I2(%g) = %.18e\n", x, y);

        y = bessi2(x);
        printf("bessi2(%g) = %.18e\n", x, y);

        y = gsl_sf_bessel_In(3, x);
        printf("I3(%g) = %.18e\n", x, y);

        y = bessi3(x);
        printf("bessi3(%g) = %.18e\n", x, y);
        
        y = gsl_sf_bessel_In(4, x);
        printf("I4(%g) = %.18e\n", x, y);

        y = bessi4(x);
        printf("bessi4(%g) = %.18e\n", x, y);
    }

    for (int m = 0; m <= 4; m++)
    {
        y = gsl_sf_bessel_In(4, 0);
        printf("I%d(%g) = %.18e\n", m, 0, y);
    }

    return 0;
}
