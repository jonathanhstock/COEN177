// Name: Jonathan Stock
// Date: Wednesday
// Title: Lab5 - Step3
// Description: Creates a producer and consumer that keep producing items and consuming the items one after another

// Shared data: semaphore full, empty, mutex;
// pool of n buffers, each can hold one item
// mutex provides mutual exclusion to the buffer pool
// empty and full count the number of empty and full buffers
// Initially: full = 0, empty = n, mutex = 1

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>

#define NTHREADS 2
#define n 2

pthread_t threads[NTHREADS];

sem_t *full;
sem_t *empty;
sem_t *mutex;

int buffer[n];
int x;

// Producer thread
void *producer(void *arg)
{
    printf("Starting producer\n");

    do
    {
        // printf("\ncame here: producer\n");
        //  produce next item
        int item;
        item = 69;
        // add count into buffer then increment
        sem_wait(empty);
        sem_wait(mutex);
        // add the item to buffer
        buffer[x] = item;
        printf("Producer adding %d to buffer\n", item);
        x = (x + 1) % n;
        sem_post(mutex);
        sem_post(full);
    } while (1);
}

// Consumer thread
void *consumer(void *arg)
{
    printf("Starting consumer\n");

    do
    {
        printf("\ncame here: consumer\n");
        sem_wait(full);
        sem_wait(mutex);
        // remove next item from buffer
        int item = buffer[x];
        x = (x + 1) % n;
        printf("Consumer removed %d from buffer\n", item);
        sem_post(mutex);
        sem_post(empty);

        // consume the item
        // reads from buffer
    } while (1);
}

int main()
{
    sem_unlink("full");
    sem_unlink("empty");
    sem_unlink("mutex");
    printf("Starting main\n");

    full = sem_open("full", O_CREAT, 0644, 0);
    empty = sem_open("empty", O_CREAT, 0644, n);
    mutex = sem_open("mutex", O_CREAT, 0644, 1);

    pthread_create(&threads[0], NULL, producer, NULL);

    pthread_create(&threads[1], NULL, consumer, NULL);

    pthread_join(threads[0], NULL);

    pthread_join(threads[1], NULL);
    printf("\t\t\tThread 1 returned \n");

    sem_unlink("full");
    sem_unlink("empty");
    sem_unlink("mutex");

    printf("Ending main\n");

    return 0;
}
