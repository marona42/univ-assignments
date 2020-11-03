#include "rw_lock.h"
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
  else if(rw->status >= WRITE || rw->waitings_w)    //이미 write중인 스레드가 존재함. read lock 획득 불가.
    {rw->waitings_r++; while(rw->waitings_w || rw->status>=WRITE); rw->status=READ; rw->waitings_r--;}
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
  { rw->waitings_w++;  while(rw->status > IDLE) usleep(1); rw->status=WRITE; rw->waitings_w--; }
    //{rw->waitings_w++;  while(1) if(rw->status <= IDLE){rw->waitings_w--; rw->status=WRITE; break;} }
  rw->users++;
}

void w_unlock(struct rw_lock * rw)
{
  //	Write the code for releasing read-write lock by the writer.
  rw->users--;
  if(rw->users<=0) rw->status=IDLE;
}
