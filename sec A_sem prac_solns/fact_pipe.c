#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int p[2], r, num;
    long long fact = 1;
    char buf[100];

    printf("\tFactorial of a Number using PIPE\n");

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

    // Process 2: read number and calculate factorial
    read(p[0], &num, sizeof(num));

    for (int i = 1; i <= num; i++)
        fact = fact * i;

    sprintf(buf, "Factorial of %d is %lld\n", num, fact);
    printf("%s", buf);

    return 0;
}
