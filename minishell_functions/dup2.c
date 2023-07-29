#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	pid_t   cpid;
	int     ofd;
	char    *cmd, *output;

	cmd = argv[1];
	output = argv[2];
	cpid = fork();
	if (cpid == -1)
	{
		return (printf("hhhh error in fork\n"));
	}
	if (cpid == 0)
	{
		printf("Running like : %s > %s\n", cmd, output);
		ofd = creat(output, 0644);
		dup2(ofd, 1); // same as : close(1); dup(ofd);
		printf("this text is going to the file output\n");
		return(0);
	}
	wait((int *)NULL); //wait for child to finish his execution
	return (0);
}