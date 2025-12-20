#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    if(fork()==0)
    {
        sleep(5); // child waits
        printf("\n Child Process (PID = %d), new Parent (PID = %d)\n",
               getpid(), getppid());
    }
    else
    {
        printf("\n Parent exiting... Child will be Orphan");
    }
    return 0;
}
