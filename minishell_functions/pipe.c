#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
int status;
void    execut_close_pout(char *cmd[], int p_out)
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        execve(cmd[0],cmd , NULL);
    }
    else
    {
        waitpid(pid, &status, WUNTRACED);
        close(p_out);
    }
}
void    execut_close_pin(char *cmd[], int p_in)
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        execve(cmd[0],cmd , NULL);
    }
    else
    {
        waitpid(pid, &status, WUNTRACED);
        close(p_in);
    }
}

int main(void)
{
    setbuf(stdout, NULL);
    char str[20];
    char buf[20];
    int p_fd[2];
    int p_fd2[2];
    int numRead;
    pipe(p_fd);
    int pid = fork();
    if (pid == 0)
    {
        char    *argv[] = {"/bin/ls", "-la", NULL};
        dup2(p_fd[1], 1);
        dup2(p_fd[0], 0);
        close(p_fd[0]);
        close(p_fd[1]);
        execve("/bin/ls",argv , NULL);
        // execut_close_pout(argv, p_fd[1]);
    }
    else
    {
        wait(NULL);
        pipe(p_fd2);
        int pid2 = fork();
        if (pid2 == 0)
        {
            //here we need to read from the p_fd than print to p_fd2
            dup2(p_fd[0], 0);
            dup2(p_fd2[1], 1);
            close(p_fd[0]);
            close(p_fd[1]);
            close(p_fd2[0]);
            close(p_fd2[1]);
            fprintf(stderr," p_fd 0 = %d ,p_fd 1 = %d \n", p_fd[0], p_fd[1]);
            char    *argv[] = {"/usr/bin/grep", "a.out", NULL};
            // close(p_fd[0]);
            execve(argv[0],argv , NULL);
            // execut_close_pin(argv, p_fd[0]);
        }
        else
        {
            close(p_fd[0]);
            close(p_fd[1]);
            close(p_fd2[1]);
            waitpid(pid2, &status, WUNTRACED);
            printf("jjjjjjj\n");
            for(;;)
            {
                numRead = read(p_fd2[0], buf, 20);
                if (numRead == -1)
                {
                    printf("error in read from pfd[0]");
                    exit(4);
                }
                if (numRead == 0)
                {
                    // close(p_fd[0]);
                    printf("EOF!\n");
                    break ;
                }
                if (write (STDOUT_FILENO, buf, numRead) != numRead)
                {
                    printf("child - partial/failed write \n");
                    exit (5);
                }
            }
        }
            printf("the value writed is :%s",str);
    }
}