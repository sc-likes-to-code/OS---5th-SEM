#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd[2], n;
    long long fact = 1;
    pipe(fd);

    printf("Enter number: ");
    scanf("%d", &n);

    if(fork() == 0)
    {
        close(fd[0]);
        for(int i = 1; i <= n; i++)
            fact *= i;
        write(fd[1], &fact, sizeof(fact));
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        read(fd[0], &fact, sizeof(fact));
        printf("Factorial = %lld\n", fact);
        close(fd[0]);
        wait(NULL);
    }
    return 0;
}
