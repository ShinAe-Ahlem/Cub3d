
#include "../includes/game.h"

/*square cubes!

the ray distance is converted to vertical lines that will make the walls

1- use triangles on the horizental grid line =>save distance
2- use triangles on the vertical grid lines => save distance

3- compare both and the one that hits closer will be used as the vertical line's strip

*/

/**/

void	drawPlayer(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (!game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		perror("window");
		exit(1);
	}
	ft_putstr_fd("in draw player\n", 1);
    drawRectangle(game, (TILE * game->playerPos->x), (TILE * game->playerPos->y), 20, 20, RED_PIXEL);
	// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->grp->ennemi_one,
	// 	(TILE * game->playerPos->x), (TILE * game->playerPos->y));
    printf("game->playerPos->x : %d\n", game->playerPos->x);
    printf("game->playerPos->y : %d\n", game->playerPos->y);
	drawLine(game, game->playerPos->x * TILE, game->playerPos->y  * TILE, (game->playerPos->x
		+ game->playerPosDelta->x) * TILE, (game->playerPos->y + game->playerPosDelta->y) * TILE, SHINAECOLOR);
    drawRays3D(game);
	// my_mlx_pixel_put(&(game->img), (int)game->playerPos->x + TILE,
		// (int)game->playerPos->y + TILE, create_rgb(255, 255, 255);
}

int	move(int keysym, t_game *game)
{
	if (keysym == XK_a)
	{
		game->playerAngle -= 0.1;
		if (game->playerAngle < 0)
		{
			game->playerAngle += 2 * PI;
		}
		game->playerPosDelta->x = cos(game->playerAngle) * 3;
		game->playerPosDelta->y = sin(game->playerAngle) * 3;
		// if (game->playerPos->x > 0)
		//     game->playerPos->x -= 1;
	}
	if (keysym == XK_d)
	{
		game->playerAngle += 0.1;
		if (game->playerAngle > 2 * PI)
		{
			game->playerAngle -= 2 * PI;
		}
		game->playerPosDelta->x = cos(game->playerAngle) * 3;
		game->playerPosDelta->y = sin(game->playerAngle) * 3;
		// if (game->playerPos->x < game->window_x)
		//     game->playerPos->x += 1;
	}
	if (keysym == XK_w)
	{
		game->playerPos->x += game->playerPosDelta->x;
		game->playerPos->y += game->playerPosDelta->y;
		// if (game->playerPos->y > 0)
		//     game->playerPos->y -= 1;
	}
	if (keysym == XK_s)
	{
		game->playerPos->x -= game->playerPosDelta->x;
		game->playerPos->y -= game->playerPosDelta->y;
		// if (game->playerPos->y < game->window_y)
		//     game->playerPos->y += 1;
	}
	return (0);
}
