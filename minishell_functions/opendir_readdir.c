#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(void)
{
    DIR *dir = opendir(".");
    struct dirent* entity;

    if (dir == NULL)
    {
        return (1);
    }
    entity = readdir(dir);
    while (entity != NULL)
    {
        if (strcmp(entity->d_name, ".") && strcmp(entity->d_name, ".."))
            printf("%s\n",entity->d_name);
        entity = readdir(dir);
    }
    closedir(dir);
    return (0);
}
