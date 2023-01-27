// Name: Jonathan Stock
// Date: Wednesday
// Title: Lab2 - step 4
// Description This program computes two processes and creates children for each process and also waits for the child process to complete

#include <stdio.h> /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h> /* fork */
#include <stdlib.h> /* atoi */
#include <errno.h> /* errno */
#include <pthread.h>

int main(int argc, char *argv[]) {
	pid_t pid;
	int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
	printf("\n Before forking.\n");
	pid = fork();
	if (pid == -1){
		fprintf(stderr, "can't fork, error %d\n", errno);
	}
	if (pid){
		// Parent process
		for (i = 0; i < 100; i++){
			printf("\t \t \t Parent Process %d \n",i);
			usleep(n);
		}
		wait(NULL);
		printf("Child Complete");
		exit(0);
	}
	else{
		// Child process		
		for (i = 0; i < 100; i++){
			printf("Child process %d\n",i);
			usleep(n);
		}
		execlp("/bin/ls", "ls", NULL);
	}
	return 0;
}



