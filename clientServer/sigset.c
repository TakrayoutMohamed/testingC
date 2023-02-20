#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int main()
{
    sigset_t    set1;
    int ret;

    ret = sigemptyset(&set1);
    ret = sigaddset(&set1, 1);
    ret = sigaddset(&set1, 2);
    ret = sigaddset(&set1, 7);
    ret = sigaddset(&set1, 8);
    
    ret = sigaddset(&set1, 9);
    ret = sigaddset(&set1, 10);
    ret = sigaddset(&set1, 11);
    ret = sigaddset(&set1, 12);
    ret = sigaddset(&set1, 13);
    // ret = sigaddset(&set1, 14);
    // ret = sigaddset(&set1, 15);
    ret = sigaddset(&set1, 16);
    printf("%d\n", set1);
    printf("i%ci\n", set1);
    write(1,&set1, 2);
    // write(1, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempordddddddddddddddddddddd")
    return (0);
}