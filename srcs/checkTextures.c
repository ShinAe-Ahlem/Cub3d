/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkTextures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:25:32 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 15:43:27 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	export_texture_strdup(t_game *game)
{
	if (!game->texLines[game->tex_num])
		game->texLines[game->tex_num] = ft_strdup(game->mapfile[game->pos]);
	else
	{
		ft_error("texture already exists");
		free_part(game);
		exit(EXIT_FAILURE);
	}
}

void	export_textures(t_game *game)
{
	int	j;

	j = 0;
	if (!game->texLines)
	{
		game->texLines = malloc(5 * sizeof(char *));
		if (!game->texLines)
		{
			ft_perror(ERROR_MALLOC);
			free_all(game);
			exit(EXIT_FAILURE);
		}
		while (j < 4)
			game->texLines[j++] = NULL;
	}
	export_texture_strdup(game);
	game->texLines[4] = NULL;
}

void	texture_files_exist(t_game *game)
{
	int			fd;
	char		*filename;
	struct stat	file_stat;
	int			i;

	if (!game->texFiles)
	{
		game->texFiles = ft_calloc(sizeof(char *), 5);
	}
	i = 3;
	while (game->texLines[game->tex_num][i] == ' ')
		i++;
	filename = ft_substr(game->texLines[game->tex_num], i,
			ft_strlen(game->texLines[game->tex_num]) - (i + 1));
	fd = open(filename, O_RDONLY);
	fd_error_check(fd, &filename, game);
	file_is_directory_check(&filename, &file_stat, game, fd);
	game->texFiles[game->tex_num] = ft_strdup(filename);
	free(filename);
	filename = NULL;
	close(fd);
}

void	check_export_textures(t_game *game)
{
	if (!are_valid_texture_formats(game))
	{
		free_part(game);
		exit(EXIT_FAILURE);
	}
	export_textures(game);
	texture_files_exist(game);
	check_textures_dimensions(game);
}
