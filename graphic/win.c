#include "header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

    // printf("data->bits_per_pixel = %d\n",data->bits_per_pixel);
    // printf("data->line_length = %d\n",data->line_length);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	close(int keycode, t_vars *vars)
{
    // (void)keycode;
    printf("key code = %d",keycode);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int press_key(int keycode)
{
    printf("hello world key code = %d \n", keycode);
    return (0);
}

int press_mouse(int keycode)
{
    printf("the key is : %d\n", keycode);
    return (0);
}

int render_next_frame()
{
    printf("here is the loop hook\n");
    return (0);
}

int main(void)
{
    t_vars  vars;
    t_data  img;
    int     i = 0;
    char	*relative_path = "./../../racoon.png";

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 800, 600, "hello alvares");
    img.img = mlx_new_image(vars.mlx, 400, 400);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    // while(i < 20)
    // {
    //     my_mlx_pixel_put(&img, 50 + i, 50, 0x00FF0000);
    //     // sleep(1);
    //     i++;
    // }
    // mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    /*x_mask argument of mlx_hook is useless, keep it at 0*/
    // mlx_hook(vars.win, ON_KEYDOWN, 0, close, &vars);


    /*even it looks a new function but it only calls the function mlx_hook() 
        with the appropriate X11 event types*/
    // mlx_key_hook(vars.win, press_key, &vars);

    // mlx_mouse_hook(vars.win, press_mouse, &vars);

    /*mlx_loop_hook */
    // mlx_loop_hook(vars.mlx, render_next_frame, &vars);


    img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img.img_width, &img.img_height);


    mlx_loop(vars.mlx);
    return 0;
}
