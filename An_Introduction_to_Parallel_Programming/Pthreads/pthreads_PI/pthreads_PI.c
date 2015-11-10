#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long n = 1000000000;

pthread_mutex_t mutex;

long thread_count;

double sum = 0;

void* Thread_sum(void* rank)
{
    long my_rank = (long)rank;
    double factor;
    
    long my_n = n / thread_count;

    long my_first_i = my_n * my_rank;
    long my_last_i = my_n * (my_rank + 1) - 1;

    double my_sum = 0.0;

    if (my_first_i % 2 == 0)
        factor = 1.0;
    else
        factor = -1.0;

    for (long i = my_first_i; i <= my_last_i; i++, factor *= -1)
        my_sum += factor / (2 * i + 1);

    pthread_mutex_lock(&mutex);
    sum += my_sum;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char* argv[])
{
    // transfer argv[1] to a long
    thread_count = strtol(argv[1], NULL, 10);

    // initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // initialize thread_handles
    pthread_t* thread_handles;
    thread_handles = malloc(thread_count * sizeof(pthread_t));

    for (long thread = 0; thread < thread_count; thread++)
        pthread_create(&thread_handles[thread],
                       NULL,
                       Thread_sum,
                       (void*)thread);

    for (long thread = 0; thread < thread_count; thread++)
        pthread_join(thread_handles[thread], NULL);

    printf("PI = %lf\n", 4 * sum);

    return 0;
}
