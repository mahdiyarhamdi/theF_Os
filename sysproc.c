#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  myproc()->count[1]=myproc()->count[1]+1;
  return fork();
}

int
sys_exit(void)
{
  myproc()->count[2]=myproc()->count[2]+1;
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  myproc()->count[3]=myproc()->count[3]+1;
  return wait();
}

int
sys_kill(void)
{
  int pid;
  myproc()->count[6]=myproc()->count[6]+1;
  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  myproc()->count[11]=myproc()->count[11]+1;
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;
  myproc()->count[12]=myproc()->count[12]+1;
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
      myproc()->count[13]=myproc()->count[13]+1;
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
    myproc()->count[14]=myproc()->count[14]+1;
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
int
sys_getppid(void)
{
    // cprintf("@@@@@@@@@@\n");
    myproc()->count[23]=myproc()->count[23]+1;
    return myproc()->parent->pid;
}

int
sys_getchild()
{
myproc()->count[24]=myproc()->count[24]+1;
int pid;
if(argint(0, &pid) < 0)
  return -1;
return getchild(pid);
}

int
sys_getcount(void)
{
  int n;
  if(argint(0, &n) < 0)
    return -1;
  return myproc()->count[n];
}
int 
sys_changep(void)
{
 int n,m;
if(argint(0, &n) < 0)
    return -1;
if(argint(1, &m) < 0)
    return -1;
return changep(n,m);
}

int 
sys_changepo(void)
{
 int n;
if(argint(0, &n) < 0)
    return -1;
return changepo(n);
}

