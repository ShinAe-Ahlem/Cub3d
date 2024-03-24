/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:34:37 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 14:36:25 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	fc_init(t_game *game)
{
	game->floor.red = 0;
	game->floor.green = 0;
	game->floor.blue = 0;
	game->ceiling.red = 0;
	game->ceiling.green = 0;
	game->ceiling.blue = 0;
}

void	map_info_init(t_game *game)
{
	game->mapfile = NULL;
	game->mapLL = NULL;
	game->map = NULL;
	game->mapCharHeight = 0;
	game->max_map_width = 0;
	game->playerPos = NULL;
	game->playerPosDelta = NULL;
	game->playerAngle = 0;
}

void	init_game_param(t_game *game)
{
	game->game_name = "Alhem and Shin Ae's World <3";
	game->fd = 0;
	game->pos = 0;
	game->x = 0;
	game->y = 0;
	game->mlx_ptr = NULL;
	game->tex = NULL;
	game->map = NULL;
	game->mapfile = NULL;
	game->texFiles = NULL;
	game->texLines = NULL;
	fc_init(game);
	map_info_init(game);
}
