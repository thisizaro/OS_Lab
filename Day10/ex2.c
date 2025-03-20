#include<stdio.h>
#include<pthread.h>

void *example(void *y1) {
   int *y2 = (int *)(y1);
   printf("Single thread with argument: %d\n", *y2);
   return NULL;
   }
   
   
int main (){
    pthread_t xl;
    int value = 10;
    pthread_create (&xl,NULL,example,(void*)&value);
    pthread_join (xl,NULL);
}

