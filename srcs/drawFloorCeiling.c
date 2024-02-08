#include "../includes/game.h"

// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }


void	my_mlx_pixel_put(t_img *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}


/*screen is divided to two parts*/
/*Floor => bottom half
Ceiling => above half*/



void drawFloorCeiling(t_game *game)
{
	int x;
	int y;
	int color1;
	int color2;

	color1 = create_rgb(game->floor.red, game->floor.green, game->floor.blue);
	color2 = create_rgb(game->ceiling.red, game->ceiling.green, game->ceiling.blue);

	x = 0;
	y = 0;
	/*ceiling*/
	while (y < game->window_y / 2)
	{
		while (x < game->window_x)
		{
			my_mlx_pixel_put(&(game->img), x, y, color2);
			x++;
		}
		x = 0;
		y++;
	}
	/*floor*/
	while (y <= game->window_y)
	{
		while (x <= game->window_x)
		{
			my_mlx_pixel_put(&(game->img), x, y, color1);
			x++;
		}
		x = 0;
		y++;
	}
}