#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread_count;

int m = 4;
int n = 4;

float y[4];
float A[4][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
float x[4] = {1, 2, 3, 4};

void* Pth_mat_vec(void* rank)
{
    long my_rank = (long)rank;

    int local_m = m /thread_count;
    
    int my_first_row = my_rank * local_m;
    int my_last_row = (my_rank + 1) * local_m - 1;

    for (int i = my_first_row; i <= my_last_row; i++)
    {
        y[i] = 0;
        for (int j = 0; j < n; j++)
            y[i] += A[i][j] * x[j];
    }

    return NULL;
}

int main(int argc, char* argv[])
{
    pthread_t* thread_handles;

    // transfer argv[1] to a long
    thread_count = strtol(argv[1], NULL, 10);

    thread_handles = malloc(thread_count * sizeof(pthread_t));

    for (long thread = 0; thread < thread_count; thread++)
        pthread_create(&thread_handles[thread],
                       NULL,
                       Pth_mat_vec,
                       (void*)thread);

    for (long thread = 0; thread < thread_count; thread++)
        pthread_join(thread_handles[thread], NULL);

    for (int i = 0; i < n; i++)
        printf("%f ", y[i]);
    printf("\n");

    free(thread_handles);

    return 0;
}
