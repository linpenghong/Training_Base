#include <iostream>
#include <cstdio>
#include <cstdlib>

typedef int (*PFun)(int a, int b);

int add(int a, int b)
{
    return (a + b);
}

void fun(int a, int b, PFun pFun)
{
    std::cout << pFun(a, b) << std::endl;
}

int main(int argc, char* argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    fun(a, b, add);

    return 0;
}
