#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    if(fork()==0)
    {
        printf("\n Child Process Exiting ....\n");
        exit(0);
    }
    else
    {
        printf("\n Parent does not receive the child's termination status.\n");
        printf("\n Parent is sleeping, Child becomes Zombie...\n");
        sleep(10);
        printf("\n Parent Wokeup.\n");
    }
    return 0;
}
