#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid, pid1;
    pid = fork();
    /* error */
    if(pid < 0)
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    /* Child process */
    else if(pid == 0)
    {
        pid1 = getpid();
        printf("c: pid = %d\n", pid); /*A*/
        printf("c: pid1 = %d\n", pid1); /*b*/
    }
    /* Parent process */
    else
    {
        pid1 = getpid();
        printf("p: pid = %d\n", pid); /*C*/
        printf("p: pid1 = %d\n", pid1); /*D*/
        wait(NULL);
    }
    return 0;
}
