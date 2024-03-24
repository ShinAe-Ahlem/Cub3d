/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:43:55 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 15:47:24 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	perform_dda_while(t_game *game, int *hit)
{
	while (*hit == 0)
	{
		if (game->sideDistX < game->sideDistY)
		{
			game->sideDistX += game->deltaDistX;
			game->mapX += game->stepX;
			if (game->stepX > 0)
				game->dir = 0;
			else
				game->dir = 2;
			game->side = 0;
		}
		else
		{
			game->sideDistY += game->deltaDistY;
			game->mapY += game->stepY;
			if (game->stepY > 0)
				game->dir = 3;
			else
				game->dir = 1;
			game->side = 1;
		}
		if (game->map[game->mapX][game->mapY] == '1')
			*hit = 1;
	}
}

void	perform_dda(t_game *game)
{
	int	hit;

	hit = 0;
	perform_dda_while(game, &hit);
	if (game->side == 0)
		game->perpWallDist = (game->sideDistX - game->deltaDistX);
	else
		game->perpWallDist = (game->sideDistY - game->deltaDistY);
}
