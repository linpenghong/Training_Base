#include <iostream>

#include "tbb/task_scheduler_init.h"

using namespace tbb;

int main(int argc, char* argv[])
{
    int nthread = 4;

    task_scheduler_init init(task_scheduler_init::deferred);

    if (nthread >= 1)
    {
        init.initialize(nthread);

        std::cout<< "a thread" << std::endl;
    }

    if (nthread >= 1)
        init.terminate();
}
