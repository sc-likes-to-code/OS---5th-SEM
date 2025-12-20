#include <stdio.h>
#include <pthread.h>

void* sum(void* arg)
{
    int n = *(int*)arg;
    int s = 0;

    for(int i = 1; i <= n; i++)
        s += i;

    pthread_exit((void*)s);
}

int main()
{
    pthread_t t;
    int n;
    void* res;

    printf("Enter n: ");
    scanf("%d", &n);

    pthread_create(&t, NULL, sum, &n);
    pthread_join(t, &res);

    printf("Sum = %d\n", (int)res);
    return 0;
}
