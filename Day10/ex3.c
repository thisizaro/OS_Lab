#include<stdio.h>
#include<pthread.h>

void *example(void *y1) {
    int *y2 = (int*)(y1);
    printf("Argument: %d\n", *y2);
}

int main() {
    pthread_t x1, x2;
    int value1 = 5, value2 = 10;
    pthread_create(&x1, NULL, example, (void*)&value1);
    pthread_create(&x2, NULL, example, (void*)&value2);
    pthread_join(x1, NULL);
    pthread_join(x2, NULL);
}


