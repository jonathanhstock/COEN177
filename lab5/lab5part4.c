// Name: Jonathan Stock
// Date: Wednesday
// Title: Lab5 - Step3
// Description: Creates a producer and consumer that keep producing items and consuming the items one after another

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>

#define NTHREADS 2
#define n 10

pthread_t threads[NTHREADS];

int buffer[n];
int x;
size_t length;

pthread_cond_t full, empty;
pthread_mutex_t mutex;
pthread_mutex_t lock;

// Producer thread
void *producer(void *arg)
{
    do
    {
        // produce next item
        int item;
        item = 69;
        pthread_mutex_lock(&lock);
        while (length == 10)
        {
            pthread_cond_wait(&empty, &mutex);
        }
        // add the item to buffer
        buffer[x] = item;
        x = (x + 1) % n;
        length++;
        printf("Producer adding %d to buffer\n", item);

        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
    } while (1);
}

// Consumer thread
void *consumer(void *arg)
{
    do
    {
        pthread_mutex_lock(&lock);

        while (length == 0)
        {
            pthread_cond_wait(&full, &mutex);
        }
        // remove next item from buffer
        int item = buffer[x];
        x = (x + 1) % n;
        length--;
        printf("Consumer removed %d from buffer\n", item);

        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
        // consume the item
    } while (1);
}

int main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&empty, NULL);
    pthread_cond_init(&full, NULL);

    pthread_create(&threads[0], NULL, producer, NULL);
    pthread_create(&threads[1], NULL, consumer, NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);

    return 0;
}
