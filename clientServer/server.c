#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void handle_sigusr(int sig)
{
    if (sig == SIGUSR1)
        // printf("1");
        write(1, "1", 2);
    if (sig == SIGUSR2)
        write(1, "0", 2);
        // printf("0");
}
// void handle_sigusr2(int sig)
// {
//     printf("siguser2");
// }

int main(int argc, char **argv)
{
    struct sigaction sa;
    // struct sigaction sa2;
    int x;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_handler = &handle_sigusr;
    // sa2.sa_flags = SA_SIGINFO;
    // sa2.sa_handler = handle_sigusr2;
    
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    printf("the pid is : %d \n",getpid());
    
    // wait(NULL);
    while(1)
        sleep(1);
    return (0);
}