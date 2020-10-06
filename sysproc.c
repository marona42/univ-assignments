#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "processInfo.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_hello(void)
{
  return hello();
}

int
sys_hello_name(void)
{
  char *name="";
  if(argstr(0, &name) < 0)
    return -1;
  return hello_name(name);
}

/*TODO: implements these syscalls:*/
int
sys_get_num_proc(void)
{
  return get_num_proc();
}
int
sys_get_max_pid(void)
{
  return get_max_pid();
}
int
sys_get_proc_info(void)
{
  int tproc;
  struct processInfo *tinf;
  if(argint(0,&tproc)<0 || argptr(1,(void*)&tinf,sizeof(*tinf))<0) return -1;

  return get_proc_info(tproc,tinf);
}
int
sys_set_prio(void)
{
  int tprio;
  if(argint(0,&tprio)<0 || tprio<0) return -1;
  return set_prio(tprio);
}
int
sys_get_prio(void)
{
  int tpid;
  if(argint(0,&tpid)<0) return -1;
  return get_prio(tpid);
}
