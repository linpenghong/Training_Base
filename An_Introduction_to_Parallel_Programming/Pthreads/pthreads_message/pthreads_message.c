#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MSG_MAX 1024

long thread_count;

char** messages;

sem_t* semaphores;

void* Send_msg(void* rank)
{
    long my_rank = (long)rank;
    long dest = (my_rank + 1) % thread_count;

    char* my_msg = malloc(MSG_MAX * sizeof(char));

    sprintf(my_msg, "Hello to %ld from %ld", dest, my_rank);

    messages[dest] = my_msg;

    // unlock the semaphore of dest
    sem_post(&semaphores[dest]);

    // wait for our semaphore to be unlock
    sem_wait(&semaphores[my_rank]);
    printf("Thread %ld > %s\n", my_rank, messages[my_rank]);

    return NULL;
}

int main(int argc, char* argv[])
{
    // transfer argv[1] to a long
    thread_count = strtol(argv[1], NULL, 10);

    // initialize messages
    messages = malloc(thread_count * sizeof(char*));

    // initialize semaphores
    semaphores = malloc(thread_count * sizeof(sem_t));
    for (long thread = 0; thread < thread_count; thread++)
    {
        sem_init(&semaphores[thread], 0, 0);
        // sem_open(&semaphores[thread], 0, 0);
        // semaphores[thread] = *sem_open("Semaphore", O_CREAT, 0644, 0);
    }

    // initialize thread_handles
    pthread_t* thread_handles;
    thread_handles = malloc(thread_count * sizeof(pthread_t));

    for (long thread = 0; thread < thread_count; thread++)
        pthread_create(&thread_handles[thread],
                       NULL,
                       Send_msg,
                       (void*)thread);

    for (long thread = 0; thread < thread_count; thread++)
    {
        pthread_join(thread_handles[thread], NULL);
        free(messages[thread]);
    }

    free(messages);

    return 0;
}
