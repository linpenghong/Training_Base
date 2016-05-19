#include <cstdio>

#include <mpi.h>
#include <omp.h>

int main(int argc, char* argv[])
{
    // OpenMP
    int rank = 0;
    int size = 1;

    // MPI
    int commRank;
    int commSize;

    int procNameLen;
    char procName[256];

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &commRank);
    MPI_Comm_size(MPI_COMM_WORLD, &commSize);

    MPI_Get_processor_name(procName, &procNameLen);

    #pragma omp parallel default(shared) private(rank, size)
    {
        #if defined (_OPENMP)
        rank = omp_get_thread_num();
        size = omp_get_num_threads();
        #endif

        printf("Hello from thread %d out of %d from process %d out of %d on %s\n",
               rank,
               size,
               commRank,
               commSize,
               procName);
    }

    MPI_Finalize();

    return 0;
}
