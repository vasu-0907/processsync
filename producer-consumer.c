#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int max_size = 5;
int in = 0;
int out = 0;
int counter = 0;
int buf[10];
int semaphore[3];
void wait1(int *S)
{
    while ((*S) <= 0)
        ;

    (*S)--;
}
void signal(int *S)
{
    (*S)++;
}
void producer(int p)
{
    wait1(&semaphore[1]);
    wait1(&semaphore[2]);
    buf[in] = p;
    printf("\nProduced Produced Item %d", in + 1);
    in = (in + 1) % max_size;
    counter++;
    signal(&semaphore[2]);
    signal(&semaphore[0]);
}
void consumer()
{
    wait1(&semaphore[0]);
    wait1(&semaphore[2]);
    int q = buf[out];
    printf("\nConsumer Consumed Item %d", q);
    out = (out + 1) % max_size;
    counter--;
    signal(&semaphore[2]);
    signal(&semaphore[1]);
}
int main()
{
printf("\nInter Process Communication (Producer Consumer Problem) Using Semaphores");
int ch,id,i=1;
semaphore[0] = 0;
 semaphore[1] = max_size;
 semaphore[2] = 1;
 time_t t;
srand((unsigned)time(&t));
 while(i <= 30){
        int x = rand();
        if (x % 2 == 0)
        {
            if (semaphore[0] == max_size)
            {
                printf("\nBuffer Full\n");
            }
            else
            {
                producer(in + 1);
            }
        }
        else
        {
            if (semaphore[1] == max_size)
            {
                printf("\nBuffer Empty\n");
            }
            else
            {
                consumer();
            }
        }
        i++;
}
printf("\nThe End \n");
return 0;
}