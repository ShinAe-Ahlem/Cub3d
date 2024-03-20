#include "../includes/game.h"

// static void	epur_array(t_game *game)
// {
// 	int		i;
// 	size_t	last_one_pos;
// 	char	**new;

// 	new = malloc((game->mapCharHeight + 1) * sizeof(char *));
// 	if (!new)
// 	{
// 		/*free this*/
// 		perror("malloc");
// 		exit(EXIT_FAILURE);
// 	}
// 	i = 0;
// 	while (game->map[i])
// 	{
// 		last_one_pos = ft_strlen(game->map[i]);
// 		if ((last_one_pos - 1 > 0 ) && game->map[i][last_one_pos - 1] == '\n')
// 			last_one_pos--;
// 		while (game->map[i][last_one_pos] == ' '
// 			|| game->map[i][last_one_pos] == '\n')
// 			last_one_pos--;
// 		if (last_one_pos == ft_strlen(game->map[i]) - 2)
// 		{
// 			new[i] = ft_strdup(game->map[i]);
// 		}
// 		else
// 		{
// 			new[i] = ft_substr(game->map[i], 0, last_one_pos + 2);
// 			new[i][last_one_pos + 1] = '\n';
// 		}
// 		i++;
// 	}
// 	new[i] = NULL;
// 	free_table(game->map);
// 	game->map = new;
// }


static char *copy_without_space(char *line_to_epur, int len)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char) * (len + 3)); //one for enter one for null
	if (!new)
	{
		ft_error(ERROR_MALLOC);
		//freethis
		exit(EXIT_FAILURE);
	}
	while (line_to_epur[i] && i < len )
	{
		new[i] = line_to_epur[j];
		i++;
		j++;
	}
	new[i] = '\n';
	i++;
	new[i] = '\0';
	return (new);
}

static void	epur_array(t_game *game)
{
	int		i;
	size_t	last_one_pos;
	char	**new;

	// dprintf(1, "STARTED - FROM EPUR ARRAY\n");
	// print_char_table(game->map);
	// dprintf(1, "ENDED - FROM EPUR ARRAY\n");
	new = malloc((game->mapCharHeight + 1) * sizeof(char *));
	if (!new)
	{
		/*free this*/
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (game->map[i])
	{
		last_one_pos = ft_strlen(game->map[i]);
		if ((last_one_pos - 1 > 0 ) && game->map[i][last_one_pos - 1] == '\n')
			last_one_pos--;
		while (game->map[i] && (last_one_pos - 1 > 0 )
			&& (game->map[i][last_one_pos] == ' '
			|| game->map[i][last_one_pos] == '\n'))
			last_one_pos--;
		if (last_one_pos == ft_strlen(game->map[i]) - 2)
		{
			new[i] = ft_strdup(game->map[i]);
		}
		else
		{
			new[i] = copy_without_space(game->map[i], last_one_pos + 1); // car ca commence par [0]
		}
		i++;
	}
	new[i] = NULL;
	free_table(game->map);
	game->map = new;
	// dprintf(1, "STARTED - FROM EPUR ARRAY 2\n");
	// print_char_table(game->map);
	// dprintf(1, "ENDED - FROM EPUR ARRAY 2\n");
}

void	get_max_width(t_game *game)
{
	int	i;

	i = 0;
	game->maxMapWidth = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) > (size_t)game->maxMapWidth)
			game->maxMapWidth = ft_strlen(game->map[i]);
		i++;
	}
}

void	map_check_division(t_game *game)
{
	ll_toarray_converter(game);
	check_player_pos(game);
	zero_blank_contact(game);
	floodfill_check(game);
	epur_array(game);
	get_max_width(game);
}
