#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int p[2], r, num, rev = 0, temp;
    char buf[100];

    printf("\tCheck Palindrome Number using PIPE\n");

    r = pipe(p);
    if (r < 0)
    {
        printf("Failed to create unnamed pipe...\n");
        exit(1);
    }

    printf("Enter a number: ");
    scanf("%d", &num);

    // Process 1: send number
    write(p[1], &num, sizeof(num));

    // Process 2: read number and check palindrome
    read(p[0], &num, sizeof(num));

    temp = num;
    while (temp != 0)
    {
        rev = rev * 10 + (temp % 10);
        temp = temp / 10;
    }

    if (num == rev)
        strcpy(buf, "It is a Palindrome Number\n");
    else
        strcpy(buf, "It is Not a Palindrome Number\n");

    printf("%s", buf);
    return 0;
}
