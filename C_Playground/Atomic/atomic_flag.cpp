#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <sstream>

using namespace std;

atomic_flag lock_stream = ATOMIC_FLAG_INIT;
stringstream stream;

void append_number(int x)
{
    // test_and_set : flag -> false, set true, return false; true, no set,
    // return true
    // If another stream clear up lock_stream, this stream will jump out the
    // while loop.
    while (lock_stream.test_and_set()) {}

    stream << "thread #" << x << "\n";

    lock_stream.clear();
}

int main()
{
    vector<thread> threads;

    for (int i = 1; i <= 10; i++)
        threads.push_back(thread(append_number, i));

    for (auto& th : threads) th.join();

    cout << stream.str();

    return 0;
}
