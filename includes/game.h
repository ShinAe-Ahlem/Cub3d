#ifndef GAME_H
# define GAME_H

typedef struct s_game	t_game;
typedef struct s_coord	t_coord;

# include <stdbool.h>
# include "../libft/libft.h"
# include "../includes/color.h"
# include "../includes/error.h"
# include "../includes/function.h"
# include <stdlib.h>
# include "../includes/game.h"
# include <../minilibx-linux/mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# define TILE 32
# define PI 3.1415926535
# define P2 PI/2
# define P3 3*PI/2
#define texWidth 64
#define texHeight 64
#define WIDTH 920
#define HEIGHT 700

// #define WINDOW_WIDTH 600
// #define WINDOW_HEIGHT 300

typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}				t_img;

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
	void				**tex; // tableaux pour les xpm;
	int 				**texAddress; // addresse des xpm pour recuperer les pixel plutard
	void				*win_ptr;
	int					screen_x;
	int					screen_y;
	int					window_x;
	int					window_y;
	char				**mapfile; // whole .cub file content
	t_texture			*texture;
	t_color				floor;
	t_color				ceiling;
	t_list				*mapLL;
	char				**map;
	int					mapCharHeight;
	int					maxMapWidth;
	t_coord				*playerPos;
	t_coord				*playerPosDelta;
	float				playerAngle;
	t_coord				*cameraPlane;
	t_coord				*direction;
	t_img				*img;
    int                 pos; /*position in the mapfile*/
	int 				x;
	int 				y;
	double				dirX;
	double				dirY;
	double				planeX;
	double				planeY;
	double				cameraX;
	double				cameraY;
	double				rayDirX;
	double				rayDirY;
	int 				mapX; //which box in the map we're in
	int					mapY;
	double				sideDistX; //length of ray from current position to next x or y side
	double				sideDistY;
	double 				deltaDistX; //length of ray from one x or y side to the next x or y side
	double 				deltaDistY;
	double				perpWallDist;
	double				stepX; // what direction to step in x or y direction (either +1 or -1)
	double				stepY;
	double				posX; // player position
	double				posY;
	int					side; //was a NS or a EW wall hit?
	int					lineHeight;
	int					drawStart;
	int					drawEnd;
	double 				wallX; // where exactly the wall was hit
	double				step;
	double				texPos;
	int					texX;
	int					texY;
	char				**texFiles;
	int					dir;
	int					bpp[4];
	int					line_len[4];
	int					endian[4];
	char				**texLines;
	int					width[4];
	int					height[4];
	int **texg;
}						t_game;

#endif