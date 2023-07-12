#include <stdio.h>
#include <stdlib.h>
// #include <readline.h>
#include <readline/readline.h>
#include <readline/history.h>

void leaks_test(void)
{
    system("leaks a.out");
}
int main(int argc, char **argv)
{
    atexit(leaks_test);
    char *str;


    str = readline("alvares");
    str = readline("alvares");
    printf("|%s| \n",str);
    return (0);
}

//