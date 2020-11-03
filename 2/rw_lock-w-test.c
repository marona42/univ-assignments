#include "rw_lock.h"
void init_rwlock(struct rw_lock * rw)
{
  //	Write the code for initializing your read-write lock.
  rw->status=IDLE;
  rw->users=0;
  rw->waitings_r=0;
  rw->waitings_w=0;
  pthread_spin_init(&rw->lockpin,0);
}

void r_lock(struct rw_lock * rw)  //이전 reading lock 스레드와 동시에 획득 가능.
{
  //	Write the code for aquiring read-write lock by the reader.
  if(rw->status <= IDLE)
  {
    pthread_spin_lock(&rw->lockpin);
    rw->status=READ; rw->users++;
    //printf("->![%d]\n",rw->users);
    pthread_spin_unlock(&rw->lockpin);
  }
  else if(rw->status >= WRITE || rw->waitings_w)    //이미 write중인 스레드가 존재함. read lock 획득 불가.
  {
    rw->waitings_r++;
    while(1)
    {
      pthread_spin_lock(&rw->lockpin);
      if(rw->status<=READ && !rw->waitings_w)
      {
        //printf("%d[%d]->",rw->status,rw->waitings_w);
        rw->status=READ; rw->waitings_r--;  rw->users++; 
        //printf("%d(%d)\n",rw->status,rw->users);
        pthread_spin_unlock(&rw->lockpin);
        break;
      }
      pthread_spin_unlock(&rw->lockpin);
    }
  }
  else   //이미 read중인 스레드가 존재함. read 획득 가능.
  {
    rw->waitings_r++;
    while(1)
    {
      pthread_spin_lock(&rw->lockpin);
      if(rw->status<=READ && !rw->waitings_w)
      {
        //printf("%d[%d]->",rw->status,rw->waitings_w);
        rw->status=READ; rw->waitings_r--;  rw->users++; 
        //printf("%d(%d)\n",rw->status,rw->users);
        pthread_spin_unlock(&rw->lockpin);
        break;
      }
      pthread_spin_unlock(&rw->lockpin);
    }
  }
}

void r_unlock(struct rw_lock * rw)
{
  //	Write the code for releasing read-write lock by the reader.
  pthread_spin_lock(&rw->lockpin);
  rw->users--;
  //printf("[%d]=>%d\n",rw->users,rw->status);
  if(rw->users<=0) rw->status = IDLE;   //더 이상 이 lock을 read하는 스레드가 없음.
  pthread_spin_unlock(&rw->lockpin);

  
  //rw->users--;
  //if(rw->users<=0) rw->status = IDLE;   //더 이상 이 lock을 read하는 스레드가 없음.
}

void w_lock(struct rw_lock * rw)  //w은 r이 끝날때까지 대기해야함.
{
  //	Write the code for aquiring read-write lock by the writer.
  if(rw->status <= IDLE && !rw->waitings_w)
    rw->status=WRITE;
  else                           //이미 lock중인 스레드가 존재함. write lock 획득 불가.
  {
    rw->waitings_w++;
    while(1)
    {
      pthread_spin_lock(&rw->lockpin);
      if(rw->status <= IDLE)
      {
        //printf("%d",rw->status);
        rw->status=WRITE; rw->waitings_w--; rw->users++;
        //printf("->%d(%d)\n",rw->status,rw->users);
        pthread_spin_unlock(&rw->lockpin);
        break;
      }
      pthread_spin_unlock(&rw->lockpin);
    }
  }
}

void w_unlock(struct rw_lock * rw)
{
  //	Write the code for releasing read-write lock by the writer.
  pthread_spin_lock(&rw->lockpin);
  //printf("[%d]=>%d\n",rw->users,rw->status);
  rw->users--;
  if(rw->users<=0) rw->status=IDLE;  
  pthread_spin_unlock(&rw->lockpin);
}
