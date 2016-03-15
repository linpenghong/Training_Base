#include <iostream>
#include <functional>

using namespace std;

using namespace placeholders;

double my_divide(const double x,
                 const double y)
{
    return x/y;
};

int main()
{
    auto fn_five = bind(my_divide, 10, 2); // 10 / 2
    cout << fn_five() << endl;

    auto fn_half = bind(my_divide, _1, 2); // x / 2
    cout << fn_half(10) << endl;

    auto fn_invert = bind(my_divide, _2, _1); // y / x
    cout << fn_invert(10, 2) << endl;

    auto fn_rounding = bind<int>(my_divide, _1, _2); // int(y / x)
    cout << fn_rounding(10, 3) << endl;
}
