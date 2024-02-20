#include "./libpiko.h"

void	draw_dot(int x, int y, int color, t_data *data)
{
	mlx_pixel_put(data->mlx, data->win, x, y, color);
}

void	trace_ray(t_data *vars)
{
	int	i;
	int	j;


	i = 0;
	j = 0;
	while (j < vars->player->radius)
	{
		draw_dot(vars->player->x + i, vars->player->y, 0x00FFFF, vars);
		// printf("x = %d, y = %d\n", vars->player->x + i, vars->player->y);
		i++;
		j++;
	}
	printf("done!\n");
}

void	draw_rec(int x, int y, int color, t_data *data)
{
	int i, j;

	// x = x + 1;
	i = 1;
	while (i < FRAME_SIZE)
	{
		j = 1;
		while (j < FRAME_SIZE)
		{
			draw_dot(x + i, y + j, color, data);
			j++;
		}
		i++;
	}
}

void	draw_player(int width_size, int hieght_size, int color, t_data *data)
{
	int i, j;

	i = 1;
	while (i < width_size)
	{
		j = 1;
		while (j < hieght_size)
		{
			draw_dot(data->player->x + i, data->player->y + j, color, data);
			j++;
		}
		i++;
	}
	i = 1;
	while (i < 20)
	{
		draw_dot(data->player->x - (hieght_size / 2) + i, data->player->y - (hieght_size / 2) , color, data);
		i++;
	}
}


//pow(x - i , 2) +
void	draw_circle(int x_, int y_, int color, t_data *data)
{
	int i;
	int j;
	double x;
	double y;
	int	tmp_y_player;
	int	tmp_x_player;

	tmp_x_player = data->player->x;
	tmp_y_player = data->player->y;
	i = -180;
	// here is the radius of the circle
	trace_ray(data);
	// here is the center of the circle
	draw_dot(data->player->x, data->player->y, 0xFFFFFF, data);
	while (i < 180)
	{
		x = data->player->x + i;
		y = pow(data->player->radius, 2) - pow(x - data->player->x, 2);
		if (y >= 0)
		{
			y = data->player->y + sqrt((int)abs((int)y));
			draw_dot((int)x, (int)y, 0x00FFFF, data);
			draw_dot((int) (2 * data->player->x - x), (int)y, 0x00FFFF, data);
			draw_dot((int) x, (int)(2 * data->player->y - y), 0x00FFFF, data);
		}
		i++;
	}

		// x = 5;
		// y = data->player->y;
		// y += (data->player->radius * data->player->radius) - ((x - data->player->x) * (x - data->player->x) );
		
		// y = sqrt((int)abs((int)y));
		// printf("x = %f, y = %f\n", x, y);
		// printf("player x = %f, player y = %f\n", data->player->x,data->player->y);
		// draw_dot((int)x, (int)y, 0xFFFFFF, data);
}

void	draw_2dmap(char **map, t_data *data)
{
	int i, j;
	int color;
	char m[11][15] = {
		{"111111111111111"},
		{"100000000100001"},
		{"100000000100101"},
		{"100111111100101"},
		{"100000000000101"},
		{"100000000000101"},
		{"101111111000101"},
		{"100000000000101"},
		{"100000100100101"},
		{"100000100100101"},
		{"111111111111111"}
	};

	(void)map;
	i = 0;
	while (i < MAP_ROWS)
	{
		j = 0;
		while (j < MAP_COLS)
		{
			if (m[i][j] == '1')
				color = 0xFFFFFF;
			else
				color = 0x000000;
			draw_rec(j * FRAME_SIZE + 1, i * FRAME_SIZE + 1, color, data);
			j++;
		}
			// return;
		i++;
	}
}

t_player	*player_init(void)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	player->x = WIN_WIDTH / 2;
	player->y = WIN_HEIGHT / 2;
	player->radius = 100;
	player->turnDir = 0;
	player->walkDir = 0;
	player->rotateAngle = PI / 2;
	player->movespeed = 2.0;
	player->rotationSpeed = 2 * (PI / 180);
	return (player);
}

void display_player(t_data *data)
{
	// trace_ray(data);
	draw_player(10,10, 0x00F000, data);
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
			// vars->angle = vars->angle + 0.01;
			printf("the right arrow pressed \n");
		}
		else if (key == LEFT_ARROW)
		{
			// vars->angle = vars->angle - 0.01;
			printf("the left arrow pressed \n");
		}
		// trace_right_ray(vars);
	}
	else if (key == TOP_ARROW || key == BOTTOM_ARROW)
	{
		if (key == TOP_ARROW)
		{
			vars->player->y -= 1 * vars->player->movespeed;
			printf("the top arrow pressed \n");
		}
		else if (key == BOTTOM_ARROW)
		{
			vars->player->y += 1 * vars->player->movespeed;
			printf("the bottom arrow pressed \n");
		}
	}
	draw_2dmap(NULL, vars);
	display_player(vars);
	return (0);
}

int main(void)
{
	t_data  vars;
	vars.mlx = mlx_init();
	// open the window
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "alvaresssssss!");
	// set plater data;
	vars.player = player_init();
	draw_2dmap(NULL, &vars);
	display_player(&vars);
	mlx_key_hook(vars.win, &handle_keypress, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
