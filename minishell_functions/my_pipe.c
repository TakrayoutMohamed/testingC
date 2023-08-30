#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int status;

/*this function read from a fd_in's content and write it to fd_out*/
void	read_from_fd(int fd_in, int fd_out)
{
	// close(fd_out);
	for(;;)
	{
		char c;
		int numRead = read(fd_in , &c, 1);
		if (numRead == -1)
		{
			printf("error in read from pfd[0]");
			exit(4);
		}
		if (numRead == 0)
		{
			printf("EOF!\n");
			break ;
		}
		if (write (1, &c, numRead) != numRead)
		{
			printf("child - partial/failed write \n");
			exit (5);
		}
	}
}

void	print_error(int error_nbr)
{
	printf("%s\n",strerror(error_nbr));
}

void	close_pipe(int pipe_fd[2])
{
	if (close(pipe_fd[0]) == -1)
	{
		print_error(errno);
		exit(errno);
	}
	if (close(pipe_fd[1]) == -1)
	{
		print_error(errno);
		exit(errno);
	}
}

void	ft_pipe_begain(char *cmd1[], char *cmd2[])
{
	int	pipe_fd[2];
	// int	pipe_fd2[2];
	pid_t	pid;
	pid_t	pid2;

	// pid2 = fork();
	// if (pid2 == -1)
	// {
	// 	print_error(errno);
	// 	exit(errno);
	// }
	// if (pid2 == 0)
	// {
		if (pipe(pipe_fd) == -1)//create the pipe
		{
			print_error(errno);
		}
		pid = fork();
		if (pid == -1)
		{
			print_error(errno);
			exit(status);
		}
		else if (pid == 0) // this is child
		{
			dup2(pipe_fd[1], 1);
			dup2(pipe_fd[0], 0);
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			execve(cmd1[0], cmd1, NULL);
		}
		else //this is parent
		{
			dup2(pipe_fd[0], 0);
			close_pipe(pipe_fd);
			waitpid(pid, &status, WUNTRACED);
			execve(cmd2[0], cmd2, NULL);
		}
	// }
	// else
	// {
	// 	waitpid(pid2, &status, WUNTRACED);
	// 	// close_pipe(pipe_fd);

	// }
}

int main(void)
{
	int	pipe1[2];
	setbuf(stdout, NULL);
	int file = open("file.txt", O_CREAT | O_RDWR, 0777);
	pipe(pipe1);
    char *cmd1[] = {"/bin/ls", "-la",NULL};
    char *cmd2[] = {"/usr/bin/grep", "read", NULL};

	// dup2(pipe1[1], 1);
	// dup2(pipe1[0], 0);
    ft_pipe_begain(cmd1, cmd2);
	printf("\nhello\n\n");
	// close(pipe1[1]);
	// read_from_fd(0, 1);

	for(;;)
	{
		char c;
		int numRead = read(pipe1[0] , &c, 1);
		if (numRead == -1)
		{
			printf("error in read from pfd[0]");
			exit(4);
		}
		if (numRead == 0)
		{
			printf("EOF!\n");
			break ;
		}
		if (write (2, &c, numRead) != numRead)
		{
			printf("child - partial/failed write \n");
			exit (5);
		}
	}
	// write(file, "hekkkk",6);
    return (0);
}
