#include <iostream>

using namespace std;

inline int const& max(int const& a, int const& b)
{
    return a < b ? b : a;
}

template<typename T>
inline T const& max(T const& a, T const& b)
{
    return a < b ? b : a;
}

template<typename T>
inline T const& max(T const& a,
                    T const& b,
                    T const& c)
{
    return max(max(a, b), c);
}

int main()
{
    cout << ::max(7, 42, 68) << endl; // template for three arguments
    cout << ::max(7.0, 42.0) << endl; // template for two arguments
    cout << ::max('a', 'b') << endl; // template for two arguments

    cout << ::max(7, 42) << endl; // non-template
    cout << ::max<>(7, 42) << endl; // template for two arguments
    cout << ::max<double>(7, 42) << endl; // template for two arguments

    return 0;
}
