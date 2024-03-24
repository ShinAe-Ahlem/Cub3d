/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:43:55 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 17:41:22 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	perform_dda_while(t_game *game, int *hit)
{
	while (*hit == 0)
	{
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x += game->delta_dist_x;
			game->map_x += game->step_x;
			if (game->step_x > 0)
				game->dir = 0;
			else
				game->dir = 2;
			game->side = 0;
		}
		else
		{
			game->side_dist_y += game->delta_dist_y;
			game->map_y += game->step_y;
			if (game->step_y > 0)
				game->dir = 3;
			else
				game->dir = 1;
			game->side = 1;
		}
		if (game->map[game->map_x][game->map_y] == '1')
			*hit = 1;
	}
}

void	perform_dda(t_game *game)
{
	int	hit;

	hit = 0;
	perform_dda_while(game, &hit);
	if (game->side == 0)
		game->perp_wall_dist = (game->side_dist_x - game->delta_dist_x);
	else
		game->perp_wall_dist = (game->side_dist_y - game->delta_dist_y);
}
