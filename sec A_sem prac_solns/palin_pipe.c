#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd1[2], fd2[2], num, rev = 0, temp, digit, result;
    pipe(fd1);
    pipe(fd2);

    printf("Enter number: ");
    scanf("%d", &num);

    if(fork() == 0)
    {
        close(fd1[1]);
        read(fd1[0], &temp, sizeof(temp));
        close(fd1[0]);

        int original = temp;
        while(temp > 0)
        {
            digit = temp % 10;
            rev = rev * 10 + digit;
            temp /= 10;
        }

        result = (original == rev);
        write(fd2[1], &result, sizeof(result));
        close(fd2[1]);
    }
    else
    {
        close(fd1[0]);
        write(fd1[1], &num, sizeof(num));
        close(fd1[1]);

        read(fd2[0], &result, sizeof(result));
        close(fd2[0]);

        if(result)
            printf("Palindrome number\n");
        else
            printf("Not palindrome\n");

        wait(NULL);
    }
    return 0;
}
