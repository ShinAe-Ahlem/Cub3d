#include "../includes/game.h"

static char	**save_first_line(char *line, int *nb_lines)
{
	char	**map_lines;

	map_lines = NULL;
	map_lines = malloc(2 * sizeof(char *));
	if (!map_lines)
	{
		ft_error("malloc");
		return (NULL);
	}
	map_lines[0] = ft_strdup(line);
	map_lines[1] = NULL;
	free(line);
	*nb_lines = 1;
	return (map_lines);
}

static char	**save_other_lines(char **map_lines, int *nb_lines, char *line)
{
	char	**new;
	int		j;

	(*nb_lines)++;
	new = malloc((*nb_lines + 1) * sizeof(char *));
	if (!new)
		ft_error("malloc");
	j = 0;
	while (j < *nb_lines - 1)
	{
		new[j] = ft_strdup(map_lines[j]);
		j++;
	}
	new[j] = ft_strdup(line);
	free(line);
	new[j + 1] = NULL;
	j = 0;
	while (j < *nb_lines - 1)
	{
		free(map_lines[j]);
		j++;
	}
	free(map_lines);
	map_lines = new;
	return (map_lines);
}

char	**ft_read_map(char *filename)
{
	int		fd;
	char	*line;
	int		nb_lines;
	char	**map_lines;

	map_lines = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
		// return(NULL);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			if (!map_lines)
				map_lines = save_first_line(line, &nb_lines);
			else
				map_lines = save_other_lines(map_lines, &nb_lines, line);
		}
		else
			break ;
	}
	close(fd);
	return (map_lines);
}

