#include "../includes/game.h"

char    **copyMap(t_game *game)
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

void	findPlayerPosition(t_game *game, t_coord *playerPos)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	(void)playerPos;
	while (i < game->mapCharHeight)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' || game->map[i][j] == 'E' || game->map[i][j] == 'A' )
			{
				game->playerPos->x = i;
				game->playerPos->y = j;
				dprintf(1,"player position  x = %d\n", game->playerPos->x);
				dprintf(1,"player position  y = %d\n", game->playerPos->y);
				
				game->posX = i + 0.5; //reste a verifier pourquoi loooool
				game->posY = j + 0.5;
				dprintf(1,"player position  x = %f\n", game->posX);
				dprintf(1,"player position  y = %f\n", game->posY);
				
			}
			j++;
		}
		i++;
	}
	game->playerPosDelta->x = cos(game->playerAngle) * 3;
    game->playerPosDelta->y = sin(game->playerAngle) * 3;
}

void	floodFill(char **map_copy, int x, int y)
{
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'X' || map_copy[y][x] == ' ') // add if other elements to avoid floodfilling
		return ;
	map_copy[y][x] = 'X';
	floodFill (map_copy, (x + 1), y);
	floodFill (map_copy, (x - 1), y);
	floodFill (map_copy, x, (y - 1));
	floodFill (map_copy, x, (y + 1));
}

void	postFloodFillCheck(char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == '1' || map_copy[i][j] == 'X' || map_copy[i][j] == ' ' || map_copy[i][j] == '\n')
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

void    floodFillCheck(t_game *game)
{
    char **copy;
	// t_coord playerPos;
    
    copy = copyMap(game);
	// coordInit(game->playerPos);
	print_char_table(game->map);
	findPlayerPosition(game, game->playerPos);
	printf("\nPlayer Pos X: %d, Y: %d\n", game->playerPos->x, game->playerPos->y);
	print_char_table(copy);
	floodFill(copy, game->playerPos->x, game->playerPos->y);
    print_char_table(copy);
	postFloodFillCheck(copy);
	freeCharArray(&copy);
}
