#include "types.h"
#include "user.h"

int main(void) {
    getppid();
    getppid();
    sleep(1);
    getppid();
    getppid();
    sleep(2);
    getpid(); 
    getppid(); 
    getpid();
    getpid();
    int pipefds[2];
    pipe(pipefds);   
    printf(1,"#getppid %d \n",
                getcount(23));
    printf(1,"#sleep %d \n",
                getcount(13));
    printf(1,"#getpid %d \n",
                getcount(11));
       printf(1,"#pipe %d \n",
                getcount(4));
    
}