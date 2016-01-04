#include <iostream>

#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>

int main()
{
    gsl_complex c1;
    GSL_SET_COMPLEX(&c1, 3, 4);

    std::cout << gsl_complex_abs(c1) << std::endl;

    return 0;
}
