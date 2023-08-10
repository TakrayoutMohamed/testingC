#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    printf("the file access is : %d\n",access("./test.txt", X_OK|F_OK|W_OK|R_OK));
    printf("%s\n",strerror(errno));
    return (0);
}