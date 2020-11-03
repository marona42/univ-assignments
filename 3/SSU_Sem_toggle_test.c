#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <wait.h>
#include <pthread.h>

#include "SSU_Sem.h"

#define NUM_THREADS 3
#define NUM_ITER 10

SSU_Sem sem[NUM_THREADS];

void *justprint(void *data)
{
  int thread_id = *((int *)data);
  SSU_Sem_down(&sem[thread_id]);

  for(int i=0; i < NUM_ITER; i++)
  {
    printf("This is thread %d\n", thread_id);
    //printf("waking up %d\n", (thread_id+1)%NUM_THREADS);
    SSU_Sem_up(&sem[(thread_id+1)%NUM_THREADS]);
    SSU_Sem_down(&sem[thread_id]);
  }
  SSU_Sem_up(&sem[(thread_id+1)%NUM_THREADS]);
  return 0;
}

int main(int argc, char *argv[])
{

  pthread_t mythreads[NUM_THREADS];
  int mythread_id[NUM_THREADS];

  for(int i =0; i < NUM_THREADS; i++)
  {
    mythread_id[i] = i;
    SSU_Sem_init(&sem[i],0);
    pthread_create(&mythreads[i], NULL, justprint, (void *)&mythread_id[i]);
  }
  SSU_Sem_up(&sem[0]);

  for(int i =0; i < NUM_THREADS; i++)
  {
    pthread_join(mythreads[i], NULL);
  }
  
  return 0;
}
