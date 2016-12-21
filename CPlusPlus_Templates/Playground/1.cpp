#include <iostream>

struct A {};
struct B {};

inline double foo(const double i,
                  const double j,
                  const A& type)
{
    return i + j;
};

inline double foo(const double i,
                  const double j,
                  const B& type)
{
    return i - j;
};

template<typename T>
inline double fooGet(const double i,
                     const double j)
{
    T type;
    return foo(i, j, type);
};

int main()
{
    double i = 1.5;
    double j = 0.5;

    std::cout << fooGet<A>(i, j) << std::endl;
    std::cout << fooGet<B>(i, j) << std::endl;

    return 0;
}
