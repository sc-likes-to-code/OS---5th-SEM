#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2;

    printf("Level 0 Parent PID = %d\n", getpid());

    pid1 = fork();

    if(pid1 == 0)
    {
        printf("Level 1 Child PID = %d Parent PID = %d\n", getpid(), getppid());

        pid2 = fork();

        if(pid2 == 0)
        {
            printf("Level 2 Child PID = %d Parent PID = %d\n", getpid(), getppid());
        }
        else
            wait(NULL);
    }
    else
        wait(NULL);

    return 0;
}
