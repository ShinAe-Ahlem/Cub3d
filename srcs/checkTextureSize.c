/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkTextureSize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:40:15 by anouri            #+#    #+#             */
/*   Updated: 2024/03/25 11:09:04 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static bool	is_valid_size(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '"')
		i++;
	i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '6')
		i++;
	if (line[i] == '4')
		i++;
	else
		return (false);
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '6')
		i++;
	if (line[i] == '4')
		i++;
	else
		return (false);
	return (true);
}

static bool	is_size_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '"')
		i++;
	if (!line[i])
		return (false);
	i++;
	while (line[i] && line[i] != '"' && line[i] != ',')
	{
		if (line[i] != ' ' && !ft_isdigit(line[i]))
			return (false);
		i++;
	}
	return (true);
}

static char	*get_size_line(char *file_name)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd, 0);
	while (line)
	{
		if (!is_size_line(line))
		{
			free(line);
			line = get_next_line(fd, 0);
		}
		else
			break ;
	}
	get_next_line(fd, 1);
	close(fd);
	fd = -1;
	return (line);
}

void	check_textures_dimensions(t_game *game)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (game->tex_files[i])
	{
		line = get_size_line(game->tex_files[i]);
		if (!is_valid_size(line))
		{
			free(line);
			ft_error(INVALID_SIZE);
			free_part(game);
			exit(EXIT_FAILURE);
		}
		free(line);
		i++;
	}
}
