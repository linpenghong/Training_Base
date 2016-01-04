#include <iostream>

#define CONJUGATE_HALF(iCol, iRow) \
    (((iCol) < 0) ? 0 : [&iCol, &iRow]() \
                        { \
                            iCol *= -1; \
                            iRow *= -1; \
                            return 1; \
                        }())

int main()
{
    int a = -5;
    std::cout << (0 ? 0 : [&a](){a *= -1; return 1;}()) << std::endl;
    std::cout << a << std::endl;
    
    int b = 5;
    std::cout << CONJUGATE_HALF(a, b) << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
}
