#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"




int
main()
{
changepo(1);

struct timing t[25] ;




int f =0;
int k;
for ( k=0; k<25; k++) {
     f = fork();
    if (f == 0) {
        int pid = getpid();
        changePriority(pid,5-k/5);
         for (int i = 0; i < 500; i++)
        {
            printf(1,"[%d]: [%d]\n",i,k);
        }
       exit();
    }
    else
    {
          waitForChild(&t[k]);
    }
    

}


int TT = 0;
int WT = 0;
int CBT = 0;
  
    





    for(int i=0;i<5;i++){

         int tt = 0;
         int wt = 0;
         int cbt = 0;
         printf(1," priority group : %d \n",5-i);
        for(int j=0;j<5;j++){
          tt += t[i*5+j].tr - t[i*5+j].cr;
          wt += t[i*5+j].rt;
          cbt += t[i*5+j].rnt;    
        }
        tt/=5;
        wt/=5;
        cbt/=5;
         printf(1,"TT : %d,WT : %d,CBT : %d",tt,wt,cbt);
    }



    TT/=25.0;
    CBT /= 25.0;
    WT /= 25.0;
    printf(1,"TT : %d\nWT : %d\nCBT : %d\n",TT,WT,CBT);

    
exit();
}