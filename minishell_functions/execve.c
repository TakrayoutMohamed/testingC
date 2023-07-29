#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argva, char **arge)
{
    char *str = "   ";
    char *argv[] = {"/usr/bin/env" , NULL, NULL};

    while (*arge)
    {
        printf("%s\n", *arge);
        arge++;
    }
    printf("%s\n", "ffffffffffffffffffffff");
    execve(argv[0], argv, NULL);
    return (0);
}
