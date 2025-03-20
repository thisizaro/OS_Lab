#include<stdio.h>
#include<pthread.h>

void *example(void *y1) {
    long add = 0;
    long *y2 = (long*)(y1);
    for(long i = 0; i < 100000000; i++) {
        add = add + *y2;
    }
    return NULL;
}

int main() {
    pthread_t x1, x2;
    int value1 = 5, value2 = 10;
    example((void*)&value1);
    example((void*)&value2);
}


