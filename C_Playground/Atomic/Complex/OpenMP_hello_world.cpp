#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void print_thread_id(int id)
{
    mtx.lock();
    std::cout << "thread #" << id << "\n";
    mtx.unlock();
}

int main()
{
    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < 10; i++)
        print_thread_id(i);

    return 0;
}
