#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <printf.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>


int main() {

    pid_t pid, i, j, pid1, ppp; //declare the pid we will use
    int status;


    printf("\ncurrent process id = %d \n", getpid()); //acknowledge current pid
    ppp = getpid(); //save for later use
    printf("\n I am parent with PID %d is waiting my child to complete before create new child\n", getpid());

    pid = fork(); //fork first time
    if (pid < 0) // fork unsuccessful
    {
        printf("fork unsuccessful");
        exit(1);
    }
    if (pid > 0) //parent
    {


        wait(NULL);
        printf("\nchild_1 (PID:%d) is now completed\n", pid);


    }
    if (pid == 0) //child
    {


        i = getpid();
        j = getppid();
        printf("\n parent process (PID :%d) created child_1 (PID:%d)\n", j, i);

    }
    pid1 = fork(); //fork second time
    if (pid1 < 0) // fork unsuccessful
    {
        printf("fork unsuccessful");
        exit(1);
    }
    if (pid1 > 0) //parent
    {


        wait(NULL);


    }
    if (pid1 == 0) //child
    {

        i = getpid();
        j = getppid();
//        printf("\n parent process (PID :%d) created child (PID:%d)\n", j, i);
        if (j == ppp) {
            printf("\n parent process (PID :%d) created child_2 (PID:%d)\n", j, i);
            printf("\nchild_2 (PID:%d) is calling an external program external_program.out and leaving child_2â€¦\n", i);

            execl("external_program.out", "external", NULL); //go to external program


        } else {
            printf("\n child_1 process (PID :%d) created child_1.1 (PID:%d)\n", j, i);

        }

    }


    return 0;
}
