// Name: Jonathan Stock
// Date: Wednesday
// Title: Lab2 - step 6
// Description This program computes two threads and creates children threads for every parent thread

#include <stdio.h>	   /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h>	   /* fork */
#include <stdlib.h>	   /* atoi */
#include <errno.h>	   /* errno */
#include <pthread.h>

void *thread_parent(int n)
{
	for (int i = 0; i < 100; i++)
	{
		printf("\t \t \t Parent Thread %d \n", i);
		usleep(n);
	}
	pthread_exit(NULL);
}

void *thread_child(int n)
{
	for (int i = 0; i < 100; i++)
	{
		printf("\t \t \t Child Thread %d \n", i);
		usleep(n);
	}
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread1, thread2;
	int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay

	printf("\n Before Thread.\n");
	pthread_create(&thread1, NULL, thread_parent, n);
	pthread_create(&thread2, NULL, thread_child, n);
	printf("\n After Thread.\n");
	pthread_exit(NULL);

	return 0;
}
