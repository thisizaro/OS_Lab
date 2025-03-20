#include<stdio.h>
#include<pthread.h>

void *example(){
printf("Single thread\n");
}

int main (){
pthread_t x1;
pthread_create(&x1, NULL, example,NULL);
pthread_join(x1, NULL);
}

