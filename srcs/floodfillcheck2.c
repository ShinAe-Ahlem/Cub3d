/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfillcheck2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:32:58 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 17:42:43 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	set_player_pos(t_game *game, int *i, int *j)
{
	while (*i < game->map_char_height)
	{
		*j = 0;
		while (game->map[*i][*j])
		{
			if (game->map[*i][*j] == 'N' || game->map[*i][*j] == 'S'
				|| game->map[*i][*j] == 'E' || game->map[*i][*j] == 'W')
			{
				game->player_pos->x = *j;
				game->player_pos->y = *i;
				game->pos_x = *i + 0.5;
				game->pos_y = *j + 0.5;
			}
			(*j)++;
		}
		(*i)++;
	}
}

void	find_player_position(t_game *game, t_coord *player_pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)player_pos;
	game->player_pos = (t_coord *)malloc(sizeof(t_coord));
	if (game->player_pos == NULL)
	{
		ft_perror(ERROR_MALLOC);
		exit(EXIT_FAILURE);
	}
	game->player_pos->x = 0;
	game->player_pos->y = 0;
	set_player_pos(game, &i, &j);
	game->player_pos_delta = (t_coord *)malloc(sizeof(t_coord));
	if (game->player_pos_delta == NULL)
	{
		ft_perror(ERROR_MALLOC);
		exit(EXIT_FAILURE);
	}
	game->player_pos_delta->x = 0;
	game->player_pos_delta->y = 0;
	game->player_pos_delta->x = cos(game->player_angle) * 3;
	game->player_pos_delta->y = sin(game->player_angle) * 3;
}
