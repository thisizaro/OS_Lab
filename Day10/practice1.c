#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void entry1(pthread_t *thread)
{

    for (int i = 0; i < 100; i++)
    {
        printf("Thread %d is running %d\n", *thread, i);
        sleep(0.05);
    }
}

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, entry1, (void *)&thread1);
    pthread_create(&thread2, NULL, entry1, (void *)&thread2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}