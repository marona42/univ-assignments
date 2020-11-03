#include "rw_lock.h"
//TODO: 읽기랑 쓰기 둘 다 대기중인 경우 어떻게 되지?
void init_rwlock(struct rw_lock * rw)
{
  //	Write the code for initializing your read-write lock.
  rw->status=IDLE;
  rw->users=0;
  rw->waitings_r=0;
  rw->waitings_w=0;
}

void r_lock(struct rw_lock * rw)  //이전 reading lock 스레드와 동시에 획득 가능.
{
  //	Write the code for aquiring read-write lock by the reader.
  if(rw->status <= IDLE)
    rw->status=READ;
  else if(rw->status >= WRITE)    //이미 write중인 스레드가 존재함. read lock 획득 불가.
    {rw->waitings_r++; while(rw->status>=WRITE); rw->status=READ; rw->waitings_r--;}   //FIXME: write가 끝날 때까지 대기하기. 이걸로 끝나나?
  
  rw->users++;  //read하는 스레드 수 증가.
}

void r_unlock(struct rw_lock * rw)
{
  //	Write the code for releasing read-write lock by the reader.
  rw->users--;
  if(rw->users<=0) rw->status = IDLE;   //더 이상 이 lock을 read하는 스레드가 없음.
}

void w_lock(struct rw_lock * rw)  //w은 r이 끝날때까지 대기해야함.
{
  //	Write the code for aquiring read-write lock by the writer.
  if(rw->status <= IDLE && !rw->waitings_w)
    rw->status=WRITE;
  else                           //이미 lock중인 스레드가 존재함. write lock 획득 불가.
    {while(rw->waitings_w) usleep(1000); rw->waitings_w++;  while(rw->status > IDLE); rw->status=WRITE; rw->waitings_w--; }   //FIXME: 다른 일이 끝나 lock이 풀릴 때까지 대기하기. 이걸로 끝나나?
  rw->users++;
}

void w_unlock(struct rw_lock * rw)
{
  //	Write the code for releasing read-write lock by the writer.
  rw->users--;
  if(rw->users<=0) rw->status=IDLE;
}
