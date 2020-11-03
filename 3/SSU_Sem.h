#include <pthread.h>

typedef struct SSU_Sem {
    int cnt;
    pthread_spinlock_t lockpin;
} SSU_Sem;

void SSU_Sem_init(SSU_Sem *, int);
void SSU_Sem_up(SSU_Sem *);
void SSU_Sem_down(SSU_Sem *);
