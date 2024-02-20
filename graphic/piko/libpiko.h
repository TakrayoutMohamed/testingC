#ifndef LIBPIKO_H_
#define LIBPIKO_H_
#define RIGHT_ARROW  124
#define LEFT_ARROW  123
#define TOP_ARROW  126
#define BOTTOM_ARROW  125
# define PI 3.14
# define MAP_ROWS 11
# define MAP_COLS 15
# define FRAME_SIZE 32
# define WIN_WIDTH (MAP_COLS * FRAME_SIZE)
# define WIN_HEIGHT (MAP_ROWS * FRAME_SIZE)
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <math.h>

typedef struct s_player
{
    double x;
    double y;
    double radius;
    int turnDir;
    int walkDir;
    double rotateAngle;
    double movespeed;
    double rotationSpeed;
} t_player;

typedef struct s_data
{
    void *mlx;
    void *win;
    struct s_player *player;
} t_data;
#endif
