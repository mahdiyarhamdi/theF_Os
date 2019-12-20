#include "types.h"
#include "user.h"
int main(void) {
    int child1 = fork();
    int child2 = fork();
    // if (child1 > 0 && child2 > 0){
    //     printf(1, "*PARENT  :: childs=%d    getpid()=%d\n",
    //             getchild(getpid()), getpid());
    // }
    if(child1 == 0) {
        sleep(20);
        printf(1, "child 1: getpid()=%d getppid()=%d\n",
                getpid(), getppid());
        sleep(20);
    }
    else if(child2 == 0) {
        sleep(20);
        printf(1, "child 2: getpid()=%d getppid()=%d\n",
                getpid(), getppid());
        sleep(20);
        }
    else{
        printf(1, "*PARENT  :: childs=%d    getpid()=%d\n",
                getchild(getpid()), getpid());
    }
}
