#include "../includes/game.h"

// export_tectures() : checked texture status stored in :
// NO - 0, EA - 1, SO_ - 2, WE - 3

// void	export_textures_strdup(t_game *game, bool *check_table, int *i)
// {
// 	if (!ft_strncmp("NO ", game->mapfile[*i], 3) && !check_table[0])
// 	{
// 		game->texLines[0] = ft_strdup(game->mapfile[*i]);
// 		check_table[0] = true;
// 	}
// 	else if (!ft_strncmp("EA ", game->mapfile[*i], 3) && !check_table[1])
// 	{
// 		game->texLines[1] = ft_strdup(game->mapfile[*i]);
// 		check_table[1] = true;
// 	}
// 	else if (!ft_strncmp("SO ", game->mapfile[*i], 3) && !check_table[2])
// 	{
// 		game->texLines[2] = ft_strdup(game->mapfile[*i]);
// 		check_table[2] = true;
// 	}
// 	else if (!ft_strncmp("WE ", game->mapfile[*i], 3) && !check_table[3])
// 	{
// 		game->texLines[3] = ft_strdup(game->mapfile[*i]);
// 		check_table[3] = true;
// 	}
// }


void export_texture_strdup(t_game *game)
{
	if (!game->texLines[game->tex_num])
		game->texLines[game->tex_num] = ft_strdup(game->mapfile[game->pos]);
	else
	{
		ft_error("texture already exists");
		exit(EXIT_FAILURE);
	}
}
void	export_textures(t_game *game)
{
	// int		i;
	int		j;
	// bool	check_table[5];

	// i = game->pos;
	j = 0;
	// ft_memset(check_table, 0, 5);
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
	// export_textures_strdup(game, check_table, &game->tex);
	export_texture_strdup(game);
	game->texLines[4] = NULL;
}

void	texture_files_exist(t_game *game)
{
	int			fd;
	char		*filename;
	struct stat	file_stat;
	int			i;
	// int			j;

	// texture_files_exist_init(&i, &j, &fd, &filename);
	if (!game->texFiles)
	{
		game->texFiles = ft_calloc(sizeof(char *), 5);
	}
	// texlines_null_check(game, &j);
	i = 3;
	while (game->texLines[game->tex_num][i] == ' ')
		i++;
	filename = ft_substr(game->texLines[game->tex_num], i, ft_strlen(game->texLines[game->tex_num])
			- (i + 1));
	fd = open(filename, O_RDONLY);
	fd_error_check(fd, &filename, game);
	file_is_directory_check(&filename, &file_stat, game, fd);
	game->texFiles[game->tex_num] = ft_strdup(filename);
	free(filename);
	filename = NULL;
	close(fd);
}


static bool is_valid_size(char *line)
{
	int i;

	i = 0;
	while(line[i] && line[i] != '"')
	{
		// dprintf(1, "line[%d] = %c\n",i, line[i]);
		i++;
	}
	i++;
	while(line[i] && line[i] == ' ')
		i++;
	if (line[i] == '6')
		i++;
	if(line[i] == '4')
		i++;
	else
		return(false);
	while(line[i] && line[i] == ' ')
		i++;
	if (line[i] == '6')
		i++;
	if(line[i] == '4')
		i++;
	else
		return(false);
	return(true);
}

static bool is_size_line(char *line)
{
	int i;

	i = 0;
	while(line[i] && line[i] != '"')
		i++;
	if (!line[i])
		return(false);
	i++;
	while(line[i] && line[i] != '"' && line[i] != ',')
	{
		if (line[i] != ' ' && !ft_isdigit(line[i]))
			return(false);
		i++;
	}
	return(true);
}

static char *get_size_line(char *file_name)
{
	char *line;
	int fd;
	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	while((line = get_next_line(fd)))
	{
		if (!is_size_line(line))
			free(line);
		else
			break;
	}
	close(fd);
	fd = -1;
	return(line);
}

static void check_textures_dimensions(t_game *game)
{
	char *line;

	int i;

	line = NULL;
	i = 0;

	while(game->texFiles[i])
	{
		line = get_size_line(game->texFiles[i]);
		if (!is_valid_size(line))
		{
			free(line);
			ft_error(INVALID_SIZE);
			exit(EXIT_FAILURE);
		}
		free(line);
		i++;

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
	check_textures_dimensions(game);
}
