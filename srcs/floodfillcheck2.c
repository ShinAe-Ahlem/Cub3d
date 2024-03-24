/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfillcheck2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:32:58 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 15:33:15 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	set_player_pos(t_game *game, int *i, int *j)
{
	while (*i < game->mapCharHeight)
	{
		*j = 0;
		while (game->map[*i][*j])
		{
			if (game->map[*i][*j] == 'N' || game->map[*i][*j] == 'S'
				|| game->map[*i][*j] == 'E' || game->map[*i][*j] == 'W')
			{
				game->playerPos->x = *j;
				game->playerPos->y = *i;
				game->posX = *i + 0.5;
				game->posY = *j + 0.5;
			}
			(*j)++;
		}
		(*i)++;
	}
}

void	find_player_position(t_game *game, t_coord *playerPos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)playerPos;
	game->playerPos = (t_coord *)malloc(sizeof(t_coord));
	if (game->playerPos == NULL)
	{
		ft_perror(ERROR_MALLOC);
		exit(EXIT_FAILURE);
	}
	game->playerPos->x = 0;
	game->playerPos->y = 0;
	set_player_pos(game, &i, &j);
	game->playerPosDelta = (t_coord *)malloc(sizeof(t_coord));
	if (game->playerPosDelta == NULL)
	{
		ft_perror(ERROR_MALLOC);
		exit(EXIT_FAILURE);
	}
	game->playerPosDelta->x = 0;
	game->playerPosDelta->y = 0;
	game->playerPosDelta->x = cos(game->playerAngle) * 3;
	game->playerPosDelta->y = sin(game->playerAngle) * 3;
}
