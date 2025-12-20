#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2;

    printf("Parent process PID = %d\n", getpid());

    pid1 = fork();

    if(pid1 == 0)
    {
        printf("First child PID = %d, Parent PID = %d\n", getpid(), getppid());
        return 0;
    }
    else
    {
        pid2 = fork();

        if(pid2 == 0)
        {
            printf("Second child PID = %d, Parent PID = %d\n", getpid(), getppid());
            return 0;
        }
        else
        {
            wait(NULL);
            wait(NULL);
            printf("Parent finished execution\n");
        }
    }
    return 0;
}
