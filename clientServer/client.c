#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
int main(int argc, char **argv)
{
    // while (1)
    {
        kill(atoi(argv[1]), SIGUSR2);
        sleep(1);
        kill(atoi(argv[1]), SIGUSR1);
        sleep(1);
    }
}