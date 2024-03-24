/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:57:21 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 16:58:38 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	check_map_elements(t_game *game)
{
	handle_fc_dir(game);
	while (game->mapfile[game->pos] && is_empty_line(game->mapfile[game->pos]))
		game->pos++;
	if (!game->mapfile[game->pos])
	{
		ft_error(NOT_IN_ORDER);
		free_part(game);
		exit(EXIT_FAILURE);
	}
	while (game->mapfile[game->pos])
	{
		if (!is_map(game, game->mapfile[game->pos]))
		{
			ft_perror(ERROR_NO_MATCH_CHAR);
			free_part(game);
			exit(EXIT_FAILURE);
		}
		handle_map(game);
		if (game->mapfile[game->pos])
			game->pos++;
	}
	map_check_division(game);
}
