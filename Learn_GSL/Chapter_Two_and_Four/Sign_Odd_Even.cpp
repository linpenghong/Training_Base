#include <iostream>

#include <gsl/gsl_math.h>

int main()
{
    std::cout << GSL_SIGN(-10) << std::endl;
    std::cout << GSL_SIGN(0) << std::endl;
    std::cout << GSL_SIGN(10) << std::endl;

    std::cout << GSL_IS_ODD(2) << std::endl;
    std::cout << GSL_IS_EVEN(2) << std::endl;
    std::cout << GSL_IS_ODD(3) << std::endl;
    std::cout << GSL_IS_EVEN(3) << std::endl;

    std::cout << gsl_fcmp(1.0, 2.0, 0.0001) << std::endl;

    return 0;
}
