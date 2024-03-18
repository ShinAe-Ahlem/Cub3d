#include "../includes/game.h"

char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)malloc((game->mapCharHeight + 1) * sizeof(char *));
	if (copy == NULL)
		return (NULL);
	while (i < game->mapCharHeight)
	{
		copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	copy[game->mapCharHeight] = NULL;
	return (copy);
}

void	find_player_position(t_game *game, t_coord *playerPos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)playerPos;
	while (i < game->mapCharHeight)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'A')
			{
				game->playerPos->x = j;
				game->playerPos->y = i;
				
				game->posX = j + 0.5;
				game->posY = i + 0.5;
			}
			j++;
		}
		i++;
	}
	game->playerPosDelta->x = cos(game->playerAngle) * 3;
	game->playerPosDelta->y = sin(game->playerAngle) * 3;
}

void	floodfill(char **map_copy, int x, int y)
{
	if (map_copy[y] && (map_copy[y][x] == '1' || map_copy[y][x] == 'X'
			|| map_copy[y][x] == ' '))
	// add if other elements to avoid floodfilling
		return ;
	if (map_copy[y])
	{
		map_copy[y][x] = 'X';
		floodfill(map_copy, (x + 1), y);
		floodfill(map_copy, (x - 1), y);
		floodfill(map_copy, x, (y - 1));
		floodfill(map_copy, x, (y + 1));
	}
}

void	post_floodfill_check(char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	dprintf(1, "\nhere\n");
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == '1' || map_copy[i][j] == 'X'
				|| map_copy[i][j] == ' ' || map_copy[i][j] == '\n')
				j++;
			else
			{
				//freethis
				ft_perror(ERROR_FF_FAILED);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	//freethis
}

void	floodfill_check(t_game *game)
{
	char	**copy;

	copy = copy_map(game);
	find_player_position(game, game->playerPos);
	floodfill(copy, game->playerPos->x, game->playerPos->y);
	post_floodfill_check(copy);
	freeCharArray(&copy);
}
