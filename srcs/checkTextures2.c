/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkTextures2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:43:38 by anouri            #+#    #+#             */
/*   Updated: 2024/03/24 18:27:24 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	file_is_directory_check(char **filename, struct stat *file_stat,
		t_game *game, int fd)
{
	if (fstat(fd, file_stat) == -1)
		ft_perror(ERROR_FILE_STATUS);
	if (S_ISDIR(file_stat->st_mode))
	{
		ft_error(ERROR_XPM_DIR);
		free_part(game);
		free(*filename);
		close(fd);
		exit(EXIT_SUCCESS);
	}
}

void	fd_error_check(int fd, char **filename, t_game *game)
{
	if (fd == -1)
	{
		perror("open");
		if (*filename)
			free(*filename);
		free_part(game);
		dprintf(1, "filename = %p\n", game->tex_files);
		exit(EXIT_FAILURE);
	}
}

void	texture_files_exist_init(int *i, int *j, int *fd, char **filename)
{
	*j = 0;
	*fd = 0;
	*filename = NULL;
	*i = 0;
}
