/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkIsLastElement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:23:23 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 15:23:24 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	check_is_last_element(t_game *game)
{
	int	i;

	i = game->pos;
	while (game->mapfile[i])
	{
		if (game->mapfile[i] && is_empty_line(game->mapfile[i]))
		{
			while (game->mapfile[i] && !is_empty_line(game->mapfile[i]))
				i++;
			if (game->mapfile[i] && is_empty_line(game->mapfile[i]))
			{
				ft_error(ERROR_MAP_SPLITTED);
				free_part(game);
				exit(EXIT_FAILURE);
			}
		}
		if (game->mapfile[i])
			i++;
	}
}
