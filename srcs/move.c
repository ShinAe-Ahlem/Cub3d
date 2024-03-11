#include "../includes/game.h"

int	move(int keysym, t_game *game)
{
	double	olddirX;
	double	moveSpeed;
	double oldplaneX;
	double	rotatSpeed;

	rotatSpeed = 0.042;
	moveSpeed = 0.083;
	oldplaneX = game->planeX;
	olddirX = game->dirX;
	if (keysym == XK_Right)
	{
		game->dirX = game->dirX * cos(-rotatSpeed) - game->dirY * sin(-rotatSpeed);
		game->dirY = olddirX * sin(-rotatSpeed) + game->dirY * cos(-rotatSpeed);
		game->planeX = game->planeX * cos(-rotatSpeed) - game->planeY * sin(-rotatSpeed);
		game->planeY = oldplaneX * sin(-rotatSpeed) + game->planeY * cos(-rotatSpeed);
	}
	if (keysym == XK_Left)
	{
		game->dirX = game->dirX * cos(rotatSpeed) - game->dirY * sin(rotatSpeed);
		game->dirY = olddirX * sin(rotatSpeed) + game->dirY * cos(rotatSpeed);
		game->planeX = game->planeX * cos(rotatSpeed) - game->planeY * sin(rotatSpeed);
		game->planeY = oldplaneX * sin(rotatSpeed) + game->planeY * cos(rotatSpeed);
	}

	if (keysym == XK_a)
	{
		if (game->map[(int)((game->posX - game->dirY * moveSpeed - 0.000001))][(int)(game->posY)] != '1')
			game->posX -= game->dirY * moveSpeed - 0.000001;
		if (game->map[(int)(game->posX)]
			[((int)(game->posY + game->dirX * moveSpeed - 0.000001))] != '1')
			game->posY += game->dirX * moveSpeed - 0.000001;
	}
	if (keysym == XK_d)
	{
		if (game->map[(int)((game->posX + game->dirY * moveSpeed - 0.000001))]
			[(int)(game->posY)] != '1')
			game->posX += game->dirY * moveSpeed - 0.000001;
		if (game->map[(int)(game->posX)]
			[((int)(game->posY - game->dirX * moveSpeed - 0.000001))] != '1')
			game->posY -= game->dirX * moveSpeed - 0.000001;
	}
	if (keysym == XK_w)
	{
		if (game->map[(int)(game->posX + game->dirX * moveSpeed - 0.000001)][(int)(game->posY - 0.000001)] != '1')
			game->posX += game->dirX * moveSpeed;
		if (game->map[(int)(game->posX - 0.000001)][((int)(game->posY + game->dirY * moveSpeed - 0.000001))] != '1')
			game->posY += game->dirY * moveSpeed;
	}
	if (keysym == XK_s)
	{
		if (game->map[(int)((game->posX - game->dirX * moveSpeed - 0.000001))]
			[(int)(game->posY - 0.000001)] != '1')
			game->posX -= game->dirX * moveSpeed;
		if (game->map[(int)(game->posX - 0.000001)]
			[((int)(game->posY - game->dirY * moveSpeed - 0.000001))] != '1')
			game->posY -= game->dirY * moveSpeed;
	}
	return (0);
}
