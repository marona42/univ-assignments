#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <wait.h>
#include "SSU_Sem.h"
#include <unistd.h>

void SSU_Sem_init(SSU_Sem *s, int value) {
  s->cnt=value;
  pthread_spin_init(&s->lockpin,0);

}

void SSU_Sem_down(SSU_Sem *s) {
  pthread_spin_lock(&s->lockpin);
  //printf("Sem Down %d->%d\n",s->cnt,s->cnt-1);
  s->cnt--;
  while(1)
  {
    if(s->cnt>=0) {break;}
    //else {printf("Sleeping:%d\n",s->cnt); sleep(1);}
  }
  pthread_spin_unlock(&s->lockpin);
}

void SSU_Sem_up(SSU_Sem *s) {
    s->cnt++;
    //printf("Sem UP ->%d\n",s->cnt);
}
