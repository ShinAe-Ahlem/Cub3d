/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeroBlankContact.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:54:42 by shikwon           #+#    #+#             */
/*   Updated: 2024/03/24 15:54:43 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	zero_this_line(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->map[i][j])
	{
		if (game->map[i][j] == '0')
		{
			ft_perror(ERROR_MAP_UNCLOSED);
			free_part(game);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	zero_side_blank(t_game *game, char *line)
{
	int		len;
	char	*temp;

	temp = ft_strtrim(line, " \n");
	len = ft_strlen(temp) - 1;
	if (len > 0 && (temp[len] == '0' || temp[0] == '0'))
	{
		ft_perror(ERROR_MAP_UNCLOSED);
		free(temp);
		free_part(game);
		exit(EXIT_FAILURE);
	}
	free(temp);
}

static int	space_next_to_char(t_game *game, int y, int x)
{
	int	len;

	len = ft_strlen(game->map[y]);
	if (y >= game->mapCharHeight || x >= len - 1)
		return (2);
	if (ft_isspace(game->map[y][x]) || !game->map[y][x])
		return (1);
	else
		return (0);
}

void	zero_exposed(t_game *game, char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == '0')
		{
			if (space_next_to_char(game, i - 1, j) || space_next_to_char(game, i
					+ 1, j) || space_next_to_char(game, i, j - 1)
				|| space_next_to_char(game, i, j + 1))
			{
				ft_perror(ERROR_MAP_UNCLOSED);
				free_part(game);
				exit(EXIT_FAILURE);
			}
		}
		j++;
	}
}

void	zero_blank_contact(t_game *game)
{
	int	i;

	i = 0;
	zero_this_line(game, 0);
	while (game->map[i])
	{
		zero_side_blank(game, game->map[i]);
		zero_exposed(game, game->map, i);
		i++;
	}
	i -= 1;
	zero_this_line(game, i);
}
