#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
// #include <wait.h>

int main(void)
{
    int *ptr;
    int nbr = 5;

    ptr = &nbr;
    printf("the number addr = %p value = %d\n",&nbr, nbr);
    int pid = fork();

    // printf("here is the child process\n");
    if (pid == 0)
    {
        printf("\n\n{------start child only---------\n");
        sleep(2);
        *ptr = 6;
        printf("here is the child process\n");
        printf("the number addr = %p value = %d\n",&nbr, nbr);
        printf("the pointer ptr point to addr = %p value = %d\n",ptr, *ptr);
        int *str;
        printf("\n%d\n",*(str));
        printf("\n------end child only---------}\n\n");
        fflush(stdout);
        exit(12);
        while (2);
    }
    else 
    {
        int status;
        int wait_ret;
        // printf("\n the pid = %d \n",*status);
        wait_ret = wait(&status);
        printf("\n the child process id  = %d \n",pid);
        printf("\n the wait return  = %d \n",wait_ret);
        printf("\n the status value = %d \n",status);
        printf("\n\n{------start parent only---------\n");
        printf("here is the parent process \n");
        printf("the number addr = %p value = %d\n",&nbr, nbr);
        printf("the pointer ptr point to addr = %p value = %d\n",ptr, *ptr);
        printf("\n------end parent only---------}\n\n");
        fflush(stdout);
    }
    // while (1);
    return (0);
}