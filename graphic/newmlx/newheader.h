#ifndef _NEWHEADER_H
# define _NEWHEADER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 500

typedef struct s_img {
	int		width;
	int		height;
	char	*path;

} t_img;

typedef struct data {
	void	*mlx;
	void	*win;
	void	*img;
} t_data;
#endif