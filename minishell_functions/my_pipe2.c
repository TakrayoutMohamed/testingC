#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int status;

void print_error(int errnos)
{
    printf("%s\n", strerror(errnos));
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

void	ft_pipe_middle(char *cmd1[], int *fd_in, int *fd_out)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
	{
		print_error(errno);
		exit(errno);
	}
	pid = fork();
	if (pid == -1)
	{
		print_error(errno);
		exit(errno);
	}
	else if (pid == 0)
	{
		dup2(pipe_fd[0], *fd_in);
		dup2(pipe_fd[1], *fd_out);
		close_pipe(pipe_fd);
		execve(cmd1[0], cmd1, NULL);
	}
	else
		waitpid(pid, &status, WUNTRACED);
}

void	ft_pipe_begain(char *cmd1[], int pipe1[2])
{
	int	pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)//create the pipe
	{
		print_error(errno);
	}
	pid = fork();
	if (pid == -1)
	{
		print_error(errno);
		exit(errno);
	}
	else if (pid == 0) // this is child
	{
		close(pipe_fd[0]);
        dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		execve(cmd1[0], cmd1, NULL);
	}
	else //this is parent
	{
		// close(pipe_fd[0]);
		// dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		waitpid(pid, &status, WUNTRACED);
		// dup2(pipe_fd[0], 0);
		for(;;)
		{
			char c;
			int numRead = read(0 , &c, 1);
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
		close(pipe_fd[0]);
	}
}

void	ft_pipe_end(char *cmd1[], int pipe1[])
{
	int	pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)//create the pipe
	{
		print_error(errno);
	}
	pid = fork();
	if (pid == -1)
	{
		print_error(errno);
		exit(errno);
	}
	else if (pid == 0) // this is child
	{
		close(pipe_fd[1]);
        dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		execve(cmd1[0], cmd1, NULL);
	}
	else //this is parent
	{
        close(pipe_fd[0]);
		waitpid(pid, &status, WUNTRACED);
	}
}

int main(void)
{
	int		pipe_fd[2];
	pid_t	pid;
    char *cmd1[] = {"/bin/ls", "-la",NULL};
    char *cmd2[] = {"/usr/bin/grep", "read", NULL};
    char *cmd3[] = {"/usr/bin/sort", "-r" , NULL};
    char *cmd4[] = {"/usr/bin/sort", NULL, NULL};

	// if (pipe(pipe_fd) == -1)
	// {
	// 	print_error(errno);
	// 	exit(errno);
	// }
	// pid = fork();
	// if (pid == 0)
	// {
		// dup2(pipe_fd[0], 0);
		// dup2(pipe_fd[1], 1);
		ft_pipe_begain(cmd1, pipe_fd);
		// ft_pipe_middle(cmd2, &pipe_fd[0], &pipe_fd[1]);
		ft_pipe_end(cmd2, pipe_fd);
		write(2, "hello alvares", 14);
		// close_pipe(pipe_fd);
		// close(pipe_fd[0]);
		exit(55);
	// }
	// else 
	// {
	// 	waitpid(pid, &status, WUNTRACED);
	// 	close(pipe_fd[1]);
	// 	for(;;)
	// 	{
	// 		char c;
	// 		int numRead = read(pipe_fd[0] , &c, 1);
	// 		if (numRead == -1)
	// 		{
	// 			printf("error in read from pfd[0]");
	// 			exit(4);
	// 		}
	// 		if (numRead == 0)
	// 		{
	// 			printf("EOF!\n");
	// 			break ;
	// 		}
	// 		if (write (1, &c, numRead) != numRead)
	// 		{
	// 			printf("child - partial/failed write \n");
	// 			exit (5);
	// 		}
	// 	}
	// }
    return (0);
}