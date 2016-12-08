#include <iostream>
#include <string>

#include "max.hpp"

using namespace std;

int main()
{
    int i = 7;
    int j = 42;

    cout << "max(i, j): " << ::max(i, j) << endl;

    cout << "max(i, j): " << ::max<int>(i, j) << endl;

    double f1 = 3.4;
    double f2 = -6.7;

    cout << "max(f1, f2): " << ::max(f1, f2) << endl;
    cout << "max(f1, f2): " << ::max<double>(f1, f2) << endl;

    string s1 = "mathematics";
    string s2 = "math";

    cout << "max(s1, s2): " << ::max(s1, s2) << endl;
    cout << "max(s1, s2): " << ::max<string>(s1, s2) << endl;

    return 0;
}
