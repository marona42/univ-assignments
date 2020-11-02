#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <wait.h>
#include <pthread.h>
int DEBUG=0;

int item_to_produce, curr_buf_size;
int total_items, max_buf_size, num_workers, num_masters;
pthread_mutex_t mslock = PTHREAD_MUTEX_INITIALIZER;
int *buffer;

void print_produced(int num, int master) {

  printf("Produced %d by master %d\n", num, master);
  if(DEBUG) printf(" at buffer %d/%d\n", curr_buf_size,max_buf_size);
}

void print_consumed(int num, int worker) {

  printf("Consumed %d by worker %d\n", num, worker);
  
}


//produce items and place in buffer
//modify code below to synchronize correctly
void *generate_requests_loop(void *data)
{
  int thread_id = *((int *)data);
  while(1)
  {
    pthread_mutex_lock(&mslock);
    if(item_to_produce >= total_items) {
      pthread_mutex_unlock(&mslock);
      break;
    }
    if(curr_buf_size >= max_buf_size)
    {
      pthread_mutex_unlock(&mslock);
      continue;
    }
    buffer[curr_buf_size++] = item_to_produce;
    print_produced(item_to_produce, thread_id);
    item_to_produce++;
    pthread_mutex_unlock(&mslock);
  }
  //pthread_exit(NULL);
  return 0;
}

//write function to be run by worker threads
//ensure that the workers call the function print_consumed when they consume an item
void *use_requests_loop(void *data)
{
  int thread_id = *((int *)data);
  int consuming_target;
  while(1)
  {
    pthread_mutex_lock(&mslock);
    if(curr_buf_size <= 0)
    {
      if(item_to_produce == total_items)
      {
        pthread_mutex_unlock(&mslock);
        break;
      }
      else
      {
        pthread_mutex_unlock(&mslock);
        continue;
      }
    }
    consuming_target = buffer[--curr_buf_size];
    print_consumed(consuming_target, thread_id);
    pthread_mutex_unlock(&mslock);
  }
  //pthread_exit(NULL);
  return 0;
}


int main(int argc, char *argv[])
{
  int *master_thread_id, *worker_thread_id;
  pthread_t *master_thread, *worker_thread;
  item_to_produce = 0;
  curr_buf_size = 0;
  
  int i;
  
  if (argc < 5) {
    printf("%s #total_items #max_buf_size #num_workers #masters e.g. %s 10000 1000 4 3\n",argv[0],argv[0]);
    exit(1);
  }
  else {
    total_items = atoi(argv[1]);      // 생성할 숫자의 범위 M
    max_buf_size = atoi(argv[2]);     // 생성된 숫자 저장할 버퍼 최대 크기 N
    num_workers = atoi(argv[3]);      // 생성한 숫자를 소비하는 워커 스레드 수 C
    num_masters = atoi(argv[4]);      // 숫자를 생성할 마스터 스레드의 수 P
  }
  //if (argc > 5) DEBUG=1;   //버퍼 크기 확인용

   buffer = (int *)malloc (sizeof(int) * max_buf_size);

   //create master producer threads
   master_thread_id = (int *)malloc(sizeof(int) * num_masters);
   master_thread = (pthread_t *)malloc(sizeof(pthread_t) * num_masters);
  for (i = 0; i < num_masters; i++)
    master_thread_id[i] = i;

  for (i = 0; i < num_masters; i++)
    pthread_create(&master_thread[i], NULL, generate_requests_loop, (void *)&master_thread_id[i]);

  //create worker consumer threads
  worker_thread_id = (int *)malloc(sizeof(int) * num_workers);
  worker_thread = (pthread_t *)malloc(sizeof(pthread_t) * num_workers);
  for (i = 0; i < num_workers; i++)
    worker_thread_id[i] = i;
      
  for (i = 0; i < num_workers; i++)
    pthread_create(&worker_thread[i], NULL, use_requests_loop, (void *)&worker_thread_id[i]);
  
  //wait for all threads to complete
  for (i = 0; i < num_masters; i++)
  {
    pthread_join(master_thread[i], NULL);
    printf("master %d joined\n", i);
  }
  for (i = 0; i < num_workers; i++)
  {
    pthread_join(worker_thread[i], NULL);
    printf("worker %d joined\n", i);
  }

  /*----Deallocating Buffers---------------------*/
  free(buffer);
  free(master_thread_id);
  free(master_thread);
  free(worker_thread_id);
  free(worker_thread);
  pthread_mutex_destroy(&mslock);

  return 0;
}
