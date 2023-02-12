#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int main()
{
    sigset_t    set1;
    int ret;

    ret = sigemptyset(&set1);
    ret = sigaddset(&set1, 9);
    // ret = sigaddset(&set1, 1);
    // ret = sigaddset(&set1, 2);
    printf("%u", set1);
    return (0);
}