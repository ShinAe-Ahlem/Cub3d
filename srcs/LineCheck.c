/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LineCheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:01:40 by anouri            #+#    #+#             */
/*   Updated: 2024/03/25 11:02:17 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

bool	is_direction_line(char *line)
{
	if (!ft_strncmp("NO ", line, 3))
		return (true);
	else if (!ft_strncmp("SO ", line, 3))
		return (true);
	else if (!ft_strncmp("WE ", line, 3))
		return (true);
	else if (!ft_strncmp("EA ", line, 3))
		return (true);
	return (false);
}

bool	is_floor_ceilnig_line(char *line)
{
	if (!ft_strncmp("F ", line, 2))
		return (true);
	if (!ft_strncmp("C ", line, 2))
		return (true);
	return (false);
}

bool	is_map(t_game *game, char *line)
{
	char	*charset;

	(void)game;
	charset = NULL;
	charset = ft_strdup("01NSEW ");
	if (charset_finder(charset, line))
	{
		free (charset);
		return (true);
	}
	free (charset);
	return (false);
}
