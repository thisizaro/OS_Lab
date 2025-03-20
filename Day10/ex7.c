#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *example(void *y1) {
    int add = 0;
    int *result = malloc(sizeof(int));

    int *y2 = (int*)(y1);
    for(int i = 0; i < 100; i++) {
        add = add + *y2;
    }

    *result = add;
    return (void*)result;
}

int main() {
    pthread_t x1, x2;
    int value1 = 5, value2 = 10;
    int *res1, *res2;

    pthread_create(&x1, NULL, example, (void*)&value1);
    pthread_create(&x2, NULL, example, (void*)&value2);
    pthread_join(x1, (void**)&res1);
    pthread_join(x2, (void**)&res2);

    printf("Result 1 = %d\n", *res1);
    printf("Result 2 = %d\n", *res2);

    free(res1);
    free(res2);

    return 0;
}


