// Name: Jonathan Stock
// Date: Wednesday
// Title: Lab3 - step5
// Description: This program opens a pipe and has a producer create a message and a consumer read the message.
// You input some text from the terminal and then it prints out that text at the other end of the pipe.
/**************************
 *   Lab3 - pipe()
 **************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>

// main
int main(int argc, char *argv[])
{
    int fds[2];
    char buff[60];
    int count;
    int i;
    pipe(fds);

    if (fork() == 0)
    {
        printf("\nWriter on the upstream end of the pipe -> %d arguments \n", argc);
        close(fds[0]);
        // for (i = 0; i < argc; i++)
        // {
        //     write(fds[1], argv[i], strlen(argv[i]));
        // }
        scanf("%s", buff);
        write(fds[1], buff, strlen(buff));
        exit(0);
    }
    else if (fork() == 0)
    {
        printf("\nReader on the downstream end of the pipe \n");
        close(fds[1]);
        while ((count = read(fds[0], buff, 60)) > 0)
        {
            // for (i = 0; i < count; i++)
            // {
            //     write(1, buff + i, 1);
            //     write(1, " ", 1);
            // }
            // printf("\n");
            printf("buff: %s\n", buff);
        }
        exit(0);
    }
    else
    {
        close(fds[0]);
        close(fds[1]);
        wait(0);
        wait(0);
    }
    return 0;
}
