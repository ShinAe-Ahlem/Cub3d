#include "../includes/game.h"

// export_tectures() : checked texture status stored in :
// NO - 0, EA - 1, SO_ - 2, WE - 3

void	export_textures_strdup(t_game *game, bool *check_table, int *i)
{
	if (!ft_strncmp("NO ", game->mapfile[*i], 3) && !check_table[0])
	{
		game->texLines[0] = ft_strdup(game->mapfile[*i]);
		check_table[0] = true;
	}
	else if (!ft_strncmp("EA ", game->mapfile[*i], 3) && !check_table[1])
	{
		game->texLines[1] = ft_strdup(game->mapfile[*i]);
		check_table[1] = true;
	}
	else if (!ft_strncmp("SO ", game->mapfile[*i], 3) && !check_table[2])
	{
		game->texLines[2] = ft_strdup(game->mapfile[*i]);
		check_table[2] = true;
	}
	else if (!ft_strncmp("WE ", game->mapfile[*i], 3) && !check_table[3])
	{
		game->texLines[3] = ft_strdup(game->mapfile[*i]);
		check_table[3] = true;
	}
}

void	export_textures(t_game *game)
{
	int		i;
	int		j;
	bool	check_table[5];

	i = game->pos;
	j = 0;
	ft_memset(check_table, 0, 5);
	game->texLines = malloc(5 * sizeof(char *));
	if (!game->texLines)
	{
		ft_perror(ERROR_MALLOC);
		free_all(game);
		exit(EXIT_FAILURE);
	}
	while (j < 4)
		game->texLines[j++] = NULL;
	while (i < game->pos + 4)
	{
		export_textures_strdup(game, check_table, &i);
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

	texture_files_exist_init(&i, &j, &fd, &filename);
	game->texFiles = ft_calloc(sizeof(char *), 5);
	while (j < 4)
	{
		texlines_null_check(game, &j);
		i = 3;
		while (game->texLines[j][i] == ' ')
			i++;
		filename = ft_substr(game->texLines[j], i, ft_strlen(game->texLines[j])
				- (i + 1));
		fd = open(filename, O_RDONLY);
		fd_error_check(fd, &filename, game);
		file_is_directory_check(&filename, &file_stat, game, fd);
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
	if (!are_valid_texture_formats(game))
	{
		free_part(game);
		exit(EXIT_FAILURE);
	}
	export_textures(game);
	texture_files_exist(game);
	game->pos += 3;
}
