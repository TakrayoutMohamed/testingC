#include <stdlib.h>
#include <stdio.h>

void foo(void)
{
    system("leaks a.out");
}

int main(void)
{
    // atexit(foo);
    char *str = getenv("TERM_SESSION_ID");
    char *str1 = getenv("alva");
    // free(str);
    printf("%s = %s\n","TERM_SESSION_ID",str);
    printf("%s = %s\n","alva=negre",str1);
    printf("%s = %s\n","negre",str1);
    return (0);
}