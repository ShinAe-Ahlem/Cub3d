/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:04:13 by anouri            #+#    #+#             */
/*   Updated: 2024/01/31 10:22:11 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

char	**ft_read_map(char *filename)
{
	int		fd;
	char	*line;
	char	**new;
	int		nb_lines;
	int		j;

	char **map_lines; /*soit on fixe une taille maxe soit allocation dynamique*/
	map_lines = NULL;
	map_lines = malloc(1 * sizeof(char *));
	map_lines[0] = NULL;
	new = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		free(map_lines);
		exit(EXIT_FAILURE);
	}
	nb_lines = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!map_lines[0])
		{
			map_lines = malloc(2 * sizeof(char *));
			if (!map_lines)
				ft_error("malloc");
			map_lines[0] = ft_strdup(line);
			map_lines[1] = NULL;
			free(line);
			nb_lines = 1;
		}
		else
		{
			nb_lines++;
			new = malloc((nb_lines + 1) * sizeof(char *));
			if (!new)
				ft_error("malloc");
			j = 0;
			while (j < nb_lines - 1)
			{
				new[j] = ft_strdup(map_lines[j]);
				j++;
			}
			new[j] = ft_strdup(line);
			free(line);
			new[j + 1] = NULL;
			j = 0;
			while (j < nb_lines - 1)
			{
				free(map_lines[j]);
				j++;
			}
			free(map_lines);
			map_lines = new;
		}
	}
	close(fd);
	return (map_lines);
}


// int	main(int ac, char **av, char **env)
// {
// 	// t_game	game;

// 	// 1) init
// 	// 2) parsing (argument check, lecture cartte, map validity check)
// 	// 3) free / destroy

// 	// check_arg(ac, av);
// 	// check_env(env);
// 	(void)ac;
// 	(void)env;
// 	// ft_create_window(&game);
// 	char **map_lines = ft_read_map(av[1]);
// 	if (!map_lines)
// 		ft_error("invalid map");
// 	print_table(map_lines);
// 	ft_putstr_fd("yahooooooooo\n", 1);
// 	/* we will exit the loop if there's no window left, and execute this code */
// }

