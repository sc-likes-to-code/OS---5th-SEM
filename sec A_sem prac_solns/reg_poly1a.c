#include <stdio.h>
#include <pthread.h>
#include <math.h>

void* area(void* arg)
{
    int n = ((int*)arg)[0];
    float l = ((float*)arg)[1];
    float result;

    printf("Thread computing polygon area...\n");

    result = (n * l * l) / (4 * tan(M_PI / n));

    pthread_exit((void*)(&result));
}

int main()
{
    pthread_t t;
    int n;
    float l;
    void* res;

    printf("Enter number of sides: ");
    scanf("%d", &n);
    printf("Enter side length: ");
    scanf("%f", &l);

    float data[2];
    data[0] = n;
    data[1] = l;

    pthread_create(&t, NULL, area, data);
    pthread_join(t, &res);

    printf("Area of polygon = %.2f\n", *(float*)res);
    return 0;
}
