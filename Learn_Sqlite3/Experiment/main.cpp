#include <cstdio>

#include "Experiment.h"

#define N 1000000

int main()
{
    Experiment exp("test.db");

    char groupName[256];
    for (int i = 0; i < N; i++)
    {
        sprintf(groupName, "group%d", i);
        exp.appendGroup(groupName);
    }

    return 0;
}
