#include <stdio.h>
#include <stdlib.h>
// #include <readline.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>

/* Used for select(2) */
#include <sys/types.h>
#include <sys/select.h>

#include <signal.h>

#include <stdio.h>

/* Standard readline include files. */
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
    int i = 1;

    while (i)
    {
        str = readline("alvares SHILL > ");
        // str = readline("alvares");
        add_history(str);
        printf("|%s| \n",str);
        i++;
    }
    rl_clear_history();
    str = readline("\ndone !");
    return (0);
}

//