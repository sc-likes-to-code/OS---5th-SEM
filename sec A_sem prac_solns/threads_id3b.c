#include <stdio.h>
#include <pthread.h>

void* display(void* arg)
{
    int id = *(int*)arg;
    printf("Thread %d running. Thread ID = %lu\n", id, pthread_self());
    pthread_exit(NULL);
}

int main()
{
    pthread_t t[3];
    int id[3] = {1, 2, 3};

    for(int i = 0; i < 3; i++)
        pthread_create(&t[i], NULL, display, &id[i]);

    for(int i = 0; i < 3; i++)
        pthread_join(t[i], NULL);

    printf("Main thread finished\n");
    return 0;
}
