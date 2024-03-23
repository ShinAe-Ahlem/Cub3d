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


static bool is_valid_size(char *line)
{
	int i;

	i = 0;
	dprintf(1, "*****************is valid line start********************\n\n");

	dprintf(1, "line in is valid = %s/\n", line);
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
	dprintf(1, "---+++++++++++++is size line start---+++++++++++++***\n\n");

	// dprintf(1, "line in is size line= %s\n", line);
	while(line[i] && line[i] != '"')
		i++;
	if (!line[i])
	{
		dprintf(1, "false :D\n");
		return(false);
	}
	i++;
	while(line[i] && line[i] != '"' && line[i] != ',')
	{
		if (line[i] != ' ' && !ft_isdigit(line[i]))
		{
			dprintf(1, "false :O\n");
			return(false);
		}
		i++;
	}
	{
		dprintf(1, "True :X\n");
		return(true);
	}
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
		// free_part(game);
		exit(EXIT_FAILURE);
	}
	// if (!line)
	// {
	// 	close(fd);
	// 	free(line);
	// 	// free_part(game);
	// 	ft_error("texture file empty");
	// 	exit(EXIT_FAILURE);
	// } 
	while((line = get_next_line(fd)))
	{
		if (!is_size_line(line))
		{
			free(line);
			// line = get_next_line(fd);
		}
		else
		{
			break;
		}
		// if (!line)
		// {
		// 	close(fd);
		// 	free(line);
		// 	// free_part(game);
		// 	ft_error("texture file empty");
		// 	exit(EXIT_FAILURE);
		// }

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
		
		dprintf(1, "\n\n\nchecking the following texture %s\n\n", game->texFiles[i]);

		line = get_size_line(game->texFiles[i]);
		dprintf(1, "\n\n line= %s\n", line);

		if (!is_valid_size(line))
		{
			free(line);
			ft_error(INVALID_SIZE);
			exit(EXIT_FAILURE);
		}
		else
			dprintf(1, "bon\n\n");
		free(line);
		i++;

	}
}

// void check_textures_dimensions(t_game *game) {
//     char *line;
//     int fd;
//     int i;

//     i = 0;
//     while (game->texFiles[i]) {
//         dprintf(1, "\n\n\nchecking the following texture %s\n", game->texFiles[i]);

//         fd = open(game->texFiles[i], O_RDONLY);
//         if (fd == -1) {
//             perror("open");
//             free_part(game);
//             exit(EXIT_FAILURE);
//         }
        
//         while ((line = get_next_line(fd))) {
//             if (is_size_line(line)) {
//                 if (!is_valid_size(line)) {
//                     close(fd);
//                     free(line);
//                     free_part(game);
//                     ft_error(INVALID_SIZE);
//                     exit(EXIT_FAILURE);
//                 }
//                 free(line);
//                 break; // Break out of the loop when valid size information is found
//             }
//             free(line);
//         }
//         close(fd); // Close the file descriptor after processing
//         i++;
//     }
// }


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
	game->pos += 3;
}
