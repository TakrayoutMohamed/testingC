#ifndef LIBCUB3D_H
# define LIBCUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <mlx.h>
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define PLAYER_X WIN_WIDTH/2
# define PLAYER_Y WIN_HEIGHT/2

typedef struct data {
	void	*mlx;
	void	*win;
	void	*img;
} t_data;

#endif
