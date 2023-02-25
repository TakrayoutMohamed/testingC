#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <unistd.h>
#include <mlx.h>
typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int		img_width;
	int		img_height;
}   t_data;

typedef struct s_vars {
    void    *mlx;
    void    *win;
}       t_vars;

/*this used only while you are working with events*/
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};