#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_t thread1,thread2;

void* testing()
{
    printf("Execute this thread\n");
    sleep(2);
    printf("Finished execution\n");
}

int main()
{
    pthread_create(&thread1,NULL,&testing,NULL);
    pthread_create(&thread2,NULL,&testing,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    return 0;
}