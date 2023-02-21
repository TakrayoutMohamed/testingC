#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <mlx.h>
int main(void)
{
    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 2000, 1000, "hello alvares");
    mlx_loop(mlx);
    return 0;
}