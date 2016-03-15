#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    auto func = [](){cout << "Hello World!" << std::endl;};
    func();
}
