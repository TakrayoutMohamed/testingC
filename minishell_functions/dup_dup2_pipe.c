#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUF_SIZE 10

int main(int argc, char **argv)
{
    int pfd[2]; //pipe file descriptors
    char buf[BUF_SIZE];
    ssize_t numRead;

    if (argc != 2 || strcmp(argv[1], "--help") == 0)
    {
        printf("%s string\n", argv[0]);
        exit(1);
    }
    if (pipe(pfd) == -1)
    {
        printf("pipe error");
        exit(12);
    }
    switch (fork())
    {
        case -1:
        {
            printf("fork error \n");
            exit (2);
        }
        case 0:
        {
            if (close (pfd[1]) == -1)
            {
                printf("error in close pfd[1]\n");
                exit(3);
            }
            for(;;)
            {
                numRead = read(pfd[0], buf, BUF_SIZE);
                if (numRead == -1)
                {
                    printf("error in read from pfd[0]");
                    exit(4);
                }
                if (numRead == 0)
                    break ;
                if (write (STDOUT_FILENO, buf, numRead) != numRead)
                {
                    printf("child - partial/failed write \n");
                    exit (5);
                }
            }
            write(STDOUT_FILENO, "\n",1);
            if (close(pfd[0] == -1))
            {
                printf("the close has a probleme \n");
                exit (6);
            }
            _exit(0);
        }
        default:
        {
            if (close(pfd[0]) == -1) //read end is unused
            {
                printf("the close has a probleme \n");
                exit (7);
            }
            if (write(pfd[1], argv[1],strlen(argv[1])) != strlen(argv[1]))
            {
                printf("parent - partial/failed write\n");
                exit (8);
            }
            if (close(pfd[1]) == -1)
            {
                printf("close error\n");
                exit (9);
            }
            wait(NULL); //wait for child to finish
            exit(EXIT_SUCCESS);
        }
    }
    return (0);
}
