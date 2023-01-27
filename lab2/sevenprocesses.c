// Name: Jonathan Stock
// Date: Wednesday
// Title: Lab2 - step 5
// Description This program computes seven processes and creates children for each process

#include <stdio.h>	   /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h>	   /* fork */
#include <stdlib.h>	   /* atoi */
#include <errno.h>	   /* errno */

int main()
{
	pid_t pid, pid2, pid3, pid4;
	int i;
	printf("\n Before forking.\n");
	pid = fork();
	if (pid == -1)
	{
		fprintf(stderr, "can't fork, error %d\n", errno);
	}

	if (pid)
	{

		printf("This is process with pid %d\n", getpid());
		pid2 = fork();
		if (pid2 == -1)
		{
			fprintf(stderr, "can't fork, error %d\n", errno);
		}
		if (pid2)
		{
			printf("This is process with pid %d and parent pid %d\n", getpid(), getppid());
		}
		else
		{
			pid3 = fork();
			if (pid3 == -1)
			{
				fprintf(stderr, "can't fork, error %d\n", errno);
			}
			if (pid3)
			{
				printf("This is process with pid %d and parent pid %d\n", getpid(), getppid());
			}
			else
			{
				wait(NULL);
			}
		}
	}

	else
	{
		pid4 = fork();
		if (pid4 == -1)
		{
			fprintf(stderr, "can't fork, error %d\n", errno);
		}
		if (pid4)
		{
			printf("This is process with pid %d and parent pid %d\n", getpid(), getppid());
		}
		else
		{
			wait(NULL);
		}
	}
	printf("After forking\n");
}
