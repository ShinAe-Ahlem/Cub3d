
#ifndef GAME_H
# define GAME_H

typedef struct s_game t_game;

#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <../minilibx-linux/mlx.h>
#include "../includes/game.h"
#include "../libft/libft.h"
#include "../includes/function.h"
#include "../includes/error.h"
#include "../includes/color.h"
#include <errno.h>


typedef struct s_grp // graphique
{
    void    *north;
    void    *south;
    void    *east;
    void    *west;
    // void    *floor;
    // void    *ceiling;
    // void    *item;
    // void    *door;
    // void    *ennemi_one;
    // void    *ennemi_two;
}   t_grp;


typedef struct s_game
{
    char *game_name;
    int fd; // fd of map we read with gnl
    void    *mlx_ptr;
    t_grp   grp;
    void	*win_ptr;
    int screen_x;
    int screen_y;
    int window_x;
    int window_y;
    char    **map;
}   t_game;


#endif