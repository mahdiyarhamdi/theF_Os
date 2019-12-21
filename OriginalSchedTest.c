#include "types.h"
#include "stat.h"
#include "user.h"





int
main()
{
changepo(2);
struct timing t[10];

int tt = 0;
int wt = 0;
int CBT = 0;


for (int k=0; k<10; k++){
    int f = fork();     
    if (f == 0) {
        int pid = getpid();
        
        for (int i = 0; i < 1000; i++)
        {
            printf(1,"[%d]: [%d]\n",pid,i);
        }
      
        exit();
    }
    else
    {
        waitForChild(&t[i]);
        
    }
    
}




   
    for (int i = 0; i < 10; i++)
    {
         tt+=t[i].tr - t[i].cr;
         CBT += t[i].rnt;
         wt += t[i].rt;

    }
    tt/=10;
    CBT /= 10;
    wt /= 10;
   
    printf(1,"TT : %d,WT : %d,CBT : %d",tt,wt,CBT);


exit();
}