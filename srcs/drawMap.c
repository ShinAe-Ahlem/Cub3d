
#include "includes/game.h"

int mapX=8, mapY=8, mapS=64;
int map[] =
{
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
};

void drawMap2D(t_game *game)
{
	int x;
	int y;
	// int x0;
	// int y0;

	y = 0;
	while(y < mapY)
	{
		x = 0;
		while(x < mapX)
		{	
			if (map[y *mapX + x] == 1)
				mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, create_rgb(1,1,1));
			else
				mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, create_rgb(0,0,0));
			
			x++;
		}
		y++;
	}
}