#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int testfd(int fd, char *cmd, char *output)
{

	return (fd);
}

int main(int argc, char **argv)
{
	pid_t   cpid;
	int     ofd;
	char    *cmd, *output;

	cmd = argv[1];
	output = argv[2];
	// close(1);
	// close(0);
	ofd = dup2(ofd,5); // same as : close(1); dup(ofd);
	printf("toooop %d\n",ofd);
	cpid = fork();
	if (cpid == -1)
	{
		return (printf("hhhh error in fork\n"));
	}
	if (cpid == 0)
	{
		printf("child %d\n",ofd);
		printf("Running like : %s > %s\n", cmd, output);
		write(ofd, "hello lallla!11111\n", 20);
		ofd = creat(output, 0644);
		printf("\nthis text is going to the file output\n");
		printf("child2 %d\n",ofd);
		write(ofd, "hello lallla!\n", 15);
		return(0);
	}
	else
	{
		wait((int *)NULL); //wait for child to finish his execution
		printf("parent %d\n",ofd);
	}
	return (0);
}