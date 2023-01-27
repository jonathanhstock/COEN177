// Name: Jonathan Stock
// Date: Wednesday
// Title: Lab3 - step7
// Description: This program creates 10 threads and lists out which iteration it is on.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>

void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];
int main()
{
    int i;
    for (i = 0; i < NTHREADS; i++)
        // pass by value instead of reference
        pthread_create(&threads[i], NULL, go, (size_t)(void *)i);

    for (i = 0; i < NTHREADS; i++)
    {
        printf("Thread %d returned\n", i);
        pthread_join(threads[i], NULL);
    }
    printf("Main thread done.\n");
    return 0;
}
void *go(void *arg)
{
    printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), (size_t *)(int)arg);
    return 0;
}
