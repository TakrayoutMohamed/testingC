#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
    int status;
    pid_t pid;
    struct rusage *usage;
    wait3(&status, status, usage);
    return (0);
}
