#include "newheader.h"
#define MLX_ERROR 1
#define RIGHT_ARROW  124
#define LEFT_ARROW  123
#define TOP_ARROW  126
#define BOTTOM_ARROW  125

int i = 0;
int render(t_data *data)
{
	if (data->win != NULL)
	{
		mlx_pixel_put(data->mlx, data->win, WINDOW_WIDTH / 2 + i++, WINDOW_HEIGHT / 2, 0xFF0000);
		// printf("%d\n",i);
	}
	else
	{
		// printf(" ++++%d\n",i++);
		exit(0);
	}
	return (0);
}
void setImage(char *str,int width, int height, t_img *param)
{
	param->path = str;
	param->width = width;
	param->height = height;
}
int	handle_keypress(int keysym, t_data *data)
{
	/*note that the key 53 is ESC*/
	if (keysym == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		// here you need to free all what is runing
		exit(0);
	}
	/*the right arrow of the keyboard is 124*/
	if (keysym == RIGHT_ARROW)
	{
		t_img	racoon;
		t_img	student;

		setImage(
			"/Users/mohtakra/Desktop/testingC/graphic/textures/raccoon_32x32.xpm",
			32,
			32,
			&racoon
		);
		setImage(
			"/Users/mohtakra/Desktop/testingC/graphic/textures/student/student_32x32.xpm",
			32,
			32,
			&student
		);
		data->img = mlx_xpm_file_to_image(data->mlx, racoon.path, &racoon.width, &racoon.height);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 100 + i, 100);

		data->img = mlx_xpm_file_to_image(data->mlx, student.path, &student.width, &student.height);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 100 + i - 32, 100);
		
		printf("i = %d\n",i);
	}
	/*the left arrow of the keyboard is 124*/
	else if (keysym == LEFT_ARROW)
	{
		t_img	imgs;

		setImage(
			"/Users/mohtakra/Desktop/testingC/graphic/textures/raccoon_32x32.xpm",
			32,
			32,
			&imgs
		);
		data->img = mlx_xpm_file_to_image(data->mlx, imgs.path, &imgs.width, &imgs.height);
		// while ((i * imgs.width) < WINDOW_WIDTH)
		// {
			mlx_put_image_to_window(data->mlx, data->win, data->img, 100 - i, 100);
			printf("i = %d\n",i);
		// }
			// printf("xi = %d\n",i);
	}
	/*the bottom arrow of the keyboard is 124*/
	else if (keysym == BOTTOM_ARROW)
	{
		t_img	imgs;

		setImage(
			"/Users/mohtakra/Desktop/testingC/graphic/textures/raccoon_32x32.xpm",
			32,
			32,
			&imgs
		);
		data->img = mlx_xpm_file_to_image(data->mlx, imgs.path, &imgs.width, &imgs.height);
		// while ((i * imgs.width) < WINDOW_WIDTH)
		// {
			mlx_put_image_to_window(data->mlx, data->win, data->img, 100, 100 + i);
			printf("i = %d\n",i);
		// }
			// printf("xi = %d\n",i);
	}
	/*the top arrow of the keyboard is 124*/
	else if (keysym == TOP_ARROW)
	{
		t_img	imgs;

		setImage(
			"/Users/mohtakra/Desktop/testingC/graphic/textures/raccoon_32x32.xpm",
			32,
			32,
			&imgs
		);
		data->img = mlx_xpm_file_to_image(data->mlx, imgs.path, &imgs.width, &imgs.height);
		// while ((i * imgs.width) < WINDOW_WIDTH)
		// {
			mlx_put_image_to_window(data->mlx, data->win, data->img, 100, 100 - i);
			printf("i = %d\n",i);
		// }
			// printf("xi = %d\n",i);
	}
	i = i + 32;
	printf("key hoooooook keysym = %d\n",keysym);
	return (0);
}



void	setWall(t_data vars)
{
	t_img	imgs;

	setImage(
		"/Users/mohtakra/Desktop/testingC/graphic/textures/raccoon_32x32.xpm",
		32,
		32,
		&imgs
	);
	vars.img = mlx_xpm_file_to_image(vars.mlx, imgs.path, &imgs.width, &imgs.height);
	while ((i * imgs.width) < WINDOW_WIDTH)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img, i * imgs.width, 0);
		printf("i = %d\n",i++);
	}
		printf("xi = %d\n",i);
}

int main(void)
{
	t_data  vars;
	// t_img	imgs;

	printf("\a\a\a\a\a\a\a\a\a");
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (MLX_ERROR);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "alvares");
	if (vars.win == NULL)
	{
		free(vars.mlx);
		return (MLX_ERROR);
	}
	// mlx_loop_hook(vars.mlx, render, &vars);
	mlx_key_hook(vars.win, &handle_keypress, &vars);

	setWall(vars);
	
	printf("ok");
	// sleep(4);
	mlx_loop(vars.mlx);
	// free(vars.mlx);
	return (0);
}
