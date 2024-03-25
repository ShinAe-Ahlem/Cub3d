/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfillcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:28:24 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/25 11:47:01 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)malloc((game->map_char_height + 1) * sizeof(char *));
	if (copy == NULL)
		return (NULL);
	while (i < game->map_char_height)
	{
		copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	copy[game->map_char_height] = NULL;
	return (copy);
}

void	floodfill(char **map_copy, int x, int y)
{
	if (map_copy[y] && (map_copy[y][x] == '1' || map_copy[y][x] == 'X'
			|| map_copy[y][x] == ' '))
		return ;
	if (map_copy[y])
	{
		map_copy[y][x] = 'X';
		floodfill(map_copy, (x + 1), y);
		floodfill(map_copy, (x - 1), y);
		floodfill(map_copy, x, (y - 1));
		floodfill(map_copy, x, (y + 1));
	}
}

static int	post_floodfill_check(char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == '1' || map_copy[i][j] == 'X'
				|| map_copy[i][j] == ' ' || map_copy[i][j] == '\n')
				j++;
			else
			{
				ft_perror(ERROR_FF_FAILED);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	floodfill_check(t_game *game)
{
	char	**copy;

	copy = copy_map(game);
	find_player_position(game, game->player_pos);
	floodfill(copy, game->player_pos->x, game->player_pos->y);
	if (post_floodfill_check(copy))
	{
		free_table(copy);
		free_part(game);
		exit(EXIT_FAILURE);
	}
	free_char_array(&copy);
}
