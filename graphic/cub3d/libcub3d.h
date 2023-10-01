#ifndef LIBCUB3D_H
# define LIBCUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <string.h>
# include <mlx.h>
# define PI 3.14
#define RIGHT_ARROW  124
#define LEFT_ARROW  123
#define TOP_ARROW  126
#define BOTTOM_ARROW  125
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define PLAYER_X WIN_WIDTH/2
# define PLAYER_Y WIN_HEIGHT/2

typedef struct data {
	int		x_player;
	int		y_player;
	float	angle;
	void	*mlx;
	void	*win;
	void	*img;
} t_data;

#endif
