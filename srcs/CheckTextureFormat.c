/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckTextureFormat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:24:56 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 15:39:27 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

bool	has_valid_extension(char *line)
{
	int	i;

	i = ft_strlen(line) - 2;
	if (line[i] == 'm' && line[i - 1] == 'p' && line[i - 2] == 'x' && line
		[i - 3] == '.')
		return (true);
	ft_error("Not a valid extension\n");
	return (false);
}

static bool	has_valid_prefix(char *texture, int *tex_num)
{
	if (!ft_strncmp("NO ", texture, 3))
	{
		*tex_num = 0;
		return (true);
	}
	else if (!ft_strncmp("SO ", texture, 3))
	{
		*tex_num = 2;
		return (true);
	}
	else if (!ft_strncmp("WE ", texture, 3))
	{
		*tex_num = 3;
		return (true);
	}
	else if (!ft_strncmp("EA ", texture, 3))
	{
		*tex_num = 1;
		return (true);
	}
	ft_error("not a valid prefix\n");
	return (false);
}

bool	are_valid_texture_formats(t_game *game)
{
	if (!has_valid_prefix(game->mapfile[game->pos], &game->tex_num))
		return (false);
	if (!has_valid_extension(game->mapfile[game->pos]))
		return (false);
	return (true);
}
