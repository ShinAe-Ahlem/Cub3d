#include "../includes/game.h"

void	export_textures(t_game *game)
{
	int	i;

	i = game->pos;
	game->texLines = malloc(5 * sizeof(char *));
	if (!game->texLines)
	{
		free_all(game);
		exit(EXIT_FAILURE);
	}
	while (i < game->pos + 4)
	{
		if (!ft_strncmp("NO ", game->mapfile[i], 3))
			game->texLines[0] = ft_strdup(game->mapfile[i]);
		else if (!ft_strncmp("EA ", game->mapfile[i], 3))
			game->texLines[1] = ft_strdup(game->mapfile[i]);
		else if (!ft_strncmp("SO ", game->mapfile[i], 3))
			game->texLines[2] = ft_strdup(game->mapfile[i]);
		else if (!ft_strncmp("WE ", game->mapfile[i], 3))
			game->texLines[3] = ft_strdup(game->mapfile[i]);
		i++;
	}
	game->texLines[4] = NULL;
}

void	texture_files_exist(t_game *game)
{
	int			fd;
	char		*filename;
	struct stat	file_stat;
	int			i;
	int			j;

	j = 0;
	game->texFiles = ft_calloc(sizeof(char *), 5);
	while (j < 4)
	{
		i = 3;
		while (game->texLines[j][i] == ' ')
			i++;
		filename = ft_substr(game->texLines[j], i, ft_strlen(game->texLines[j])
				- (i + 1));
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			if (filename)
				free(filename);
			free_part(game);
			// free_all(game);
			exit(EXIT_FAILURE);
		}
		if (fstat(fd, &file_stat) == -1)
			ft_perror(ERROR_FILE_STATUS);
		if (S_ISDIR(file_stat.st_mode))
		{
			printf("filename : %s\n", filename);
			ft_error(ERROR_XPM_DIR);
			free_all(game);
			free(filename);
			close(fd);
			exit(EXIT_SUCCESS);
		}
		game->texFiles[j] = ft_strdup(filename);
		free(filename);
		filename = NULL;
		close(fd);
		j++;
	}
}

void	check_textures(t_game *game, int *count)
{
	while (game->mapfile[game->pos])
	{
		if (game->mapfile[game->pos][0] == '\n')
			break ;
		if (checkdirection(game->mapfile[game->pos]))
		{
			free_table(game->mapfile);
			exit(EXIT_FAILURE);
		}
		else
			(*count)++;
		(game->pos)++;
	}
}

void	check_export_textures(t_game *game)
{
	// while (game->mapfile[game->pos][0] == '\n')
	// 	game->pos++;

	if (!are_valid_texture_formats(game))
	{
		free_part(game);
		exit(EXIT_FAILURE);
	}
	export_textures(game);
	texture_files_exist(game);
	game->pos += 3;
	// while (game->mapfile[game->pos][0] == '\n')
	// 	game->pos++;
}
