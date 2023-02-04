#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    // in this file i did learn that the parent is executeed first
    printf(" this is my id : %d\n",getpid());
    fork();
    printf(" this is my id : %d\n",getpid());
    return (0);
}