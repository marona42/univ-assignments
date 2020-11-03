#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

enum lockstatus{IDLE,READ,WRITE,UNKNOWN=-1};
struct rw_lock
{
    pthread_spinlock_t lockpin;
    enum lockstatus status;
    int users;
    int waitings_r,waitings_w;
};

void init_rwlock(struct rw_lock * rw);
void r_lock(struct rw_lock * rw);
void r_unlock(struct rw_lock * rw);
void w_lock(struct rw_lock * rw);
void w_unlock(struct rw_lock * rw);
long *max_element(long* start, long* end);
long *min_element(long* start, long* end);
