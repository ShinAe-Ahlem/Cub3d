
#include "../includes/game.h"

static void	ray_pos_and_dir(t_game *game, int x)
{
	game->cameraX = 2 * x / (double)game->window_x - 1;
	game->rayDirX = game->dirX + game->planeX * game->cameraX;
	game->rayDirY = game->dirY + game->planeY * game->cameraX;
	game->mapX = (int)game->posX;
	game->mapY = (int)game->posY;
	game->deltaDistX = fabs(1 / game->rayDirX);
	game->deltaDistY = fabs(1 / game->rayDirY);
}

static void	step_and_initial_sidedist(t_game *game)
{
	if (game->rayDirX < 0)
	{
		game->stepX = -1;
		game->sideDistX = (game->posX - game->mapX) * game->deltaDistX;
	}
	else
	{
		game->stepX = 1;
		game->sideDistX = (game->mapX + 1.0 - game->posX) * game->deltaDistX;
	}
	if (game->rayDirY < 0)
	{
		game->stepY = -1;
		game->sideDistY = (game->posY - game->mapY) * game->deltaDistY;
	}
	else
	{
		game->stepY = 1;
		game->sideDistY = (game->mapY + 1.0 - game->posY) * game->deltaDistY;
	}
}

static void	perform_dda(t_game *game)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (game->sideDistX < game->sideDistY)
		{
			game->sideDistX += game->deltaDistX;
			game->mapX += game->stepX;
			if (game->stepX > 0)
				game->dir = 0; // north
			else
				game->dir = 2; //south
			game->side = 0;
		}
		else
		{
			game->sideDistY += game->deltaDistY;
			game->mapY += game->stepY;
			if (game->stepY > 0)
				game->dir = 3; //west
			else
				game->dir = 1; // east
			game->side = 1;
		}
		if (game->map[game->mapX][game->mapY] == '1')
			hit = 1;
	}
	if (game->side == 0)
		game->perpWallDist = (game->sideDistX - game->deltaDistX);
	else
		game->perpWallDist = (game->sideDistY - game->deltaDistY);
}

static void	calculate_wall_height(t_game *game)
{
	game->lineHeight = (int)(game->window_y / game->perpWallDist);
	game->drawStart = -game->lineHeight / 2 + game->window_y / 2;
	if (game->drawStart < 0)
		game->drawStart = 0;
	game->drawEnd = game->lineHeight / 2 + game->window_y / 2;
	if (game->drawEnd >= game->window_y)
		game->drawEnd = game->window_y - 1;
}

static void	texturing_calculation(t_game *game)
{
	if (game->side == 0)
		game->wallX = game->posY + game->perpWallDist * game->rayDirY;
	else
		game->wallX = game->posX + game->perpWallDist * game->rayDirX;
	game->wallX -= floor((game->wallX));
	game->texX = (int)(game->wallX * texWidth);
	if (game->side == 0 && game->rayDirX > 0)
		game->texX = texWidth - game->texX - 1;
	if (game->side == 1 && game->rayDirY < 0)
		game->texX = texWidth - game->texX - 1;
	game->step = 1.0 * texHeight / game->lineHeight;
	game->texPos = (game->drawStart - game->window_y / 2 + game->lineHeight / 2)
		* game->step;
}

int	render_next_frame(t_game *game)
{
	int x;

	x = 0;
	init_image(game);
	while (x < game->window_x)
	{
		ray_pos_and_dir(game, x);
		step_and_initial_sidedist(game);
		perform_dda(game);
		calculate_wall_height(game);
		texturing_calculation(game);
		render(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, 0,
			0);
	mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	return (1); //presonaly I prefer 0 but I guess this is a loop_hook thing
}