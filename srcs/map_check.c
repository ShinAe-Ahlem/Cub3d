#include "../includes/game.h"

static void	EpurArray(t_game *game)
{
	int		i;
	size_t	lastOnePos;
	char	**new;

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
		lastOnePos = ft_strlen(game->map[i]);
		if (game->map[i][lastOnePos - 1] == '\n')
			lastOnePos--;
		while (game->map[i][lastOnePos] == ' '
			|| game->map[i][lastOnePos] == '\n')
			lastOnePos--;
		if (lastOnePos == ft_strlen(game->map[i]) - 2)
		{
			new[i] = ft_strdup(game->map[i]);
		}
		else
		{
			new[i] = ft_substr(game->map[i], 0, lastOnePos + 2);
			new[i][lastOnePos + 1] = '\n';
		}
		i++;
	}
	new[i] = NULL;
	free_table(game->map);
	game->map = new;
}

void	getMaxWidth(t_game *game)
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

void	MapCheckDivision(t_game *game)
{
	ll_toarray_converter(game);
	check_player_pos(game);
	zeroBlankContact(game);
	floodfill_check(game);
	EpurArray(game);
	getMaxWidth(game);
}