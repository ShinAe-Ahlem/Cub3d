/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapElements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:41:08 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 17:27:57 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	handle_fc(t_game *game, int *f, int *c_flag, int *f_flag)
{
	if (game->mapfile[game->pos]
		&& is_floor_ceilnig_line(game->mapfile[game->pos]))
	{
		check_floor_ceiling(game, c_flag, f_flag);
		(*f)++;
	}
}

void	handle_dir(t_game *game, int *f)
{
	if (game->mapfile[game->pos] && is_direction_line(game->mapfile[game->pos]))
	{
		check_export_textures(game);
		(*f)++;
	}
}

void	handle_fc_dir(t_game *game)
{
	int	f1;
	int	f2;
	int	f_flag;
	int	c_flag;

	game->pos = 0;
	f_flag = 0;
	c_flag = 0;
	f1 = 0;
	f2 = 0;
	game->map_ll = NULL;
	while (game->mapfile[game->pos])
	{
		if (f1 == 4 && f2 == 2)
			break ;
		while (game->mapfile[game->pos]
			&& is_empty_line(game->mapfile[game->pos]))
			game->pos++;
		handle_fc(game, &f2, &c_flag, &f_flag);
		handle_dir(game, &f1);
		game->pos++;
	}
}

void	handle_map(t_game *game)
{
	if (game->mapfile[game->pos] && is_map(game, game->mapfile[game->pos]))
	{
		check_is_last_element(game);
		export_map(game);
	}
}
