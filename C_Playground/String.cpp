#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a = "abcd.mrc";

    cout << a.rfind('.') << endl;

    cout << a.substr(0, a.rfind('.') - 1) << endl;

    cout << a.substr(0, a.rfind('.') - 1) + "_stack.mrc" << endl;
}
