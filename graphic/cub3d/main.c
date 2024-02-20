# include "./libcub3d.h"

void	trace_dot(t_data *vars, int x,int y)
{
	mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFFFFFF);
}

void	trace_right_ray(t_data *vars)
{
	int	i;
	int	j;
	int	tmp_y_player;

	i = 0;
	j = 0;
	tmp_y_player = vars->y_player;
	while (i < WIN_WIDTH - vars->x_player - 100)
	{
		vars->y_player = sqrt(pow((vars->x_player + i) / cos(vars->angle), 2) - pow(vars->x_player + i, 2));
		if (vars->y_player > WIN_HEIGHT - 20)
		{
			break ;
		}
		trace_dot(vars, vars->x_player + i, vars->y_player);
		i++;
	}
	vars->y_player = tmp_y_player;
	printf("done!\n");
}

void	trace_view(t_data *vars)
{
	int	i;

	i = 0;
	vars->angle = 0;
	while (i++ < 1100)
	{
		trace_right_ray(vars);
		vars->angle = vars->angle + 0.01;
	}
	vars->angle = 0;
}

void	trace_vecteur_of_view(t_data *vars)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		trace_dot(vars, vars->x_player - i, vars->y_player - i);
		i++;
	}
}

int	handle_keypress(int key, t_data *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
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
		trace_right_ray(vars);
	}
	else if (key == TOP_ARROW || key == BOTTOM_ARROW)
	{
		if (key == TOP_ARROW)
		{
			vars->y_player = vars->y_player + 1;
			printf("the top arrow pressed \n");
		}
		else if (key == BOTTOM_ARROW)
		{
			vars->y_player = vars->y_player - 1;
			printf("the bottom arrow pressed \n");
		}
		printf(" angle = %f\n", vars->angle);
	}
	trace_vecteur_of_view(vars);
	mlx_pixel_put(vars->mlx, vars->win, vars->x_player, vars->y_player, 0x00FFFF);
	return (0);
}


int	main(void)
{
	t_data	vars;

	vars.x_player = WIN_WIDTH / 2;
	vars.y_player = WIN_WIDTH / 2;
	vars.angle = 0;
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (EXIT_FAILURE);
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "alvares's cub3d");
	trace_dot(&vars, vars.x_player, vars.y_player);
	trace_vecteur_of_view(&vars);
	// trace_right_ray(&vars);
	// trace_view(&vars);
	// mlx_loop_hook(vars.mlx, &handle_keypress, &vars);
	mlx_key_hook(vars.win, &handle_keypress, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
