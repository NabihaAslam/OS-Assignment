//create a program that take stores 1000 elements in an array ,create 10 threads and each thread calcuate sum of 100 arry eleemts and end show their total
//C Program
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
//size of array
#define MAX_SIZE 1000
//maximum no of threads
#define MAX_THREAD 10
//function prototype
void* sum_array(void *arg);
//DEclaring array 
int a[1000];
for(int i=0;i<1000;i++)
{
a[i]=i+1;
}
int part=0;
int sum[1000]={0};
//declaring thread function that caLCULATES sum of 100 elements
void* sum_array(void *arg)
{
int thread_part=part++;
for(int i=thread_part*(MAX_SIZE/10);i<(thread_part+1)*(MAX_SIZE/10);i++)
sum[thread_part]+=a[i];
return sum[i];
}



int main()
{
pthread_t threads[MAX_THREAD];
//CREATING 10 THREADS
for(int i=0;i<MAX_THREAD;i++)
{
pthread_create(&threads[i],NULL,sum_array,(void)* a);
}
//joining 10 threads
for(int i=0;i<MAX_THREAD;i++)
{
pthread_join(threads[i],NULL);
}
int total_sum=0;
for(int i=0;i<MAX_THREAD;i++)
{
total_sum+=sum[i];
printf("“%sum is\n”,total_sum);
return 0;
}
}
