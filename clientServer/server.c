#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void handle_sigusr1(int sig)
{
    printf("siguser1");
}
void handle_sigusr2(int sig)
{
    printf("siguser2");
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    struct sigaction sa2;
    int x;

    sa.sa_flags = SA_RESTART;
    sa.sa_handler = &handle_sigusr1;
    sa2.sa_flags = SA_RESTART;
    sa2.sa_handler = &handle_sigusr2;
    
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa2, NULL);
    printf("the pid is : %d \n",getpid());
    
    // wait(0);
    // while(1);
    sleep(55555);
    return (0);
}