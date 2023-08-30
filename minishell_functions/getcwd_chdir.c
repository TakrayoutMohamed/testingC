#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char *strcwd;

    // close(1);
    strcwd = (char *)malloc (5550);
    printf("\nthe path of this file is :%s ,strcwd = %s\n",getcwd(strcwd, 4000), strcwd);
    printf("\nthe strcwd = %s\n",strcwd);
    system("ls");
    printf("\n-----------change the dir 111-------\n");
    chdir("..");
    printf("\nthe path of this file is :%s ,strcwd = %s\n",getcwd(strcwd, 4000), strcwd);
    printf("\nthe strcwd = %s\n",strcwd);
    system("ls");
    printf("\n-----------change the dir-------\n");
    chdir("./minishell_functions");
    printf("\nthe path of this file is :%s ,strcwd = %s\n",getcwd(strcwd, 4000), strcwd);
    printf("\nthe strcwd = %s\n",strcwd);
    system("ls");
    // system("leaks a.out");
    return (0);
}
