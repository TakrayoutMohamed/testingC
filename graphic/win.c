#include "header.h"
int j;
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

    // printf("data->bits_per_pixel = %d\n",data->bits_per_pixel);
    // printf("data->line_length = %d\n",data->line_length);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
// int	close(int keycode, t_vars *vars)
// {
//     // (void)keycode;
//     printf("key code = %d",keycode);
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

int press_key(int keycode)
{
    printf("the key code = %d \n", keycode);
    return (0);
}

int press_mouse(int keycode)
{
    printf("the mouse key is : %d\n", keycode);
    return (0);
}

int render_next_frame()
{
    printf("here is the loop hook %d\n",j++);
    return (0);
}

int main(void)
{
    // t_vars  *vars;
    t_data ex;
    // t_data  img;
    // char	*relative_path = ;
    int i = 0;
    int		img_width;
	int		img_height;
    // t_vars *ptr;
    ex.mlx = mlx_init();
    ex.win = mlx_new_window(ex.mlx, 800, 600, "hello alvares");
    ex.img = mlx_new_image(ex.mlx, 400, 400);
    ex.addr = mlx_get_data_addr(ex.img, &ex.bits_per_pixel, &ex.line_length, &ex.endian);

    while(i < 20)
    {
        my_mlx_pixel_put(ex.img, 50 + i, 50, 0x00FF0000);
        // sleep(1);
        i++;
    }
    // mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    /*x_mask argument of mlx_hook is useless, keep it at 0*/
    // mlx_hook(vars.win, ON_KEYDOWN, 0, close, &vars);


    /*even it looks a new function but it only calls the function mlx_hook() 
        with the appropriate X11 event types*/
    mlx_key_hook(ex.win, press_key, &ex);

    mlx_mouse_hook(ex.win, press_mouse, &ex);

    /*mlx_loop_hook */
    // mlx_loop_hook(ex.mlx, render_next_frame, &ex);
    printf("hello\n");
    void *ptr;
    ptr = mlx_xpm_file_to_image(ex.mlx, "./textures/raccoon_32x32.xpm", &img_width, &img_height);
    mlx_put_image_to_window(ex.mlx,ex.win,ptr,32 ,32);
    
    mlx_loop(ex.mlx);
    return 0;
}
