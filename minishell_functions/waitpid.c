#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
    int nbr = 5;
    setbuf(stdout, NULL);
    printf("the number addr = %p value = %d\n",&nbr, nbr);
    int pid = fork();
    int pid1;
    // if (pid != 0)
        pid1 = fork();
    if (pid == 0 && pid1 != 0)
    {
        waitpid(pid1, &nbr, WUNTRACED);
        printf("\n\n ________________start 1 a child process________\n\n");
        printf("here is the first child pid = %d\n",getpid());
        printf("\n\n ________________end 1 a child process________\n");
    }
    if (pid1 == 0 && pid != 0)
    {
        printf("\n\n ________________start 2 a child process________\n\n");
        printf("here is the second child pid = %d\n",getpid());
        printf("\n\n ________________end 2 a child process________\n");
        // while (1);
    }
    if (pid != 0 && pid1 != 0)
    {
        int res_ret = waitpid(pid, &nbr, WUNTRACED);
        printf("\nthe first ends here with return %d\n",res_ret);
        // waitpid(0, &nbr, WUNTRACED);
        // waitpid(pid1, &nbr, nbr);
        printf("\n\n ________________start a parent process________\n\n");
        printf("here is the parent process pid = %d\n",getpid());
        printf("\n\n ________________end a parent process________\n");
    }
    if (pid1 == 0 && pid == 0)
    {
        // sleep(5);
        wait(NULL);
        printf("\nhere is the lost process\n");
    }
    // sleep(6);
    while (4);
    return (0);
}