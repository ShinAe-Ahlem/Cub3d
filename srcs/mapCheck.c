#include "../includes/game.h"

static char	*copy_without_space(char *line_to_epur, int len)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char) * (len + 3));
	if (!new)
	{
		ft_error(ERROR_MALLOC);
		exit(EXIT_FAILURE);
	}
	while (line_to_epur[i] && i < len)
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

static void	epur_array_malloc(t_game *game, char ***new)
{
	*new = malloc((game->mapCharHeight + 1) * sizeof(char *));
	if (!(*new))
	{
		perror(ERROR_MALLOC);
		exit(EXIT_FAILURE);
	}
}

static void	epur_array(t_game *game)
{
	int		i;
	size_t	last_one_pos;
	char	**new;

	i = 0;
	epur_array_malloc(game, &new);
	while (game->map[i])
	{
		last_one_pos = ft_strlen(game->map[i]);
		if ((last_one_pos - 1 > 0) && game->map[i][last_one_pos - 1] == '\n')
			last_one_pos--;
		while (game->map[i] && (last_one_pos - 1 > 0)
			&& (game->map[i][last_one_pos] == ' '
			|| game->map[i][last_one_pos] == '\n'))
			last_one_pos--;
		if (last_one_pos == ft_strlen(game->map[i]) - 2)
			new[i] = ft_strdup(game->map[i]);
		else
			new[i] = copy_without_space(game->map[i], last_one_pos + 1);
		i++;
	}
	new[i] = NULL;
	free_table(game->map);
	game->map = new;
}

void	get_max_width(t_game *game)
{
	int	i;

	i = 0;
	game->max_map_width = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) > (size_t)game->max_map_width)
			game->max_map_width = ft_strlen(game->map[i]);
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
