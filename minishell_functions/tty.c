#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd, fd1;
    setbuf(stdout,NULL);
    fd = creat("alvares.txt", 0644);
    fd = open("/dev/ttys002",O_RDONLY | O_WRONLY);
    // fd = 3;
    fd1 = fd;

    if (fd == -1)
    {
        printf("the error\n");
        return(-1);
    }
    // fd = dup2(fd,1);
    // close(fd);
    printf("tty name = |%s| \nis tty = %d\ntty slot = %d\n",ttyname(fd), isatty(fd), ttyslot());
    printf(" fd1 == %d , fd = %d \n",fd1, fd);
    write(fd1, "alvares negredo fd1", 20);
    write(fd, "alvares negredo fd", 19);
    // ttyslot();
    // if (write(fd1, "ffffffff",8) == -1)
    // {
    //     printf("no way");
    // }
    return (0);
}
