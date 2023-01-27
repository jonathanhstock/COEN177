// Name: Jonathan Stock
// Date: Wednesday
// Title: Lab4 - Step1
// Description: creates a simple multi-threaded program that lists the threads and threadid's

/**************************************************************
 *	threadHello.c - simple multi-threaded program.            *
 *   compile with: >gcc -lpthread threadHello.c -o threadHello       *                                              *
 **************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREADS 20

void *go(void *);
pthread_t threads[NTHREADS];

int main()
{
    static int i;
    for (i = 0; i < NTHREADS; i++)
        pthread_create(&threads[i], NULL, go, &i);
    for (i = 0; i < NTHREADS; i++)
    {
        pthread_join(threads[i], NULL);
        printf("Thread %d returned \n", i);
    }
    printf("Main thread done.\n");
}
void *go(void *arg)
{
    printf("Hello from thread %d with thread ID %d \n", *(int *)arg, (int)pthread_self());
    return (NULL);
}
