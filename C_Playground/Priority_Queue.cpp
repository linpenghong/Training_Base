#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct Sp
{
    double _w;
    int _iR;
    int _iT;

    Sp() {};

    Sp(const double w,
       const int iR,
       const int iT)
    {
        _w = w;
        _iR = iR;
        _iT = iT;
    };
};

auto cmpSp = [](const Sp a, const Sp b){ return a._w > b._w; };

void display(priority_queue<Sp, vector<Sp>, decltype(cmpSp)> q)
{
    while (!q.empty())
    {
        cout << q.top()._w << " "
             << q.top()._iR << " "
             << q.top()._iT << endl;
        q.pop();
    }
}

int main()
{
    Sp a[3] = {{0.5, 1, 1},
               {0.6, 2, 2},
               {0.7, 3, 3}};

    priority_queue<Sp, vector<Sp>, decltype(cmpSp)> q(cmpSp);

    for (int i = 0; i < 3; i++)
        q.push(a[i]);

    display(q);

    return 0;
}
