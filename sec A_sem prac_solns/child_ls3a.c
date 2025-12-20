#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if(pid == 0)
    {
        printf("Child executing ls using execl()\n");
        execl("/bin/ls", "ls", "-l", NULL);
    }
    else
    {
        wait(NULL);
        printf("Parent resumes after child execution\n");
    }
    return 0;
}
