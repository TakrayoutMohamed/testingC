#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
int main(int argc, char **argv)
{
    kill(atoi(argv[1]), SIGUSR1);
    kill(atoi(argv[1]), SIGUSR2);
}