#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// maximum of two values of any type
template<typename T>
inline T const& max(T const& a, T const& b)
{
    return a < b ? b : a;
}

// maximum of two pointers
template<typename T>
inline T* const& max(T* const& a, T* const& b)
{
    return *a < *b ? b : a;
}

// maximum of two C-strings
inline char const* const& max(char const* const& a,
                              char const* const& b)
{
    return strcmp(a, b) < 0 ? b : a;
}

int main()
{
    int a = 7;
    int b = 42;

    cout << ::max(a, b) << endl; // max() for two values of type int

    string s = "hey";
    string t = "you";

    cout << ::max(s, t) << endl; // max() for two values of type string

    int* p1 = &a;
    int* p2 = &b;

    cout << *::max(p1, p2) << endl; // max() for two pointers

    const char* const s1 = "David";
    const char* const s2 = "Nico";

    cout << ::max(s1, s2) << endl; // max() for two C-strings

    return 0;
}
