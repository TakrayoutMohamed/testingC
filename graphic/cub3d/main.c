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
	while (i < WIN_WIDTH - PLAYER_X)
	{
		trace_dot(vars, PLAYER_X + i, PLAYER_Y + j);
		i++;
		if (i == WIN_WIDTH - PLAYER_X)
		{
			i = 0;
			j++;
		}
		if (j == WIN_HEIGHT - PLAYER_Y)
		{
			printf("done!\n");
			break ;
		}
	}
}

int	main(void)
{
	t_data	vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (EXIT_FAILURE);
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "alvares's cub3d");
	trace_ray(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
