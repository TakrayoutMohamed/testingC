#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(void)
{
    char *path;
    struct stat detail;
    // stat() is the same as fstat() except that it takes a file descriptor instead of file name
    // lstat is returning the information about a symbolik link rather than the linked file.
    if (stat("./../libft.so",&detail) != -1)
    {
        printf(" mode = %hu \n",detail.st_mode);
        if ((detail.st_mode & S_IFMT) == S_IFREG)
            printf("regular file\n");
        if ((detail.st_mode & S_IFMT) == S_IFLNK)
            printf("symbolic link\n");
        if ((detail.st_mode & S_IFMT) == S_IFSOCK)
            printf("socket file\n");
        if ((detail.st_mode & S_IFMT) == S_IFIFO)
            printf("named pipe\n");
        if ((detail.st_mode & S_IFMT) == S_IFDIR)
            printf("directory file\n");

        //we can use above conditions of to get files type or use the above kind
        // if (S_ISREG(detail.st_mode))
        //     printf("regular file\n");
        printf("size  = %lld \n",detail.st_size);
    }
    else 
        printf("error ");
    return (0);
}