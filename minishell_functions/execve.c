#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argva, char **env)
{
    char *str = "script.bash";
    char *argv[] = {NULL, NULL};

    // while (*env)
    // {
    //     printf("%s\n", *env);
    //     env++;
    // }
    printf("%s\n", "ffffffffffffffffffffff");
    execve(argv[0], argv, NULL);
    return (0);
}
