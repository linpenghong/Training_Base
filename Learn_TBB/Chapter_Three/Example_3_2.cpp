#include <cstdlib>

#include "tbb/task_scheduler_init.h"

using namespace tbb;

int main(int argc, char* argv[])
{
    // get the thread number
    int nthread = strtol(argv[0], 0, 0);

    // constructed a deferred task scheduler
    // it will wait for initialize method for constructing multi-tasks
    task_scheduler_init init(task_scheduler_init::deferred);

    if (nthread >= 1)
        init.initialize(nthread);

    if (nthread >= 1)
        init.terminate();

    return 0;
}
