#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <wait.h>
#include <string.h>

int status;

/*this function read from a fd_in's content and write it to fd_out*/
void	read_from_fd(int fd_in, int fd_out)
{

	while (1)
	{
		char	buff;
		size_t	readedbuf;
		readedbuf = read(fd_in, &buff, 1);
		if (readedbuf == -1)
		{
			exit(errno);
		}
		if (readedbuf == 0)
			break;
		write(fd_out, &buff, 1);
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

	pid2 = fork();
	if (pid2 == -1)
	{
		print_error(errno);
		exit(errno);
	}
	if (pid2 == 0)
	{
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
	}
	else
	{
		waitpid(pid2, &status, WUNTRACED);
		// close_pipe(pipe_fd);

	}
}

void ft_pipe_one_process()
{
	int p1[2];
	int p2[2];

	if (pipe(p1) == -1)
	{
		print_error(errno);
		exit(errno);
	}
	if (pipe(p2) == -1)
	{
		print_error(errno);
		exit(errno);
	}

	dup(p1[1]);
	dup(p2[1]);
	write(p1[1], "hello this is going to pipe 1\ndd", 33);
	dup2(p1[0], 0);
	// char c   = '\0';
	// write(p1[1],&c,1);
	close(p1[1]);
	close(p1[0]);
	print_error(errno);
	char	buff[2];
	size_t	readedbuf;
	while (1)
	{
		// write(2, "HHH1\n",6);
		readedbuf = read(0, &buff, 2);
		// write(2, "HHH2\n",6);
		// fprintf(stderr,"\nreadedbuf = |%ld|\n",readedbuf);
		if (readedbuf == -1)
		{
			print_error(errno);
			exit(errno);
		}
		if (readedbuf == 0)
		{
			write(2, "EOF\n",5);
			break;
		}
		if (write(p2[1], &buff, 2) != 2)
			break;
		if ((unsigned char)buff[readedbuf - 1] == '\0')
			break;
	}
	// close(p1[0]);
	write(p2[1], "hello this is going to pipe 2\nhanta", 36);
	close(p2[1]);
	while (1)
	{
		// write(2, "HHH1\n",6);
		readedbuf = read(p2[0], &buff, 2);
		// write(2, "HHH2\n",6);
		// fprintf(stderr,"\nreadedbuf = |%ld|\n",readedbuf);
		if (readedbuf == -1)
		{
			print_error(errno);
			exit(errno);
		}
		if (readedbuf == 0)
		{
			write(2, "EOF\n",5);
			break;
		}
		if (write(1, &buff, 2) != 2)
			break;
		if ((unsigned char)buff[readedbuf -1] == '\0')
			break;
	}
}

int main(void)
{
	int	pipe1[2];
	setbuf(stdout, NULL);
	// pipe(pipe1);
	// dup2(pipe1[0], 0);
	// dup2(pipe1[1], 1);
	// close_pipe(pipe1);
    char *cmd1[] = {"/bin/ls", "-la",NULL};
    char *cmd2[] = {"/usr/bin/grep", "read", NULL};
    char *cmd3[] = {"/usr/bin/sort", "-r" , NULL};
    char *cmd4[] = {"/usr/bin/sort", NULL, NULL};
    // ft_pipe_begain(cmd1, cmd2);
	ft_pipe_one_process();
    // ft_pipe_begain(cmd3, cmd4);
	// printf("\nhello\n\n");
	// read_from_fd(0, 1);
    return (0);
}