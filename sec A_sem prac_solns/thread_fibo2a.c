#include <stdio.h>
#include <pthread.h>

void* fibonacci(void* arg)
{
    int n = *(int*)arg;
    int a = 0, b = 1, c;

    printf("Thread generating Fibonacci series...\n");

    if(n >= 1) printf("%d ", a);
    if(n >= 2) printf("%d ", b);

    for(int i = 3; i <= n; i++)
    {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }

    printf("\nThread finished execution\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t t;
    int n;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    pthread_create(&t, NULL, fibonacci, &n);
    pthread_join(t, NULL);

    printf("Main thread exiting\n");
    return 0;
}
