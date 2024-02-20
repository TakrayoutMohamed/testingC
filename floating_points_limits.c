#include <stdio.h>

int main(int argc, char **argv)
{
    float y;
    int i = (1 << 24) - 1;
    y = i;
    printf("int i = %d , float y = %f\n", i, y);
    for (int j = 0; j < 5;j++)
    {
        printf("%d %f    ", i, y);
        printf("%08x %08x\n", i, *((int *)&y));
        y = y + 1.0;
        i = i + 1;
    }
}