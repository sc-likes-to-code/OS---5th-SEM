#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int p[2];
    char msg[50];

    if (pipe(p) < 0)
    {
        printf("Pipe creation failed");
        exit(1);
    }

    printf("Enter the message: ");
    scanf("%s", msg);

    write(p[1], msg, strlen(msg) + 1);
    read(p[0], msg, sizeof(msg));

    if (strcmp(msg, "HELLO") == 0)
    {
        printf("Action: Greeting received");
    }
    else
    {
        printf("Action: Unknown message");
    }

    return 0;
}
