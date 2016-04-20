#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>

typedef gsl_complex Complex;

inline Complex operator+(Complex a, Complex b)
{
    return gsl_complex_add(a, b);
};

// Complex operator+(const Complex a, const Complex b);
