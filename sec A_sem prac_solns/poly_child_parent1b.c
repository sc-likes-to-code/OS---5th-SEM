#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

int main()
{
    int n;
    float l, area;
    pid_t pid;

    printf("Enter number of sides: ");
    scanf("%d", &n);
    printf("Enter length of side: ");
    scanf("%f", &l);

    pid = fork();

    if(pid == 0)
    {
        // Child process
        printf("Child computing area of polygon...\n");
        area = (n * l * l) / (4 * tan(M_PI / n));
        printf("Child computed area: %.2f\n", area);
    }
    else
    {
        // Parent process
        printf("Parent waiting for child to finish...\n");
        wait(NULL);
        printf("Parent resumes after child completion\n");
    }

    return 0;
}
