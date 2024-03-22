#include "../includes/game.h"

void	export_textures(t_game *game)
{
	int	i;
	int j;
	// We need a switch that prevents double strdup(meaning double malloc)
	bool checkTable[5];  // checked texture status stored in : NO - 0, EA - 1, SO_ - 2, WE - 3

	i = game->pos;
	j = 0;
	ft_memset(checkTable, 0, 5);
	game->texLines = malloc(5 * sizeof(char *));
	if (!game->texLines)
	{
		ft_perror(ERROR_MALLOC);
		free_all(game);
		exit(EXIT_FAILURE);
	}
	// Try to prervent problems below by initializing manually
	while (j < 4)
		game->texLines[j++] = NULL;
	while (i < game->pos + 4) // this condition causes errors, it also has to check if there is an error in texture loading part
	{
		if (!ft_strncmp("NO ", game->mapfile[i], 3) && !checkTable[0])
		{
			game->texLines[0] = ft_strdup(game->mapfile[i]);
			checkTable[0] = true;
		}
		else if (!ft_strncmp("EA ", game->mapfile[i], 3) && !checkTable[1])
		{
			game->texLines[1] = ft_strdup(game->mapfile[i]);
			checkTable[1] = true;
		}
		else if (!ft_strncmp("SO ", game->mapfile[i], 3) && !checkTable[2])
		{
			game->texLines[2] = ft_strdup(game->mapfile[i]);
			checkTable[2] = true;
		}
		else if (!ft_strncmp("WE ", game->mapfile[i], 3) && !checkTable[3])
		{
			game->texLines[3] = ft_strdup(game->mapfile[i]);
			checkTable[3]  = true;
		}
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
	fd = 0;
	filename = NULL;
	i = 0;
	game->texFiles = ft_calloc(sizeof(char *), 5);
	while (j < 4)
	{
		// Make sure that all the textures are imported allright
		if (game->texLines[j] == NULL)
		{
			ft_perror(ERROR_LOAD_DIR);
			free_part(game);
			exit(EXIT_FAILURE);
		}
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
	dprintf(1,"check export texture\n");
	if (!are_valid_texture_formats(game))
	{
		free_part(game);
		exit(EXIT_FAILURE);
	}
	export_textures(game);
	texture_files_exist(game);
	game->pos += 3;
	dprintf(1,"game->texfile = %s\n", game->texFiles[0]);
}
