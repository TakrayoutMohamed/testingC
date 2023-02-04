#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void send_SIGUSR1(int a);

int main()
{
	int pid;

	if ((pid = fork()) < 0) {
		perror("Fork");
		exit(1);
	}

	if (pid == 0) {
		printf("\nhello i am the child my pid is = %d \n", getpid());
		signal(SIGUSR1, send_SIGUSR1);
	}
	else
	{
		printf("\nPARENT: sending SIGUSR1 %d myid = %d \n\n", pid, getpid());
		kill(pid, SIGUSR1);
	}
	return (0);
}

void send_SIGUSR1(int a)
{
	// signal(SIGUSR1, send_SIGUSR1);
	printf("CHILD: I have received a SIGUSR1\n");
}