#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "processInfo.h"


int main(void)
{
    struct processInfo tbuf;
    int i=0;
    printf(1,"PID   PPID   SIZE      Number of Context Switch\n");
    for(i=1;i<64;i++)
        if(get_proc_info(i,&tbuf)>0)
            printf(1,"%d\t%d\t%d\t%d\n",tbuf.pid,tbuf.ppid,tbuf.psize,tbuf.numberContextSwitches);
    exit();
}
