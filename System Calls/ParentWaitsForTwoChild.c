#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t p1, p2;
    
    p1 = fork();
    
    if (p1 == 0)
    {
        printf("Child 1 created, PID = %d", getpid());
    }
    else
    {
        p2 = fork();
        
        if (p2 == 0)
        {
            printf("Child 2 created, PID = %d", getpid());
        }
        else
        {
            wait(NULL);
            wait(NULL);
            printf("Parent process is created after both child processes finish executing\n")
        }
    }
    return 0;
}
