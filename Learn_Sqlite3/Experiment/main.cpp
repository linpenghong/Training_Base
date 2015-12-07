#include <cstdio>

#include "Experiment.h"

#define N 1000000

int main()
{
    Experiment exp;
    exp.createTableParticles();

    char particleName[256];
    for (int i = 0; i < N; i++)
    {
        sprintf(particleName, "%d", i);
        exp.appendParticle(particleName, i, i);
    }

    exp.saveDatabase("save1.db");

    return 0;
}
