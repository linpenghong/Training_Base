#include <cstdlib>

#include "inline.h"

/***
Complex operator+(const Complex a, const Complex b)
{
    return gsl_complex_add(a, b);
}
***/

int main(int argc, char* argv[])
{
    int n = atoi(argv[1]);
    Complex* a = new Complex[n];
    Complex* b = new Complex[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = gsl_complex_rect(i, i);
        b[i] = gsl_complex_rect(i, i);
    }

    Complex c;
    for (int i = 0; i < n; i++)
    {
        c = a[i] + b[i];
        // c = gsl_complex_add(a[i], b[i]);
    }

    return 0;
}
