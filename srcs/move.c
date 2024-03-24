/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:22:35 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 17:49:41 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	rot_right(int keysym, t_game *game, double olddir_x, double oldplane_x)
{
	double	rotat_speed;

	rotat_speed = 0.042;
	if (keysym == XK_Right)
	{
		game->dir_x = game->dir_x * cos(-rotat_speed) - game->dir_y
			* sin(-rotat_speed);
		game->dir_y = olddir_x * sin(-rotat_speed) + game->dir_y
			* cos(-rotat_speed);
		game->plane_x = game->plane_x * cos(-rotat_speed) - game->plane_y
			* sin(-rotat_speed);
		game->plane_y = oldplane_x * sin(-rotat_speed) + game->plane_y
			* cos(-rotat_speed);
	}
}

void	rot_left(int keysym, t_game *game, double olddir_x, double oldplane_x)
{
	double	rotat_speed;

	rotat_speed = 0.042;
	if (keysym == XK_Left)
	{
		game->dir_x = game->dir_x * cos(rotat_speed) - game->dir_y
			* sin(rotat_speed);
		game->dir_y = olddir_x * sin(rotat_speed) + game->dir_y
			* cos(rotat_speed);
		game->plane_x = game->plane_x * cos(rotat_speed) - game->plane_y
			* sin(rotat_speed);
		game->plane_y = oldplane_x * sin(rotat_speed) + game->plane_y
			* cos(rotat_speed);
	}
}

void	up_down(int keysym, t_game *game)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game->dir_x;
	oldplane_x = game->plane_x;
	rot_left(keysym, game, olddir_x, oldplane_x);
	rot_right(keysym, game, olddir_x, oldplane_x);
}

void	lef_right(int keysym, t_game *game, double move_speed)
{
	if (keysym == XK_a)
	{
		if (game->map[(int)((game->pos_x - game->dir_y * move_speed
					- 0.000001))][(int)(game->pos_y)] != '1')
			game->pos_x -= game->dir_y * move_speed - 0.000001;
		if (game->map[(int)(game->pos_x)]
						[((int)(game->pos_y + game->dir_x * move_speed
									- 0.000001))] != '1')
			game->pos_y += game->dir_x * move_speed - 0.000001;
	}
	if (keysym == XK_d)
	{
		if (game->map[(int)((game->pos_x + game->dir_y * move_speed
					- 0.000001))]
						[(int)(game->pos_y)] != '1')
			game->pos_x += game->dir_y * move_speed - 0.000001;
		if (game->map[(int)(game->pos_x)]
						[((int)(game->pos_y - game->dir_x * move_speed
									- 0.000001))] != '1')
			game->pos_y -= game->dir_x * move_speed - 0.000001;
	}
}

void	forward_backward(int keysym, t_game *game, double move_speed)
{
	if (keysym == XK_w)
	{
		if (game->map[(int)(game->pos_x + game->dir_x * move_speed
				- 0.000001)][(int)(game->pos_y - 0.000001)] != '1')
			game->pos_x += game->dir_x * move_speed;
		if (game->map[(int)(game->pos_x - 0.000001)][((int)(game->pos_y
					+ game->dir_y * move_speed - 0.000001))] != '1')
			game->pos_y += game->dir_y * move_speed;
	}
	if (keysym == XK_s)
	{
		if (game->map[(int)((game->pos_x - game->dir_x * move_speed
					- 0.000001))]
						[(int)(game->pos_y - 0.000001)] != '1')
			game->pos_x -= game->dir_x * move_speed;
		if (game->map[(int)(game->pos_x - 0.000001)]
						[((int)(game->pos_y - game->dir_y * move_speed
									- 0.000001))] != '1')
			game->pos_y -= game->dir_y * move_speed;
	}
}
