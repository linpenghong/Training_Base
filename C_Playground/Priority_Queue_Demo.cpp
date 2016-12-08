#include <iostream>
#include <queue>

using namespace std;

void display(priority_queue<int> q)
{
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }

    cout << endl;
}

int main()
{
    int a[10] = {1, 5, 4, 3, 2, 6, 7, 2, 3, 3};

    priority_queue<int> q;

    for (int i = 0; i < 10; i++)
        q.push(a[i]);

    display(q);

    return 0;
}
