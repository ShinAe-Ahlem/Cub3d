
#include "../includes/game.h"


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

static void	drawCeiling(t_game *game, int *y, int x)
{
	int	color2;

	color2 = create_rgb(game->ceiling.red, game->ceiling.green,
			game->ceiling.blue);
	while ((*y) < game->drawStart)
	{
		my_mlx_pixel_put(game->img, x, *y, color2);
		(*y)++;
	}
}

static void	drawFloor(t_game *game, int *y, int x)
{
	int	color1;

	color1 = create_rgb(game->floor.red, game->floor.green, game->floor.blue);
	while (*y < game->window_y - 1)
	{
		my_mlx_pixel_put(game->img, x, *y, color1);
		(*y)++;
	}
}

static void	drawWall(t_game *game, int *y, int x)
{
	int	color3;

	while ((*y) < game->drawEnd)
	{
		game->texY = (int)game->texPos & (texHeight - 1);
		game->texPos += game->step;
		color3 = game->texAddress[game->dir][texHeight * game->texY
			+ game->texX];
		if (game->side == 1)
			color3 = (color3 >> 1) & 8355711;
		my_mlx_pixel_put(game->img, x, *y, color3);
		(*y)++;
	}
}

void	render(t_game *game, int x)
{
	int	y;

	y = 0;
	drawCeiling(game, &y, x);
	drawWall(game, &y, x);
	y = game->drawEnd;
	drawFloor(game, &y, x);
}
