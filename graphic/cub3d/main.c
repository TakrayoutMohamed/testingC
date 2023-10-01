# include "./libcub3d.h"

void	trace_dot(t_data *vars, int x,int y)
{
	mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFFFFFF);
}

void	trace_ray(t_data *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < WIN_WIDTH - 100)
	{
		vars->y_player = sqrt(pow((vars->x_player + i) / cos(vars->angle), 2) - pow(vars->x_player + i, 2));
		if (vars->y_player > WIN_HEIGHT - 20)
		{
			break ;
		}
		trace_dot(vars, vars->x_player + i, vars->y_player);
		i++;
	}
	vars->y_player = 0;
	printf("done!\n");
}

void	trace_view(t_data *vars)
{
	int	i;

	i = 0;
	vars->angle = 0;
	while (i++ < 1100)
	{
		trace_ray(vars);
		vars->angle = vars->angle + 0.01;
	}
}

int	handle_keypress(int key, t_data *vars)
{
	(void) vars;
	if (key == 53)
	{
		printf("ESC pressed \nexit\n");
		exit(0);
	}
	else if (key == RIGHT_ARROW || key == LEFT_ARROW)
	{
		if (key == RIGHT_ARROW)
		{
			vars->angle = vars->angle + 0.01;
			printf("the right arrow pressed \n");
		}
		else if (key == LEFT_ARROW)
		{
			vars->angle = vars->angle - 0.01;
			printf("the left arrow pressed \n");
		}
		printf(" angle = %f\n", vars->angle);
		trace_ray(vars);
	}
	return (0);
}


int	main(void)
{
	t_data	vars;

	vars.mlx = mlx_init();
	// the player is in the top left corner (0,0)
	vars.x_player = 0;
	vars.y_player = 0;
	vars.angle = 3.14;
	if (vars.mlx == NULL)
		return (EXIT_FAILURE);
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "alvares's cub3d");
	// trace_ray(&vars);
	trace_view(&vars);
	// mlx_loop_hook(vars.mlx, render, &vars);
	mlx_key_hook(vars.win, &handle_keypress, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
