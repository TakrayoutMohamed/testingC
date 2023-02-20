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
void old_handle_sigusr(int sig)
{
    if (sig == SIGUSR1)
        // printf("1");
        write(1, "2", 2);
    if (sig == SIGUSR2)
        write(1, "3", 2);
        // printf("0");
}
// void handle_sigusr2(int sig)
// {
//     printf("siguser2");
// }

void	test(int sig, siginfo_t *info, void *uap)
{
    static int  firstpid;
	if (sig == SIGUSR1)
        // printf("1");
        write(1, "1", 2);
    if (sig == SIGUSR2)
        write(1, "0", 2);
    if (!firstpid)
    {
        firstpid = info->si_pid;
    }
    else if (info->si_pid != firstpid)
    {
        // sigemptyset();
        firstpid = info->si_pid;
    }
    printf("\n si_errno = %d \n",info->si_errno);
    printf("\n si_pid = %d \n",info->si_pid);
    printf("\n si_signo = %d \n",info->si_signo);
    printf("\n si_code = %d \n",info->si_code);
    printf("\n si_uid = %d \n",info->si_uid);
    printf("\n si_status = %d \n",info->si_status);
    printf("\n *si_addr = %p \n",info->si_addr);
    printf("\n si_value = %d \n",info->si_value);
    // printf("0");
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    // struct sigaction sa2;
    int x;

    sa.sa_flags = SA_SIGINFO;
    // sa.sa_mask = ;
    // sa.sa_handler = &handle_sigusr;
    sa.__sigaction_u.__sa_sigaction = test; // <==> sa.sa_sigaction = test
    
    // sa2.sa_flags = SA_SIGINFO;
    // sa2.sa_handler = handle_sigusr2;
    
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    printf("the pid is : %d \n",getpid());
    while(1)
        sleep(1);
    return (0);
}