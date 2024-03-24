/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfillcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:28:24 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 15:37:53 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)malloc((game->mapCharHeight + 1) * sizeof(char *));
	if (copy == NULL)
		return (NULL);
	while (i < game->mapCharHeight)
	{
		copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	copy[game->mapCharHeight] = NULL;
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
	dprintf(1, "\nhere\n");
	print_char_table(map_copy);
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
	find_player_position(game, game->playerPos);
	floodfill(copy, game->playerPos->x, game->playerPos->y);
	if (post_floodfill_check(copy))
	{
		free_table(copy);
		free_part(game);
		exit(EXIT_FAILURE);
	}
	free_char_array(&copy);
}
