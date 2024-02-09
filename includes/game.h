#ifndef GAME_H
# define GAME_H

typedef struct s_game	t_game;
typedef struct s_coord	t_coord;

# include <stdbool.h>
# include "../libft/libft.h"
# include "../includes/color.h"
# include "../includes/error.h"
# include "../includes/function.h"
# include "../includes/game.h"
# include <../minilibx-linux/mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

# define TILE 32


typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}				t_img;

typedef struct s_grp // graphique
{
	void *north;
	void *south;
	void *east;
	void *west;
	void *wall;  //temporary
	void *floor; //temporary
	// void    *floor;
	// void    *ceiling;
	// void    *item;
	// void    *door;
	void    *ennemi_one;
	// void    *ennemi_two;
}						t_grp;

typedef struct s_color
{
	int					red;
	int					green;
	int					blue;
}						t_color;

typedef struct s_texture
{
	char				*NO;
	char				*SO;
	char				*EA;
	char				*WE;
}						t_texture;

typedef struct s_coord
{
	int	x;
	int y;
}	t_coord;



typedef struct s_game
{
	char				*game_name;
	int fd; // fd of map we read with gnl
	void				*mlx_ptr;
	t_grp				*grp;
	void				*win_ptr;
	int					screen_x;
	int					screen_y;
	int					window_x;
	int					window_y;
	char				**mapfile; // whole .cub file content
	t_texture			texture;
	t_color				floor;
	t_color				ceiling;
	t_list				*mapLL;
	char				**map;
	int					mapCharHeight;
	t_coord				*playerPos;
	t_img				img;
    int                 pos; /*position in the mapfile*/
	int x;
	int y;
}						t_game;

#endif