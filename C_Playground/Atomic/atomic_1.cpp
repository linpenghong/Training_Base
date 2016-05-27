#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;

struct Node
{
    int value;
    Node* next;
};

atomic<Node*> list_head(nullptr);

void append(int val)
{
    Node* newNode = new Node {val, list_head};

    while (!list_head.compare_exchange_weak(newNode->next, newNode)){}
}

int main()
{
    vector<thread> threads;

    for (int i = 0; i < 10; i++)
        threads.push_back(thread(append, i));

    for (auto& th : threads) th.join();

    for (Node* it = list_head; it != nullptr; it = it->next)
        cout << ' ' << it->value;
    
    cout << '\n';

    Node* it;

    while (it = list_head)
    {
        list_head = it->next;
        delete it;
    }

    return 0;
}
