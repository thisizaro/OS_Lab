#include<stdio.h>
#include<pthread.h>

void *example(void *y1) {
    long add = 0;
    long *y2 = (long*)(y1);
    for(long i = 0; i < 1000000; i++) {
        add = add + *y2;
    }
    return NULL;
}

int main() {
    pthread_t x1, x2;
    int value1 = 5, value2 = 10;
    pthread_create(&x1, NULL, example, (void*)&value1);
     pthread_join(x1, NULL);
    pthread_create(&x2, NULL, example, (void*)&value2);
    pthread_join(x2, NULL);
}


