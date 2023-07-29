#include <stdio.h>
#include <stdlib.h>
// #include <readline.h>
#include <readline/readline.h>
#include <readline/history.h>

void leaks_test(void)
{
    system("leaks a.out");
}
int main(int argc, char **argv, char **env)
{
    while (*env)
    {
        printf("%s\n",*env);
        env++;
    }
    exit(0);
    atexit(leaks_test);
    char *str;
    int i = 1;

    while (i < 5)
    {
        str = readline("alvares SHELL > ");
        // str = readline("alvares");
        free(str);
        add_history(str);
        printf("|%s| \n",str);
        i++;
    }
    clear_history();
    str = readline("\ndone !");
    free(str);
    return (0);
}

//