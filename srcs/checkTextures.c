/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkTextures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:25:32 by anouri            #+#    #+#             */
/*   Updated: 2024/03/25 11:21:29 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	export_texture_strdup(t_game *game)
{
	if (!game->tex_lines[game->tex_num])
	{
		game->tex_lines[game->tex_num] = ft_strdup(game->mapfile[game->pos]);
	}
	else
	{
		ft_error("Texture already exists");
		free_part(game);
		exit(EXIT_FAILURE);
	}
}

void	export_textures(t_game *game)
{
	int	j;

	j = 0;
	if (!game->tex_lines)
	{
		game->tex_lines = ft_calloc(sizeof(char *), 5);
		if (!game->tex_lines)
		{
			ft_perror(ERROR_MALLOC);
			free_all(game);
			exit(EXIT_FAILURE);
		}
		while (j < 5)
			game->tex_lines[j++] = NULL;
	}
	export_texture_strdup(game);
}

void	texture_files_exist(t_game *game)
{
	int			fd;
	char		*filename;
	struct stat	file_stat;
	int			i;

	if (!game->tex_files)
	{
		game->tex_files = ft_calloc(sizeof(char *), 5);
	}
	i = 3;
	while (game->tex_lines[game->tex_num][i] == ' ')
		i++;
	filename = ft_substr(game->tex_lines[game->tex_num], i,
			ft_strlen(game->tex_lines[game->tex_num]) - (i + 1));
	fd = open(filename, O_RDONLY);
	dprintf(1, "filename = %s\n", filename);
	fd_error_check(fd, &filename, game);
	file_is_directory_check(&filename, &file_stat, game, fd);
	game->tex_files[game->tex_num] = ft_strdup(filename);
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
