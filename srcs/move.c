/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:22:35 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 16:22:36 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	rot_right(int keysym, t_game *game, double olddir_x,
		double oldplane_x)
{
	double	rotat_speed;

	rotat_speed = 0.042;
	if (keysym == XK_Right)
	{
		game->dirX = game->dirX * cos(-rotat_speed) - game->dirY
			* sin(-rotat_speed);
		game->dirY = olddir_x * sin(-rotat_speed) + game->dirY
			* cos(-rotat_speed);
		game->planeX = game->planeX * cos(-rotat_speed) - game->planeY
			* sin(-rotat_speed);
		game->planeY = oldplane_x * sin(-rotat_speed) + game->planeY
			* cos(-rotat_speed);
	}
}

void	rot_left(int keysym, t_game *game, double olddir_x,
		double oldplane_x)
{
	double	rotat_speed;

	rotat_speed = 0.042;
	if (keysym == XK_Left)
	{
		game->dirX = game->dirX * cos(rotat_speed) - game->dirY
			* sin(rotat_speed);
		game->dirY = olddir_x * sin(rotat_speed) + game->dirY
			* cos(rotat_speed);
		game->planeX = game->planeX * cos(rotat_speed) - game->planeY
			* sin(rotat_speed);
		game->planeY = oldplane_x * sin(rotat_speed) + game->planeY
			* cos(rotat_speed);
	}
}

void	up_down(int keysym, t_game *game)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game->dirX;
	oldplane_x = game->planeX;
	rot_left(keysym, game, olddir_x, oldplane_x);
	rot_right(keysym, game, olddir_x, oldplane_x);
}

void	lef_right(int keysym, t_game *game, double move_speed)
{
	if (keysym == XK_a)
	{
		if (game->map[(int)((game->posX - game->dirY * move_speed
					- 0.000001))][(int)(game->posY)] != '1')
			game->posX -= game->dirY * move_speed - 0.000001;
		if (game->map[(int)(game->posX)]
						[((int)(game->posY + game->dirX * move_speed
									- 0.000001))] != '1')
			game->posY += game->dirX * move_speed - 0.000001;
	}
	if (keysym == XK_d)
	{
		if (game->map[(int)((game->posX + game->dirY * move_speed - 0.000001))]
						[(int)(game->posY)] != '1')
			game->posX += game->dirY * move_speed - 0.000001;
		if (game->map[(int)(game->posX)]
						[((int)(game->posY - game->dirX * move_speed
									- 0.000001))] != '1')
			game->posY -= game->dirX * move_speed - 0.000001;
	}
}

void	forward_backward(int keysym, t_game *game, double move_speed)
{
	if (keysym == XK_w)
	{
		if (game->map[(int)(game->posX + game->dirX * move_speed
				- 0.000001)][(int)(game->posY - 0.000001)] != '1')
			game->posX += game->dirX * move_speed;
		if (game->map[(int)(game->posX - 0.000001)][((int)(game->posY
					+ game->dirY * move_speed - 0.000001))] != '1')
			game->posY += game->dirY * move_speed;
	}
	if (keysym == XK_s)
	{
		if (game->map[(int)((game->posX - game->dirX * move_speed - 0.000001))]
						[(int)(game->posY - 0.000001)] != '1')
			game->posX -= game->dirX * move_speed;
		if (game->map[(int)(game->posX - 0.000001)]
						[((int)(game->posY - game->dirY * move_speed
									- 0.000001))] != '1')
			game->posY -= game->dirY * move_speed;
	}
}
