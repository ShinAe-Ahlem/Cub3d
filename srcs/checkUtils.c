/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkUtils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:44:36 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 15:50:37 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

/*check ft_isspace in libft => tried and it didn't work! try again!*/

static void	error_msg(char *str, int exit_status)
{
	ft_error(str);
	exit(exit_status);
}

bool	is_empty_line(char *line)
{
	if (line == NULL)
		return (true);
	while (*line != '\0')
	{
		if (*line != ' ' || *line != '\n' || *line != '\t')
			return (false);
		line++;
	}
	return (true);
}

void	check_has_spaces(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (game->map[i])
	{
		if (!game->map[i + 1])
			return ;
		j = 0;
		while (game->map[i][j])
		{
			if (ft_isspace(game->map[i][j]))
			{
				while (ft_isspace(game->map[i][j]))
					j++;
				if (game->map[i][j] != '\n')
					error_msg("found empty line\n", EXIT_FAILURE);
			}
			else
				j++;
		}
		i++;
	}
}
